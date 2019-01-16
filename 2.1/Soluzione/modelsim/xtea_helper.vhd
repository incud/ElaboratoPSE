library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

package xtea_helper is

    subtype data_word    is std_logic_vector (31 downto 0);
    subtype command_word is std_logic_vector (1 downto 0);
    type keys_word       is array (3 downto 0) of data_word;
    type message_word    is array (1 downto 0) of data_word;
    
    constant CONFIGURE_KEYS_0_1 : command_word;
    constant CONFIGURE_KEYS_2_3 : command_word;
    constant RUN_ENCRYPT        : command_word;
    constant RUN_DECRYPT        : command_word;

end package;

package body xtea_helper is

    constant CONFIGURE_KEYS_0_1 : command_word := "00";
    constant CONFIGURE_KEYS_2_3 : command_word := "01";
    constant RUN_ENCRYPT        : command_word := "10";
    constant RUN_DECRYPT        : command_word := "11";

end package body;

