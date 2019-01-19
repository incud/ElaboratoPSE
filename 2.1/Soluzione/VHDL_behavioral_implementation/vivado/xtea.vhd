library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.all;
use WORK.xtea_helper.ALL;

entity xtea is
    Port ( 
        clock          : in std_logic;
        reset          : in std_logic;
        -- input
        op1            : in data_word;
        op2            : in data_word;
        command        : in command_word;
        input_ready    : in std_logic;
        -- output
        result1        : out data_word;
        result2        : out data_word;
        input_received : out std_logic := '0';
        output_ready   : out std_logic := '0'
    );
end xtea;

architecture Behavioral of xtea is

    -- possibili stati nel quale si trova il mio
    -- componente. essendo interni li definisco qui
    type state is (swait, srouter, sconfigure, 
        senc0, senc1, senc2, senc3, senc4, senc5,
        sdec0, sdec1, sdec2, sdec3, sdec4, sdec5, serr
    );
    
    -- costanti per la criptazione e decriptazione
    constant DELTA            : data_word := X"9E37_79B9";
    constant INIT_SUM_ENCRYPT : data_word := X"0000_0000"; -- X"0000_0000_0000_0000";
    constant INIT_SUM_DECRYPT : data_word := X"C6EF_3720"; -- X"0000_0013_C6EF_3720"; -- 0x9e3779b9*32;
    
    -- segnale che risveglia gli altri processi
    signal resume : bit := '0';
    
    -- numero di iterazioni dei calcoli
    subtype iteration_range is integer range 0 to 32;
    constant ITERATION_NUMBER : iteration_range := 32;
    signal counter : iteration_range;
    
    -- variabili di mantenimento
    signal current_state    : state := swait;
    signal next_state       : state := swait;
    signal keys             : keys_word;
    signal stored_command   : command_word;
    signal stored_op1       : data_word;
    signal stored_op2       : data_word;
    signal sum, temp, acc   : data_word;
    signal v0, v1           : data_word;
    
    -- calculate ( ((v << 4) ^ (v >> 5)) + v ) + (sum + temp)
    function complex_op (v, sum, temp : data_word) return data_word is
        variable v_shl_4 : data_word;
        variable v_shr_5 : data_word;
    begin
        v_shl_4 := v(27 downto 0) & "0000";
        v_shr_5 := "00000" & v(31 downto 5);
        return ((v_shl_4 xor v_shr_5) + v) xor (sum + temp);
    end complex_op;

begin

    -- questo ptimo processo aggiorna lo stato corrente
    -- allo stato iniziale se siamo nel reset, oppure
    -- allo stato di next_state. Un segnale fantoccio resume
    -- viene utilizza per far partire gli altri processi dopo
    -- questo primo processo qua. Non posso usare current_state
    -- perchè a volte lo stato non cambia perchè è stato assegnato
    -- uguale a prima, e non viene generato l'evento
    clock_event: process(clock)
    begin
        if clock'event and clock = '1' then
            if reset = '1' then -- il segnale di reset è sincrono
                current_state <= swait;
            else
                current_state <= next_state;
            end if;
            -- avvio i processi per il calcolo
            resume <= not resume;
        end if;
    end process;
    
    -- processo che aggiorna i segnali di controllo
    fsm: process(resume)
    begin
        case current_state is
            when swait =>
                if reset = '1' then
                    stored_op1  <= X"0000_0000";
                    stored_op2  <= X"0000_0000";
                    stored_command <= "00";
                    next_state <= swait;
                else
                    if input_ready = '1' then
                        stored_op1 <= op1;
                        stored_op2 <= op2;
                        stored_command <= command;
                        next_state <= srouter;
                    else
                        next_state <= swait;
                    end if;
                end if;
            when srouter =>
                input_received <= '1';
                output_ready <= '0';
                case stored_command is
                    when CONFIGURE_KEYS_0_1 => next_state <= sconfigure;
                    when CONFIGURE_KEYS_2_3 => next_state <= sconfigure;
                    when RUN_ENCRYPT        => next_state <= senc0;
                    when RUN_DECRYPT        => next_state <= sdec0;
                    when others             => next_state <= serr;
                end case;
            when sconfigure =>
                case stored_command is
                    when CONFIGURE_KEYS_0_1 => 
                        keys(0) <= stored_op1;
                        keys(1) <= stored_op2;
                    when CONFIGURE_KEYS_2_3 => 
                        keys(2) <= stored_op1;
                        keys(3) <= stored_op2;
                    when others => 
                        null;
                end case;
                input_received <= '0';
                output_ready <= '1';
                next_state <= swait;
            when senc0 =>
                if counter = ITERATION_NUMBER then 
                    result1 <= v0;
                    result2 <= v1;
                    input_received <= '0';
                    output_ready <= '1';
                    next_state <= swait;
                else
                    next_state <= senc1;
                end if;
            when sdec0 =>
                if counter = ITERATION_NUMBER then 
                    result1 <= v0;
                    result2 <= v1;
                    input_received <= '0';
                    output_ready <= '1';
                    next_state <= swait;
                else
                    next_state <= sdec1;
                end if;
            when senc1 => next_state <= senc2;
            when senc2 => next_state <= senc3;
            when senc3 => next_state <= senc4;
            when senc4 => next_state <= senc5;
            when senc5 => next_state <= senc0;
            when sdec1 => next_state <= sdec2;
            when sdec2 => next_state <= sdec3;
            when sdec3 => next_state <= sdec4;
            when sdec4 => next_state <= sdec5;
            when sdec5 => next_state <= sdec0;
            when others => next_state <= serr;
        end case;
    end process;

    datapath: process(resume)
        variable index : integer range 3 downto 0;
    begin
        case current_state is
        when swait =>
            if reset = '1' then
                counter     <= 0;
                sum         <= X"0000_0000";
                temp        <= X"0000_0000";
                acc         <= X"0000_0000";
            end if;
        when srouter =>
            v0 <= stored_op1;
            v1 <= stored_op2;
            counter <= 0;
            case stored_command is
                when RUN_ENCRYPT        => sum <= INIT_SUM_ENCRYPT;
                when RUN_DECRYPT        => sum <= INIT_SUM_DECRYPT;
                when others             => null;
            end case;
        when sconfigure => 
            null;
        when senc0 | sdec3 =>
            index := to_integer(unsigned(sum(1 downto 0)));
            temp <= keys(index);
        when senc1 | sdec4 =>
            acc <= complex_op(v1, sum, temp);
        when senc2 =>
            v0 <= v0 + acc;
            sum <= sum + DELTA;
        when senc3 | sdec0 =>
            index := to_integer(unsigned(sum(12 downto 11)));
            temp <= keys(index);
        when senc4 | sdec1 =>
            acc <= complex_op(v0, sum, temp);
        when senc5 =>
            v1 <= v1 + acc;
            counter <= counter + 1;
        when sdec2 =>
            v1 <= v1 - acc;
            sum <= sum - DELTA;
        when sdec5 =>
            v0 <= v0 - acc;
            counter <= counter + 1;
        when others =>
            null;
        end case;
    end process;

end Behavioral;
