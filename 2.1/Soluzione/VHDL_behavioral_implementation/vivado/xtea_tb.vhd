library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;
use WORK.xtea_helper.ALL;

entity xtea_tb is
end;

architecture bench of xtea_tb is

    component xtea
        Port ( 
            clock          : in std_logic;
            reset          : in std_logic;
            op1            : in data_word;
            op2            : in data_word;
            command        : in command_word;
            input_ready    : in std_logic;
            result1        : out data_word;
            result2        : out data_word;
            input_received : out std_logic := '0';
            output_ready   : out std_logic := '0'
        );
    end component;
    
    signal clock: std_logic;
    signal reset: std_logic;
    signal op1: data_word;
    signal op2: data_word;
    signal command: command_word;
    signal input_ready: std_logic;
    signal result1: data_word;
    signal result2: data_word;
    signal input_received: std_logic := '0';
    signal output_ready: std_logic := '0' ;
    
    constant KEYS : keys_word := (X"AAAA0000", X"BBBB1111", X"CCCC2222", X"DDDD3333");
    constant MSG : message_word := (X"DEADBEEF", X"DEFEC8ED");
    
    constant clock_period: time := 1 ns;
    signal stop_the_clock: boolean;

begin

    uut: xtea port map ( 
        clock          => clock,
        reset          => reset,
        op1            => op1,
        op2            => op2,
        command        => command,
        input_ready    => input_ready,
        result1        => result1,
        result2        => result2,
        input_received => input_received,
        output_ready   => output_ready );

    stimulus: process
    begin
        -- reset
        reset <= '1';
        input_ready <= '0';
        wait until clock'event and clock = '1';
        reset <= '0';
        wait until clock'event and clock = '1';
    
        -- configurazione prima parte delle chiavi
        op1 <= KEYS(0);
        op2 <= KEYS(1);
        command <= CONFIGURE_KEYS_0_1;
        input_ready <= '1';
        wait until input_received'event and input_received = '1';
        input_ready <= '0';
        wait until output_ready'event and output_ready = '1';
        
        -- configurazione seconda parte delle chiavi
        op1 <= KEYS(2);
        op2 <= KEYS(3);
        command <= CONFIGURE_KEYS_2_3;
        input_ready <= '1';
        wait until input_received'event and input_received = '1';
        input_ready <= '0';
        wait until output_ready'event and output_ready = '1';
        
        -- configurazione dei messaggi (criptazione
        op1 <= MSG(0);
        op2 <= MSG(1);
        command <= RUN_ENCRYPT;
        input_ready <= '1';
        wait until input_received'event and input_received = '1';
        input_ready <= '0';
        wait until output_ready'event and output_ready = '1';
        
        -- configurazione dei messaggi (decriptazione)
        op1 <= result1;
        op2 <= result2;
        command <= RUN_DECRYPT;
        input_ready <= '1';
        wait until input_received'event and input_received = '1';
        input_ready <= '0';
        wait until output_ready'event and output_ready = '1';
        
        -- finalizzazione, aspetto qualche ciclo di clock 
        -- per vedere come si evolve il sistema senza stimoli
        wait until clock'event and clock = '1';
        wait until clock'event and clock = '1';
        wait until clock'event and clock = '1';
        stop_the_clock <= true;
        wait;
    end process;

    clocking: process
    begin
        while not stop_the_clock loop
            clock <= '0', '1' after clock_period / 2;
            wait for clock_period;
        end loop;
        wait;
    end process;

end;

