-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2018.2.2
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity xtea_datapath is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    counter_i : IN STD_LOGIC_VECTOR (5 downto 0);
    counter_o : OUT STD_LOGIC_VECTOR (5 downto 0);
    counter_o_ap_vld : OUT STD_LOGIC;
    sum_i : IN STD_LOGIC_VECTOR (63 downto 0);
    sum_o : OUT STD_LOGIC_VECTOR (63 downto 0);
    sum_o_ap_vld : OUT STD_LOGIC;
    temp_i : IN STD_LOGIC_VECTOR (31 downto 0);
    temp_o : OUT STD_LOGIC_VECTOR (31 downto 0);
    temp_o_ap_vld : OUT STD_LOGIC;
    acc_i : IN STD_LOGIC_VECTOR (31 downto 0);
    acc_o : OUT STD_LOGIC_VECTOR (31 downto 0);
    acc_o_ap_vld : OUT STD_LOGIC;
    dpValues_address0 : OUT STD_LOGIC_VECTOR (0 downto 0);
    dpValues_ce0 : OUT STD_LOGIC;
    dpValues_we0 : OUT STD_LOGIC;
    dpValues_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    dpValues_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    dpValues_address1 : OUT STD_LOGIC_VECTOR (0 downto 0);
    dpValues_ce1 : OUT STD_LOGIC;
    dpValues_we1 : OUT STD_LOGIC;
    dpValues_d1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    keys_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    keys_ce0 : OUT STD_LOGIC;
    keys_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    values_address0 : OUT STD_LOGIC_VECTOR (0 downto 0);
    values_ce0 : OUT STD_LOGIC;
    values_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    values_address1 : OUT STD_LOGIC_VECTOR (0 downto 0);
    values_ce1 : OUT STD_LOGIC;
    values_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    fsmState : IN STD_LOGIC_VECTOR (31 downto 0);
    command : IN STD_LOGIC_VECTOR (1 downto 0) );
end;


architecture behav of xtea_datapath is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_E : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001110";
    constant ap_const_lv32_B : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001011";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv32_A : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001010";
    constant ap_const_lv32_8 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001000";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_D : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001101";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv32_C : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001100";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv64_1 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000001";
    constant ap_const_lv6_0 : STD_LOGIC_VECTOR (5 downto 0) := "000000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv64_C6EF3720 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000011000110111011110011011100100000";
    constant ap_const_lv6_1 : STD_LOGIC_VECTOR (5 downto 0) := "000001";
    constant ap_const_lv64_FFFFFFFF61C88647 : STD_LOGIC_VECTOR (63 downto 0) := "1111111111111111111111111111111101100001110010001000011001000111";
    constant ap_const_lv32_1F : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000011111";
    constant ap_const_lv64_9E3779B9 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000010011110001101110111100110111001";
    constant ap_const_lv2_2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv2_3 : STD_LOGIC_VECTOR (1 downto 0) := "11";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal tmp_read_fu_144_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_reg_548 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm : STD_LOGIC_VECTOR (1 downto 0);
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal xtea_dpValues_Val_V_9_gep_fu_234_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_8_gep_fu_243_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_6_gep_fu_266_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_5_gep_fu_275_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_3_fu_410_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_9_fu_419_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal xtea_dpValues_Val_V_14_gep_fu_319_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal xtea_dpValues_Val_V_12_gep_fu_328_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_10_gep_fu_337_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_7_gep_fu_346_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xtea_dpValues_Val_V_s_gep_fu_355_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal grp_fu_386_p2 : STD_LOGIC_VECTOR (5 downto 0);
    signal tmp_8_fu_536_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_7_fu_542_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal v_V_21_fu_424_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal v_V_15_fu_480_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal v_V_17_fu_473_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal v_V_13_fu_529_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_379_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_393_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal p_Result_1_fu_400_p4 : STD_LOGIC_VECTOR (1 downto 0);
    signal tmp_10_fu_415_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal r_V_9_fu_437_p4 : STD_LOGIC_VECTOR (26 downto 0);
    signal r_V_10_fu_431_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal r_V_11_fu_447_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal r_V_4_fu_451_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_14_fu_463_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_4_fu_457_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_6_fu_467_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal r_V_7_fu_493_p4 : STD_LOGIC_VECTOR (26 downto 0);
    signal r_V_6_fu_487_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal r_V_8_fu_503_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal r_V_fu_507_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_12_fu_519_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_s_fu_513_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_2_fu_523_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_condition_171 : BOOLEAN;


begin



    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state1)) then
                tmp_reg_548 <= fsmState;
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

    acc_o_assign_proc : process(acc_i, tmp_reg_548, ap_CS_fsm_state2, v_V_17_fu_473_p2, v_V_13_fu_529_p2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
            if (((tmp_reg_548 = ap_const_lv32_5) or (tmp_reg_548 = ap_const_lv32_D))) then 
                acc_o <= v_V_13_fu_529_p2;
            elsif (((tmp_reg_548 = ap_const_lv32_8) or (tmp_reg_548 = ap_const_lv32_A))) then 
                acc_o <= v_V_17_fu_473_p2;
            else 
                acc_o <= acc_i;
            end if;
        else 
            acc_o <= acc_i;
        end if; 
    end process;


    acc_o_ap_vld_assign_proc : process(tmp_reg_548, ap_CS_fsm_state2)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_state2) and ((tmp_reg_548 = ap_const_lv32_5) or (tmp_reg_548 = ap_const_lv32_D))) or ((ap_const_logic_1 = ap_CS_fsm_state2) and ((tmp_reg_548 = ap_const_lv32_8) or (tmp_reg_548 = ap_const_lv32_A))))) then 
            acc_o_ap_vld <= ap_const_logic_1;
        else 
            acc_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    ap_CS_fsm <= ap_ST_fsm_state1;
    ap_CS_fsm_state1 <= ap_ST_fsm_state1(0);
    ap_CS_fsm_state2 <= ap_ST_fsm_state1(1);

    ap_condition_171_assign_proc : process(tmp_reg_548, tmp_8_fu_536_p2, tmp_7_fu_542_p2)
    begin
                ap_condition_171 <= ((tmp_reg_548 = ap_const_lv32_1) and (tmp_7_fu_542_p2 = ap_const_lv1_1) and (tmp_8_fu_536_p2 = ap_const_lv1_0));
    end process;


    counter_o_assign_proc : process(counter_i, tmp_reg_548, ap_CS_fsm_state2, grp_fu_386_p2, tmp_8_fu_536_p2, tmp_7_fu_542_p2)
    begin
        if ((((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2) and (tmp_8_fu_536_p2 = ap_const_lv1_1)) or ((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2) and (tmp_7_fu_542_p2 = ap_const_lv1_1) and (tmp_8_fu_536_p2 = ap_const_lv1_0)))) then 
            counter_o <= ap_const_lv6_0;
        elsif ((((tmp_reg_548 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            counter_o <= grp_fu_386_p2;
        else 
            counter_o <= counter_i;
        end if; 
    end process;


    counter_o_ap_vld_assign_proc : process(tmp_reg_548, ap_CS_fsm_state2, tmp_8_fu_536_p2, tmp_7_fu_542_p2)
    begin
        if ((((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2) and (tmp_8_fu_536_p2 = ap_const_lv1_1)) or ((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2) and (tmp_7_fu_542_p2 = ap_const_lv1_1) and (tmp_8_fu_536_p2 = ap_const_lv1_0)) or ((tmp_reg_548 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            counter_o_ap_vld <= ap_const_logic_1;
        else 
            counter_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;


    dpValues_address0_assign_proc : process(tmp_read_fu_144_p2, tmp_reg_548, ap_CS_fsm_state1, xtea_dpValues_Val_V_9_gep_fu_234_p3, xtea_dpValues_Val_V_8_gep_fu_243_p3, xtea_dpValues_Val_V_6_gep_fu_266_p3, xtea_dpValues_Val_V_5_gep_fu_275_p3, xtea_dpValues_Val_V_14_gep_fu_319_p3, ap_CS_fsm_state2, xtea_dpValues_Val_V_12_gep_fu_328_p3, xtea_dpValues_Val_V_10_gep_fu_337_p3, xtea_dpValues_Val_V_7_gep_fu_346_p3, xtea_dpValues_Val_V_s_gep_fu_355_p3)
    begin
        if (((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_s_gep_fu_355_p3;
        elsif (((tmp_reg_548 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_7_gep_fu_346_p3;
        elsif (((tmp_reg_548 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_10_gep_fu_337_p3;
        elsif (((tmp_reg_548 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_12_gep_fu_328_p3;
        elsif (((tmp_reg_548 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_14_gep_fu_319_p3;
        elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and ((tmp_read_fu_144_p2 = ap_const_lv32_5) or (tmp_read_fu_144_p2 = ap_const_lv32_D)))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_5_gep_fu_275_p3;
        elsif (((tmp_read_fu_144_p2 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_6_gep_fu_266_p3;
        elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and ((tmp_read_fu_144_p2 = ap_const_lv32_8) or (tmp_read_fu_144_p2 = ap_const_lv32_A)))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_8_gep_fu_243_p3;
        elsif (((tmp_read_fu_144_p2 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            dpValues_address0 <= xtea_dpValues_Val_V_9_gep_fu_234_p3;
        elsif (((tmp_read_fu_144_p2 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            dpValues_address0 <= ap_const_lv64_1(1 - 1 downto 0);
        elsif (((tmp_read_fu_144_p2 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            dpValues_address0 <= ap_const_lv64_0(1 - 1 downto 0);
        else 
            dpValues_address0 <= "X";
        end if; 
    end process;

    dpValues_address1 <= ap_const_lv64_1(1 - 1 downto 0);

    dpValues_ce0_assign_proc : process(tmp_read_fu_144_p2, tmp_reg_548, ap_CS_fsm_state1, ap_CS_fsm_state2)
    begin
        if ((((tmp_read_fu_144_p2 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((ap_const_logic_1 = ap_CS_fsm_state1) and ((tmp_read_fu_144_p2 = ap_const_lv32_8) or (tmp_read_fu_144_p2 = ap_const_lv32_A))) or ((tmp_read_fu_144_p2 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_read_fu_144_p2 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((tmp_read_fu_144_p2 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state1)) or ((ap_const_logic_1 = ap_CS_fsm_state1) and ((tmp_read_fu_144_p2 = ap_const_lv32_5) or (tmp_read_fu_144_p2 = ap_const_lv32_D))) or ((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            dpValues_ce0 <= ap_const_logic_1;
        else 
            dpValues_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    dpValues_ce1_assign_proc : process(ap_CS_fsm_state2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            dpValues_ce1 <= ap_const_logic_1;
        else 
            dpValues_ce1 <= ap_const_logic_0;
        end if; 
    end process;


    dpValues_d0_assign_proc : process(values_q0, tmp_reg_548, ap_CS_fsm_state2, grp_fu_379_p2, grp_fu_393_p2)
    begin
        if (((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_d0 <= values_q0;
        elsif ((((tmp_reg_548 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            dpValues_d0 <= grp_fu_393_p2;
        elsif ((((tmp_reg_548 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            dpValues_d0 <= grp_fu_379_p2;
        else 
            dpValues_d0 <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        end if; 
    end process;

    dpValues_d1 <= values_q1;

    dpValues_we0_assign_proc : process(tmp_reg_548, ap_CS_fsm_state2)
    begin
        if ((((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_9) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_E) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            dpValues_we0 <= ap_const_logic_1;
        else 
            dpValues_we0 <= ap_const_logic_0;
        end if; 
    end process;


    dpValues_we1_assign_proc : process(tmp_reg_548, ap_CS_fsm_state2)
    begin
        if (((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            dpValues_we1 <= ap_const_logic_1;
        else 
            dpValues_we1 <= ap_const_logic_0;
        end if; 
    end process;

    grp_fu_379_p2 <= std_logic_vector(unsigned(dpValues_q0) - unsigned(acc_i));
    grp_fu_386_p2 <= std_logic_vector(unsigned(counter_i) + unsigned(ap_const_lv6_1));
    grp_fu_393_p2 <= std_logic_vector(unsigned(acc_i) + unsigned(dpValues_q0));

    keys_address0_assign_proc : process(tmp_read_fu_144_p2, ap_CS_fsm_state1, tmp_3_fu_410_p1, tmp_9_fu_419_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state1)) then
            if (((tmp_read_fu_144_p2 = ap_const_lv32_3) or (tmp_read_fu_144_p2 = ap_const_lv32_C))) then 
                keys_address0 <= tmp_9_fu_419_p1(2 - 1 downto 0);
            elsif (((tmp_read_fu_144_p2 = ap_const_lv32_7) or (tmp_read_fu_144_p2 = ap_const_lv32_4))) then 
                keys_address0 <= tmp_3_fu_410_p1(2 - 1 downto 0);
            else 
                keys_address0 <= "XX";
            end if;
        else 
            keys_address0 <= "XX";
        end if; 
    end process;


    keys_ce0_assign_proc : process(tmp_read_fu_144_p2, ap_CS_fsm_state1)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_state1) and ((tmp_read_fu_144_p2 = ap_const_lv32_7) or (tmp_read_fu_144_p2 = ap_const_lv32_4))) or ((ap_const_logic_1 = ap_CS_fsm_state1) and ((tmp_read_fu_144_p2 = ap_const_lv32_3) or (tmp_read_fu_144_p2 = ap_const_lv32_C))))) then 
            keys_ce0 <= ap_const_logic_1;
        else 
            keys_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    p_Result_1_fu_400_p4 <= sum_i(12 downto 11);
    r_V_10_fu_431_p2 <= std_logic_vector(shift_left(unsigned(dpValues_q0),to_integer(unsigned('0' & ap_const_lv32_4(31-1 downto 0)))));
    r_V_11_fu_447_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(r_V_9_fu_437_p4),32));
    r_V_4_fu_451_p2 <= (r_V_11_fu_447_p1 xor r_V_10_fu_431_p2);
    r_V_6_fu_487_p2 <= std_logic_vector(shift_left(unsigned(dpValues_q0),to_integer(unsigned('0' & ap_const_lv32_4(31-1 downto 0)))));
    r_V_7_fu_493_p4 <= dpValues_q0(31 downto 5);
    r_V_8_fu_503_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(r_V_7_fu_493_p4),32));
    r_V_9_fu_437_p4 <= dpValues_q0(31 downto 5);
    r_V_fu_507_p2 <= (r_V_8_fu_503_p1 xor r_V_6_fu_487_p2);

    sum_o_assign_proc : process(sum_i, tmp_reg_548, ap_CS_fsm_state2, tmp_8_fu_536_p2, v_V_21_fu_424_p2, v_V_15_fu_480_p2, ap_condition_171)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
            if (((tmp_reg_548 = ap_const_lv32_1) and (tmp_8_fu_536_p2 = ap_const_lv1_1))) then 
                sum_o <= ap_const_lv64_0;
            elsif ((ap_const_boolean_1 = ap_condition_171)) then 
                sum_o <= ap_const_lv64_C6EF3720;
            elsif ((tmp_reg_548 = ap_const_lv32_6)) then 
                sum_o <= v_V_15_fu_480_p2;
            elsif ((tmp_reg_548 = ap_const_lv32_B)) then 
                sum_o <= v_V_21_fu_424_p2;
            else 
                sum_o <= sum_i;
            end if;
        else 
            sum_o <= sum_i;
        end if; 
    end process;


    sum_o_ap_vld_assign_proc : process(tmp_reg_548, ap_CS_fsm_state2, tmp_8_fu_536_p2, tmp_7_fu_542_p2)
    begin
        if ((((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2) and (tmp_8_fu_536_p2 = ap_const_lv1_1)) or ((tmp_reg_548 = ap_const_lv32_1) and (ap_const_logic_1 = ap_CS_fsm_state2) and (tmp_7_fu_542_p2 = ap_const_lv1_1) and (tmp_8_fu_536_p2 = ap_const_lv1_0)) or ((tmp_reg_548 = ap_const_lv32_6) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((tmp_reg_548 = ap_const_lv32_B) and (ap_const_logic_1 = ap_CS_fsm_state2)))) then 
            sum_o_ap_vld <= ap_const_logic_1;
        else 
            sum_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;


    temp_o_assign_proc : process(temp_i, keys_q0, tmp_reg_548, ap_CS_fsm_state2)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_state2) and ((tmp_reg_548 = ap_const_lv32_3) or (tmp_reg_548 = ap_const_lv32_C))) or ((ap_const_logic_1 = ap_CS_fsm_state2) and ((tmp_reg_548 = ap_const_lv32_7) or (tmp_reg_548 = ap_const_lv32_4))))) then 
            temp_o <= keys_q0;
        else 
            temp_o <= temp_i;
        end if; 
    end process;


    temp_o_ap_vld_assign_proc : process(tmp_reg_548, ap_CS_fsm_state2)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_state2) and ((tmp_reg_548 = ap_const_lv32_3) or (tmp_reg_548 = ap_const_lv32_C))) or ((ap_const_logic_1 = ap_CS_fsm_state2) and ((tmp_reg_548 = ap_const_lv32_7) or (tmp_reg_548 = ap_const_lv32_4))))) then 
            temp_o_ap_vld <= ap_const_logic_1;
        else 
            temp_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    tmp_10_fu_415_p1 <= sum_i(2 - 1 downto 0);
    tmp_12_fu_519_p1 <= sum_i(32 - 1 downto 0);
    tmp_14_fu_463_p1 <= sum_i(32 - 1 downto 0);
    tmp_2_fu_523_p2 <= std_logic_vector(unsigned(tmp_12_fu_519_p1) + unsigned(temp_i));
    tmp_3_fu_410_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(p_Result_1_fu_400_p4),64));
    tmp_4_fu_457_p2 <= std_logic_vector(unsigned(r_V_4_fu_451_p2) + unsigned(dpValues_q0));
    tmp_6_fu_467_p2 <= std_logic_vector(unsigned(tmp_14_fu_463_p1) + unsigned(temp_i));
    tmp_7_fu_542_p2 <= "1" when (command = ap_const_lv2_3) else "0";
    tmp_8_fu_536_p2 <= "1" when (command = ap_const_lv2_2) else "0";
    tmp_9_fu_419_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_10_fu_415_p1),64));
    tmp_read_fu_144_p2 <= fsmState;
    tmp_s_fu_513_p2 <= std_logic_vector(unsigned(r_V_fu_507_p2) + unsigned(dpValues_q0));
    v_V_13_fu_529_p2 <= (tmp_s_fu_513_p2 xor tmp_2_fu_523_p2);
    v_V_15_fu_480_p2 <= std_logic_vector(unsigned(sum_i) + unsigned(ap_const_lv64_9E3779B9));
    v_V_17_fu_473_p2 <= (tmp_6_fu_467_p2 xor tmp_4_fu_457_p2);
    v_V_21_fu_424_p2 <= std_logic_vector(unsigned(sum_i) + unsigned(ap_const_lv64_FFFFFFFF61C88647));
    values_address0 <= ap_const_lv64_0(1 - 1 downto 0);
    values_address1 <= ap_const_lv64_1(1 - 1 downto 0);

    values_ce0_assign_proc : process(ap_CS_fsm_state1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state1)) then 
            values_ce0 <= ap_const_logic_1;
        else 
            values_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    values_ce1_assign_proc : process(ap_CS_fsm_state1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state1)) then 
            values_ce1 <= ap_const_logic_1;
        else 
            values_ce1 <= ap_const_logic_0;
        end if; 
    end process;

    xtea_dpValues_Val_V_10_gep_fu_337_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_dpValues_Val_V_12_gep_fu_328_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_dpValues_Val_V_14_gep_fu_319_p3 <= ap_const_lv64_0(1 - 1 downto 0);
    xtea_dpValues_Val_V_5_gep_fu_275_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_dpValues_Val_V_6_gep_fu_266_p3 <= ap_const_lv64_0(1 - 1 downto 0);
    xtea_dpValues_Val_V_7_gep_fu_346_p3 <= ap_const_lv64_0(1 - 1 downto 0);
    xtea_dpValues_Val_V_8_gep_fu_243_p3 <= ap_const_lv64_0(1 - 1 downto 0);
    xtea_dpValues_Val_V_9_gep_fu_234_p3 <= ap_const_lv64_1(1 - 1 downto 0);
    xtea_dpValues_Val_V_s_gep_fu_355_p3 <= ap_const_lv64_0(1 - 1 downto 0);
end behav;
