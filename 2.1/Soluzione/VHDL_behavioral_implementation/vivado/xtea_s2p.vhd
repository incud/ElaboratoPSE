library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;
use WORK.xtea_helper.ALL;

entity xtea_s2p is
    Port ( 
        clock          : in std_logic;
        reset          : in std_logic;
        op1            : in std_logic_vector(7 downto 0);
        op2            : in std_logic_vector(7 downto 0);
        command        : in command_word;
        input_ready    : in std_logic;
        result1        : out std_logic_vector(7 downto 0);
        result2        : out std_logic_vector(7 downto 0);
        input_received : out std_logic := '0';
        output_ready   : out std_logic := '0'
    );
end;

architecture bench of xtea_s2p is

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
    
    signal op1_full     : data_word;
    signal op2_full     : data_word;
    signal result1_full : data_word;
    signal result2_full : data_word;
    signal clock_slower : std_logic;

begin

    uut: xtea port map ( 
        clock          => clock_slower,
        reset          => reset,
        op1            => op1_full,
        op2            => op2_full,
        command        => command,
        input_ready    => input_ready,
        result1        => result1_full,
        result2        => result2_full,
        input_received => input_received,
        output_ready   => output_ready );

    adapter: process(clock)
        variable i : integer range 0 to 3;
    begin
        case i is
        when 0 =>
            clock_slower <= '0';
            i := 1;
            op1_full(31 downto 24) <= op1;
            op2_full(31 downto 24) <= op2;
            result1 <= result1_full(31 downto 24);
            result2 <= result2_full(31 downto 24);
        when 1 =>
            i := 2;
            op1_full(23 downto 16) <= op1;
            op2_full(23 downto 16) <= op2;
            result1 <= result1_full(23 downto 16);
            result2 <= result2_full(23 downto 16);
        when 2 =>
            i := 3;
            op1_full(15 downto 8) <= op1;
            op2_full(15 downto 8) <= op2;
            result1 <= result1_full(15 downto 8);
            result2 <= result2_full(15 downto 8);
        when 3 =>
            clock_slower <= '1';
            i := 0;
            op1_full(7 downto 0) <= op1;
            op2_full(7 downto 0) <= op2;
            result1 <= result1_full(7 downto 0);
            result2 <= result2_full(7 downto 0);
        when others => 
            i := 0;
            null;
        end case;
        
    end process;
    

end;
