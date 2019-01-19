-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2018.2.2
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity xtea_fsm is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    counter : IN STD_LOGIC_VECTOR (5 downto 0);
    dpValues_address0 : OUT STD_LOGIC_VECTOR (0 downto 0);
    dpValues_ce0 : OUT STD_LOGIC;
    dpValues_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    dpValues_address1 : OUT STD_LOGIC_VECTOR (0 downto 0);
    dpValues_ce1 : OUT STD_LOGIC;
    dpValues_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    keys_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    keys_ce0 : OUT STD_LOGIC;
    keys_we0 : OUT STD_LOGIC;
    keys_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    keys_address1 : OUT STD_LOGIC_VECTOR (1 downto 0);
    keys_ce1 : OUT STD_LOGIC;
    keys_we1 : OUT STD_LOGIC;
    keys_d1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    values_address0 : OUT STD_LOGIC_VECTOR (0 downto 0);
    values_ce0 : OUT STD_LOGIC;
    values_we0 : OUT STD_LOGIC;
    values_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    values_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    values_address1 : OUT STD_LOGIC_VECTOR (0 downto 0);
    values_ce1 : OUT STD_LOGIC;
    values_we1 : OUT STD_LOGIC;
    values_d1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    values_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    memCommand : OUT STD_LOGIC_VECTOR (1 downto 0);
    memCommand_ap_vld : OUT STD_LOGIC;
    fsmState_i : IN STD_LOGIC_VECTOR (31 downto 0);
    fsmState_o : OUT STD_LOGIC_VECTOR (31 downto 0);
    fsmState_o_ap_vld : OUT STD_LOGIC;
    reset : IN STD_LOGIC;
    op1 : IN STD_LOGIC_VECTOR (31 downto 0);
    op2 : IN STD_LOGIC_VECTOR (31 downto 0);
    command : IN STD_LOGIC_VECTOR (1 downto 0);
    inputReady : IN STD_LOGIC;
    result1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    result1_ap_vld : OUT STD_LOGIC;
    result2 : OUT STD_LOGIC_VECTOR (31 downto 0);
    result2_ap_vld : OUT STD_LOGIC;
    outputReady : OUT STD_LOGIC;
    outputReady_ap_vld : OUT STD_LOGIC );
end;


architecture behav of xtea_fsm is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv64_1 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000001";
    constant ap_const_lv64_2 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000010";
    constant ap_const_lv64_3 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000011";
    constant ap_const_lv32_E : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001110";
    constant ap_const_lv32_D : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001101";
    constant ap_const_lv32_C : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001100";
    constant ap_const_lv32_B : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001011";
    constant ap_const_lv32_A : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001010";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv32_8 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001000";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv2_1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_const_lv2_2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal tmp_read_fu_140_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_reg_419 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm : STD_LOGIC_VECTOR (1 downto 0);
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal tmp_1_read_fu_146_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_1_reg_423 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_393_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_5_reg_427 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_4_reg_441 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_s_gep_fu_263_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_1_gep_fu_272_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_3_fu_401_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_3_reg_455 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_6_fu_407_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_6_reg_459 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_values_Val_V_ad_2_gep_fu_308_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_values_Val_V_ad_3_gep_fu_317_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_values_Val_V_ad_gep_fu_326_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_2_read_fu_191_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_values_Val_V_ad_1_gep_fu_336_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal tmp_7_fu_413_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_condition_284 : BOOLEAN;
    signal ap_condition_289 : BOOLEAN;
    signal ap_condition_294 : BOOLEAN;


begin



    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                tmp_1_reg_423 <= fsmState_i;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                tmp_3_reg_455 <= tmp_3_fu_401_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((tmp_1_read_fu_146_p2 = ap_const_lv32_3) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                tmp_4_reg_441 <= counter(5 downto 5);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((tmp_1_read_fu_146_p2 = ap_const_lv32_4) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                tmp_5_reg_427 <= counter(5 downto 5);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                tmp_6_reg_459 <= tmp_6_fu_407_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state1)) then
                tmp_reg_419 <= (0=>reset, others=>'-');
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_CS_fsm)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                ap_NS_fsm <= ap_ST_fsm_state2;
            when ap_ST_fsm_state2 => 
                ap_NS_fsm <= ap_ST_fsm_state1;
            when others =>  
                ap_NS_fsm <= "XX";
        end case;
    end process;
    ap_CS_fsm <= ap_ST_fsm_state1;
    ap_CS_fsm_state1 <= ap_ST_fsm_state1(0);
    ap_CS_fsm_state2 <= ap_ST_fsm_state1(1);

    ap_condition_284_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, grp_fu_393_p3)
    begin
                ap_condition_284 <= ((grp_fu_393_p3 = ap_const_lv1_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1));
    end process;


    ap_condition_289_assign_proc : process(tmp_reg_419, tmp_1_reg_423, ap_CS_fsm_state2)
    begin
                ap_condition_289 <= ((tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2));
    end process;


    ap_condition_294_assign_proc : process(tmp_1_read_fu_146_p2, tmp_3_fu_401_p2, tmp_6_fu_407_p2)
    begin
                ap_condition_294 <= ((tmp_6_fu_407_p2 = ap_const_lv1_1) and (tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1));
    end process;


    dpValues_address0_assign_proc : process(tmp_1_read_fu_146_p2, xtea_dpValues_Val_V_s_gep_fu_263_p3, ap_condition_284)
    begin
        if ((ap_const_boolean_1 = ap_condition_284)) then
            if ((tmp_1_read_fu_146_p2 = ap_const_lv32_3)) then 
                dpValues_address0 <= xtea_dpValues_Val_V_s_gep_fu_263_p3;
            elsif ((tmp_1_read_fu_146_p2 = ap_const_lv32_4)) then 
                dpValues_address0 <= ap_const_lv64_0(1 - 1 downto 0);
            else 
                dpValues_address0 <= "X";
            end if;
        else 
            dpValues_address0 <= "X";
        end if; 
    end process;


    dpValues_address1_assign_proc : process(tmp_1_read_fu_146_p2, xtea_dpValues_Val_V_1_gep_fu_272_p3, ap_condition_284)
    begin
        if ((ap_const_boolean_1 = ap_condition_284)) then
            if ((tmp_1_read_fu_146_p2 = ap_const_lv32_3)) then 
                dpValues_address1 <= xtea_dpValues_Val_V_1_gep_fu_272_p3;
            elsif ((tmp_1_read_fu_146_p2 = ap_const_lv32_4)) then 
                dpValues_address1 <= ap_const_lv64_1(1 - 1 downto 0);
            else 
                dpValues_address1 <= "X";
            end if;
        else 
            dpValues_address1 <= "X";
        end if; 
    end process;


    dpValues_ce0_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, grp_fu_393_p3)
    begin
        if ((((grp_fu_393_p3 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_3) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((grp_fu_393_p3 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_4) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            dpValues_ce0 <= ap_const_logic_1;
        else 
            dpValues_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    dpValues_ce1_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, grp_fu_393_p3)
    begin
        if ((((grp_fu_393_p3 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_3) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((grp_fu_393_p3 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_4) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            dpValues_ce1 <= ap_const_logic_1;
        else 
            dpValues_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    fsmState_o_assign_proc : process(fsmState_i, tmp_read_fu_140_p2, tmp_reg_419, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_1_reg_423, grp_fu_393_p3, tmp_5_reg_427, tmp_4_reg_441, tmp_3_fu_401_p2, tmp_3_reg_455, tmp_6_fu_407_p2, tmp_6_reg_459, tmp_2_read_fu_191_p2, ap_CS_fsm_state2, tmp_7_fu_413_p2)
    begin
        if ((((tmp_read_fu_140_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_4_reg_441 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_3) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_5_reg_427 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_4) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            fsmState_o <= ap_const_lv32_0;
        elsif (((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_1;
        elsif (((grp_fu_393_p3 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_3) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_5;
        elsif (((grp_fu_393_p3 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_4) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_A;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_5) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_6;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_6) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_7;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_7) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_8;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_8) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_9;
        elsif ((((tmp_1_read_fu_146_p2 = ap_const_lv32_9) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_7_fu_413_p2 = ap_const_lv1_1) and (tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_6_fu_407_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            fsmState_o <= ap_const_lv32_3;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_A) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_B;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_B) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_C;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_C) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_D;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_D) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            fsmState_o <= ap_const_lv32_E;
        elsif ((((tmp_1_read_fu_146_p2 = ap_const_lv32_E) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_7_fu_413_p2 = ap_const_lv1_0) and (tmp_6_fu_407_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            fsmState_o <= ap_const_lv32_4;
        else 
            fsmState_o <= fsmState_i;
        end if; 
    end process;


    fsmState_o_ap_vld_assign_proc : process(tmp_read_fu_140_p2, tmp_reg_419, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_1_reg_423, grp_fu_393_p3, tmp_5_reg_427, tmp_4_reg_441, tmp_3_fu_401_p2, tmp_3_reg_455, tmp_6_fu_407_p2, tmp_6_reg_459, tmp_2_read_fu_191_p2, ap_CS_fsm_state2, tmp_7_fu_413_p2)
    begin
        if ((((grp_fu_393_p3 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_3) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((grp_fu_393_p3 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_4) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_5) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_6) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_7) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_8) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_9) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_A) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_B) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_C) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_D) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_1_read_fu_146_p2 = ap_const_lv32_E) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_7_fu_413_p2 = ap_const_lv1_1) and (tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_6_fu_407_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_7_fu_413_p2 = ap_const_lv1_0) and (tmp_6_fu_407_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_read_fu_140_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_4_reg_441 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_3) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_5_reg_427 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_4) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            fsmState_o_ap_vld <= ap_const_logic_1;
        else 
            fsmState_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    grp_fu_393_p3 <= counter(5 downto 5);

    keys_address0_assign_proc : process(tmp_3_reg_455, tmp_6_reg_459, ap_condition_289)
    begin
        if ((ap_const_boolean_1 = ap_condition_289)) then
            if ((tmp_3_reg_455 = ap_const_lv1_1)) then 
                keys_address0 <= ap_const_lv64_0(2 - 1 downto 0);
            elsif (((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0))) then 
                keys_address0 <= ap_const_lv64_2(2 - 1 downto 0);
            else 
                keys_address0 <= "XX";
            end if;
        else 
            keys_address0 <= "XX";
        end if; 
    end process;


    keys_address1_assign_proc : process(tmp_3_reg_455, tmp_6_reg_459, ap_condition_289)
    begin
        if ((ap_const_boolean_1 = ap_condition_289)) then
            if ((tmp_3_reg_455 = ap_const_lv1_1)) then 
                keys_address1 <= ap_const_lv64_1(2 - 1 downto 0);
            elsif (((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0))) then 
                keys_address1 <= ap_const_lv64_3(2 - 1 downto 0);
            else 
                keys_address1 <= "XX";
            end if;
        else 
            keys_address1 <= "XX";
        end if; 
    end process;


    keys_ce0_assign_proc : process(tmp_reg_419, tmp_1_reg_423, tmp_3_reg_455, tmp_6_reg_459, ap_CS_fsm_state2)
    begin
        if ((((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            keys_ce0 <= ap_const_logic_1;
        else 
            keys_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    keys_ce1_assign_proc : process(tmp_reg_419, tmp_1_reg_423, tmp_3_reg_455, tmp_6_reg_459, ap_CS_fsm_state2)
    begin
        if ((((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            keys_ce1 <= ap_const_logic_1;
        else 
            keys_ce1 <= ap_const_logic_0;
        end if; 
    end process;

    keys_d0 <= values_q0;
    keys_d1 <= values_q1;

    keys_we0_assign_proc : process(tmp_reg_419, tmp_1_reg_423, tmp_3_reg_455, tmp_6_reg_459, ap_CS_fsm_state2)
    begin
        if ((((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            keys_we0 <= ap_const_logic_1;
        else 
            keys_we0 <= ap_const_logic_0;
        end if; 
    end process;


    keys_we1_assign_proc : process(tmp_reg_419, tmp_1_reg_423, tmp_3_reg_455, tmp_6_reg_459, ap_CS_fsm_state2)
    begin
        if ((((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            keys_we1 <= ap_const_logic_1;
        else 
            keys_we1 <= ap_const_logic_0;
        end if; 
    end process;

    memCommand <= command;

    memCommand_ap_vld_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_2_read_fu_191_p2)
    begin
        if (((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            memCommand_ap_vld <= ap_const_logic_1;
        else 
            memCommand_ap_vld <= ap_const_logic_0;
        end if; 
    end process;


    outputReady_assign_proc : process(tmp_read_fu_140_p2, tmp_reg_419, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_1_reg_423, tmp_5_reg_427, tmp_4_reg_441, tmp_3_reg_455, tmp_6_reg_459, ap_CS_fsm_state2)
    begin
        if ((((tmp_4_reg_441 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_3) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_5_reg_427 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_4) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            outputReady <= ap_const_logic_1;
        elsif (((tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            outputReady <= ap_const_logic_0;
        else 
            outputReady <= 'X';
        end if; 
    end process;


    outputReady_ap_vld_assign_proc : process(tmp_read_fu_140_p2, tmp_reg_419, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_1_reg_423, tmp_5_reg_427, tmp_4_reg_441, tmp_3_reg_455, tmp_6_reg_459, ap_CS_fsm_state2)
    begin
        if ((((tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_4_reg_441 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_3) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_5_reg_427 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_4) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_3_reg_455 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_6_reg_459 = ap_const_lv1_1) and (tmp_3_reg_455 = ap_const_lv1_0) and (tmp_1_reg_423 = ap_const_lv32_1) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            outputReady_ap_vld <= ap_const_logic_1;
        else 
            outputReady_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    result1 <= dpValues_q0;

    result1_ap_vld_assign_proc : process(tmp_reg_419, tmp_1_reg_423, tmp_5_reg_427, tmp_4_reg_441, ap_CS_fsm_state2)
    begin
        if ((((tmp_4_reg_441 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_3) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_5_reg_427 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_4) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            result1_ap_vld <= ap_const_logic_1;
        else 
            result1_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    result2 <= dpValues_q1;

    result2_ap_vld_assign_proc : process(tmp_reg_419, tmp_1_reg_423, tmp_5_reg_427, tmp_4_reg_441, ap_CS_fsm_state2)
    begin
        if ((((tmp_4_reg_441 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_3) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_5_reg_427 = ap_const_lv1_1) and (tmp_1_reg_423 = ap_const_lv32_4) and (tmp_reg_419 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            result2_ap_vld <= ap_const_logic_1;
        else 
            result2_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    tmp_1_read_fu_146_p2 <= fsmState_i;
    tmp_2_read_fu_191_p2 <= (0=>inputReady, others=>'-');
    tmp_3_fu_401_p2 <= "1" when (command = ap_const_lv2_0) else "0";
    tmp_6_fu_407_p2 <= "1" when (command = ap_const_lv2_1) else "0";
    tmp_7_fu_413_p2 <= "1" when (command = ap_const_lv2_2) else "0";
    tmp_read_fu_140_p2 <= (0=>reset, others=>'-');

    values_address0_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_3_fu_401_p2, xtea_values_Val_V_ad_2_gep_fu_308_p3, xtea_values_Val_V_ad_gep_fu_326_p3, tmp_2_read_fu_191_p2, ap_condition_294)
    begin
        if (((tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
            if (((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0))) then 
                values_address0 <= xtea_values_Val_V_ad_gep_fu_326_p3;
            elsif (((tmp_3_fu_401_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1))) then 
                values_address0 <= xtea_values_Val_V_ad_2_gep_fu_308_p3;
            elsif ((ap_const_boolean_1 = ap_condition_294)) then 
                values_address0 <= ap_const_lv64_0(1 - 1 downto 0);
            else 
                values_address0 <= "X";
            end if;
        else 
            values_address0 <= "X";
        end if; 
    end process;


    values_address1_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_3_fu_401_p2, xtea_values_Val_V_ad_3_gep_fu_317_p3, tmp_2_read_fu_191_p2, xtea_values_Val_V_ad_1_gep_fu_336_p3, ap_condition_294)
    begin
        if (((tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
            if (((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0))) then 
                values_address1 <= xtea_values_Val_V_ad_1_gep_fu_336_p3;
            elsif (((tmp_3_fu_401_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1))) then 
                values_address1 <= xtea_values_Val_V_ad_3_gep_fu_317_p3;
            elsif ((ap_const_boolean_1 = ap_condition_294)) then 
                values_address1 <= ap_const_lv64_1(1 - 1 downto 0);
            else 
                values_address1 <= "X";
            end if;
        else 
            values_address1 <= "X";
        end if; 
    end process;


    values_ce0_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_3_fu_401_p2, tmp_6_fu_407_p2, tmp_2_read_fu_191_p2)
    begin
        if ((((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_3_fu_401_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_6_fu_407_p2 = ap_const_lv1_1) and (tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            values_ce0 <= ap_const_logic_1;
        else 
            values_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    values_ce1_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_3_fu_401_p2, tmp_6_fu_407_p2, tmp_2_read_fu_191_p2)
    begin
        if ((((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_3_fu_401_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_6_fu_407_p2 = ap_const_lv1_1) and (tmp_3_fu_401_p2 = ap_const_lv1_0) and (tmp_1_read_fu_146_p2 = ap_const_lv32_1) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            values_ce1 <= ap_const_logic_1;
        else 
            values_ce1 <= ap_const_logic_0;
        end if; 
    end process;

    values_d0 <= op1;
    values_d1 <= op2;

    values_we0_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_2_read_fu_191_p2)
    begin
        if (((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            values_we0 <= ap_const_logic_1;
        else 
            values_we0 <= ap_const_logic_0;
        end if; 
    end process;


    values_we1_assign_proc : process(tmp_read_fu_140_p2, ap_CS_fsm_state1, tmp_1_read_fu_146_p2, tmp_2_read_fu_191_p2)
    begin
        if (((tmp_2_read_fu_191_p2 = ap_const_lv1_1) and (tmp_1_read_fu_146_p2 = ap_const_lv32_0) and (tmp_read_fu_140_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            values_we1 <= ap_const_logic_1;
        else 
            values_we1 <= ap_const_logic_0;
        end if; 
    end process;

    xtea_dpValues_Val_V_1_gep_fu_272_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_dpValues_Val_V_s_gep_fu_263_p3 <= ap_const_lv64_0(1 - 1 downto 0);
    xtea_values_Val_V_ad_1_gep_fu_336_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_values_Val_V_ad_2_gep_fu_308_p3 <= ap_const_lv64_0(1 - 1 downto 0);
    xtea_values_Val_V_ad_3_gep_fu_317_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_values_Val_V_ad_gep_fu_326_p3 <= ap_const_lv64_0(1 - 1 downto 0);
end behav;