<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="CLK" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="LED2" />
        <signal name="LED1" />
        <signal name="EN_FIB_OP" />
        <signal name="RED_REF" />
        <signal name="YEL_REF" />
        <signal name="BLU_REF" />
        <signal name="ZX_INT" />
        <signal name="XLXN_40" />
        <signal name="XLXN_44" />
        <signal name="D(15:0)" />
        <signal name="XLXN_56" />
        <signal name="n_CS" />
        <signal name="n_OE" />
        <signal name="n_WE" />
        <signal name="XLXN_70(15:0)" />
        <signal name="A(6:0)" />
        <signal name="XLXN_74" />
        <signal name="XLXN_84" />
        <signal name="XLXN_85" />
        <signal name="XLXN_86" />
        <signal name="XLXN_87" />
        <signal name="XLXN_88" />
        <signal name="XLXN_89" />
        <signal name="XLXN_90" />
        <signal name="XLXN_93" />
        <signal name="XLXN_95" />
        <signal name="XLXN_100" />
        <signal name="XLXN_106" />
        <signal name="XLXN_107" />
        <signal name="XLXN_23" />
        <signal name="XLXN_108" />
        <signal name="XLXN_110" />
        <signal name="XLXN_111" />
        <signal name="XLXN_112" />
        <port polarity="Input" name="CLK" />
        <port polarity="Output" name="LED2" />
        <port polarity="Output" name="LED1" />
        <port polarity="Output" name="EN_FIB_OP" />
        <port polarity="Input" name="RED_REF" />
        <port polarity="Input" name="YEL_REF" />
        <port polarity="Input" name="BLU_REF" />
        <port polarity="Output" name="ZX_INT" />
        <port polarity="Output" name="D(15:0)" />
        <port polarity="Input" name="n_CS" />
        <port polarity="Input" name="n_OE" />
        <port polarity="Input" name="n_WE" />
        <port polarity="Input" name="A(6:0)" />
        <blockdef name="DCM">
            <timestamp>2019-1-17T13:9:11</timestamp>
            <rect width="336" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="464" y1="-224" y2="-224" x1="400" />
            <line x2="464" y1="-160" y2="-160" x1="400" />
            <line x2="464" y1="-96" y2="-96" x1="400" />
            <line x2="464" y1="-32" y2="-32" x1="400" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="clkmod">
            <timestamp>2019-1-29T11:16:46</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="pullup">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-108" y2="-128" x1="64" />
            <line x2="64" y1="-104" y2="-108" x1="80" />
            <line x2="80" y1="-88" y2="-104" x1="48" />
            <line x2="48" y1="-72" y2="-88" x1="80" />
            <line x2="80" y1="-56" y2="-72" x1="48" />
            <line x2="48" y1="-48" y2="-56" x1="64" />
            <line x2="64" y1="-32" y2="-48" x1="64" />
            <line x2="64" y1="-56" y2="-48" x1="48" />
            <line x2="48" y1="-72" y2="-56" x1="80" />
            <line x2="80" y1="-88" y2="-72" x1="48" />
            <line x2="48" y1="-104" y2="-88" x1="80" />
            <line x2="80" y1="-108" y2="-104" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-128" y2="-128" x1="96" />
        </blockdef>
        <blockdef name="phaseman">
            <timestamp>2019-1-29T11:37:41</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <blockdef name="periodcnt">
            <timestamp>2019-1-29T14:53:2</timestamp>
            <rect width="368" x="64" y="-448" height="448" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <line x2="0" y1="-352" y2="-352" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="496" y1="-416" y2="-416" x1="432" />
            <line x2="496" y1="-224" y2="-224" x1="432" />
            <rect width="64" x="432" y="-108" height="24" />
            <line x2="496" y1="-96" y2="-96" x1="432" />
        </blockdef>
        <blockdef name="demand">
            <timestamp>2019-1-29T14:41:28</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
        </blockdef>
        <blockdef name="constant">
            <timestamp>2006-1-1T10:10:10</timestamp>
            <rect width="112" x="0" y="0" height="64" />
            <line x2="112" y1="32" y2="32" x1="144" />
        </blockdef>
        <blockdef name="statem">
            <timestamp>2019-1-29T15:42:44</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-236" height="24" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
        </blockdef>
        <block symbolname="DCM" name="XLXI_1">
            <blockpin signalname="CLK" name="CLKIN_IN" />
            <blockpin signalname="XLXN_15" name="RST_IN" />
            <blockpin signalname="XLXN_23" name="CLKDV_OUT" />
            <blockpin name="CLKIN_IBUFG_OUT" />
            <blockpin name="CLK0_OUT" />
            <blockpin name="LOCKED_OUT" />
        </block>
        <block symbolname="gnd" name="XLXI_8">
            <blockpin signalname="XLXN_15" name="G" />
        </block>
        <block symbolname="clkmod" name="XLXI_9">
            <blockpin signalname="XLXN_23" name="clk" />
            <blockpin signalname="XLXN_95" name="rst" />
            <blockpin signalname="XLXN_100" name="enIn" />
            <blockpin signalname="XLXN_44" name="enable" />
            <blockpin signalname="XLXN_40" name="enable1" />
            <blockpin signalname="XLXN_89" name="enable2" />
        </block>
        <block symbolname="pullup" name="XLXI_10">
            <blockpin signalname="XLXN_100" name="O" />
        </block>
        <block symbolname="phaseman" name="XLXI_11">
            <blockpin signalname="XLXN_23" name="clk" />
            <blockpin signalname="XLXN_89" name="enable" />
            <blockpin signalname="RED_REF" name="rphase" />
            <blockpin signalname="YEL_REF" name="yphase" />
            <blockpin signalname="BLU_REF" name="bphase" />
            <blockpin signalname="LED2" name="rotation" />
            <blockpin signalname="LED1" name="missing" />
            <blockpin signalname="ZX_INT" name="rdbphase" />
        </block>
        <block symbolname="nor2" name="XLXI_12">
            <blockpin signalname="LED1" name="I0" />
            <blockpin signalname="LED2" name="I1" />
            <blockpin signalname="EN_FIB_OP" name="O" />
        </block>
        <block symbolname="periodcnt" name="XLXI_13">
            <blockpin signalname="XLXN_23" name="clk" />
            <blockpin signalname="XLXN_40" name="enable12" />
            <blockpin signalname="XLXN_44" name="enable" />
            <blockpin signalname="ZX_INT" name="zxing" />
            <blockpin signalname="XLXN_56" name="cpu_rd" />
            <blockpin signalname="XLXN_74" name="sync" />
            <blockpin signalname="A(6:0)" name="cpu_address(6:0)" />
            <blockpin signalname="XLXN_110" name="fsmclk" />
            <blockpin signalname="XLXN_111" name="gate" />
            <blockpin signalname="D(15:0)" name="cpu_data(15:0)" />
        </block>
        <block symbolname="nor2" name="XLXI_14">
            <blockpin signalname="n_CS" name="I0" />
            <blockpin signalname="n_OE" name="I1" />
            <blockpin signalname="XLXN_56" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_15">
            <blockpin signalname="n_WE" name="I0" />
            <blockpin signalname="n_CS" name="I1" />
            <blockpin name="O" />
        </block>
        <block symbolname="demand" name="XLXI_16">
            <blockpin signalname="XLXN_23" name="clk" />
            <blockpin signalname="XLXN_40" name="enable" />
            <blockpin signalname="ZX_INT" name="zxing" />
            <blockpin signalname="XLXN_70(15:0)" name="delay(15:0)" />
            <blockpin signalname="XLXN_74" name="sync" />
        </block>
        <block symbolname="constant" name="XLXI_17">
            <attr value="0000200" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 32 Hexadecimal" />
            </attr>
            <blockpin signalname="XLXN_70(15:0)" name="O" />
        </block>
        <block symbolname="gnd" name="XLXI_18">
            <blockpin signalname="XLXN_95" name="G" />
        </block>
        <block symbolname="statem" name="XLXI_19">
            <blockpin signalname="XLXN_23" name="clk" />
            <blockpin signalname="XLXN_110" name="sclk" />
            <blockpin signalname="XLXN_74" name="sync" />
            <blockpin signalname="XLXN_111" name="osc" />
            <blockpin name="firing(5:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="2688" height="1900">
        <attr value="CM" name="LengthUnitName" />
        <attr value="4" name="GridsPerUnit" />
        <branch name="CLK">
            <wire x2="560" y1="112" y2="112" x1="512" />
        </branch>
        <iomarker fontsize="28" x="512" y="112" name="CLK" orien="R180" />
        <instance x="432" y="496" name="XLXI_8" orien="R0" />
        <instance x="560" y="336" name="XLXI_1" orien="R0">
        </instance>
        <branch name="LED2">
            <wire x2="1904" y1="464" y2="464" x1="1488" />
            <wire x2="2336" y1="464" y2="464" x1="1904" />
            <wire x2="1904" y1="464" y2="496" x1="1904" />
            <wire x2="1936" y1="496" y2="496" x1="1904" />
        </branch>
        <branch name="EN_FIB_OP">
            <wire x2="2336" y1="528" y2="528" x1="2192" />
        </branch>
        <branch name="D(15:0)">
            <wire x2="992" y1="1488" y2="1488" x1="272" />
            <wire x2="992" y1="1296" y2="1296" x1="928" />
            <wire x2="992" y1="1296" y2="1488" x1="992" />
        </branch>
        <iomarker fontsize="28" x="272" y="1488" name="D(15:0)" orien="R180" />
        <instance x="272" y="1744" name="XLXI_14" orien="R0" />
        <branch name="XLXN_56">
            <wire x2="432" y1="1232" y2="1232" x1="352" />
            <wire x2="352" y1="1232" y2="1536" x1="352" />
            <wire x2="656" y1="1536" y2="1536" x1="352" />
            <wire x2="656" y1="1536" y2="1648" x1="656" />
            <wire x2="656" y1="1648" y2="1648" x1="528" />
        </branch>
        <branch name="ZX_INT">
            <wire x2="320" y1="768" y2="1168" x1="320" />
            <wire x2="432" y1="1168" y2="1168" x1="320" />
            <wire x2="1584" y1="768" y2="768" x1="320" />
            <wire x2="1584" y1="768" y2="1104" x1="1584" />
            <wire x2="1584" y1="720" y2="720" x1="1488" />
            <wire x2="1584" y1="720" y2="768" x1="1584" />
            <wire x2="2336" y1="720" y2="720" x1="1584" />
            <wire x2="1584" y1="1104" y2="1104" x1="1520" />
        </branch>
        <branch name="XLXN_44">
            <wire x2="432" y1="1104" y2="1104" x1="400" />
            <wire x2="400" y1="1104" y2="1424" x1="400" />
            <wire x2="1856" y1="1424" y2="1424" x1="400" />
            <wire x2="1856" y1="112" y2="112" x1="1792" />
            <wire x2="1856" y1="112" y2="1424" x1="1856" />
        </branch>
        <branch name="XLXN_40">
            <wire x2="352" y1="800" y2="1040" x1="352" />
            <wire x2="432" y1="1040" y2="1040" x1="352" />
            <wire x2="1824" y1="800" y2="800" x1="352" />
            <wire x2="1824" y1="800" y2="1040" x1="1824" />
            <wire x2="1824" y1="1040" y2="1040" x1="1520" />
            <wire x2="1824" y1="176" y2="176" x1="1792" />
            <wire x2="1824" y1="176" y2="800" x1="1824" />
        </branch>
        <instance x="432" y="1392" name="XLXI_13" orien="R0">
        </instance>
        <instance x="272" y="1888" name="XLXI_15" orien="R0" />
        <branch name="n_OE">
            <wire x2="272" y1="1616" y2="1616" x1="224" />
        </branch>
        <branch name="n_WE">
            <wire x2="272" y1="1824" y2="1824" x1="224" />
        </branch>
        <branch name="n_CS">
            <wire x2="256" y1="1680" y2="1680" x1="224" />
            <wire x2="272" y1="1680" y2="1680" x1="256" />
            <wire x2="256" y1="1680" y2="1760" x1="256" />
            <wire x2="272" y1="1760" y2="1760" x1="256" />
        </branch>
        <iomarker fontsize="28" x="224" y="1680" name="n_CS" orien="R180" />
        <iomarker fontsize="28" x="224" y="1616" name="n_OE" orien="R180" />
        <iomarker fontsize="28" x="224" y="1824" name="n_WE" orien="R180" />
        <instance x="1520" y="1200" name="XLXI_16" orien="M0">
        </instance>
        <branch name="XLXN_70(15:0)">
            <wire x2="1600" y1="1168" y2="1168" x1="1520" />
        </branch>
        <iomarker fontsize="28" x="288" y="1360" name="A(6:0)" orien="R180" />
        <branch name="A(6:0)">
            <wire x2="432" y1="1360" y2="1360" x1="288" />
        </branch>
        <branch name="XLXN_74">
            <wire x2="416" y1="864" y2="1296" x1="416" />
            <wire x2="432" y1="1296" y2="1296" x1="416" />
            <wire x2="416" y1="1296" y2="1520" x1="416" />
            <wire x2="752" y1="1520" y2="1520" x1="416" />
            <wire x2="752" y1="1520" y2="1680" x1="752" />
            <wire x2="1120" y1="1680" y2="1680" x1="752" />
            <wire x2="1136" y1="1680" y2="1680" x1="1120" />
            <wire x2="1120" y1="864" y2="864" x1="416" />
            <wire x2="1120" y1="864" y2="976" x1="1120" />
            <wire x2="1136" y1="976" y2="976" x1="1120" />
        </branch>
        <iomarker fontsize="28" x="576" y="592" name="RED_REF" orien="R180" />
        <iomarker fontsize="28" x="576" y="656" name="YEL_REF" orien="R180" />
        <iomarker fontsize="28" x="576" y="720" name="BLU_REF" orien="R180" />
        <instance x="1744" y="1136" name="XLXI_17" orien="M0">
        </instance>
        <iomarker fontsize="28" x="2336" y="464" name="LED2" orien="R0" />
        <iomarker fontsize="28" x="2336" y="592" name="LED1" orien="R0" />
        <iomarker fontsize="28" x="2336" y="528" name="EN_FIB_OP" orien="R0" />
        <iomarker fontsize="28" x="2336" y="720" name="ZX_INT" orien="R0" />
        <branch name="XLXN_15">
            <wire x2="560" y1="304" y2="304" x1="496" />
            <wire x2="496" y1="304" y2="368" x1="496" />
        </branch>
        <instance x="1936" y="624" name="XLXI_12" orien="R0" />
        <instance x="1232" y="176" name="XLXI_10" orien="M90" />
        <branch name="XLXN_95">
            <wire x2="1360" y1="176" y2="208" x1="1360" />
            <wire x2="1408" y1="176" y2="176" x1="1360" />
        </branch>
        <instance x="1408" y="272" name="XLXI_9" orien="R0">
        </instance>
        <branch name="XLXN_100">
            <wire x2="1408" y1="240" y2="240" x1="1232" />
        </branch>
        <branch name="LED1">
            <wire x2="1904" y1="592" y2="592" x1="1488" />
            <wire x2="2336" y1="592" y2="592" x1="1904" />
            <wire x2="1936" y1="560" y2="560" x1="1904" />
            <wire x2="1904" y1="560" y2="592" x1="1904" />
        </branch>
        <branch name="BLU_REF">
            <wire x2="1104" y1="720" y2="720" x1="576" />
        </branch>
        <branch name="YEL_REF">
            <wire x2="1104" y1="656" y2="656" x1="576" />
        </branch>
        <branch name="RED_REF">
            <wire x2="1104" y1="592" y2="592" x1="576" />
        </branch>
        <branch name="XLXN_89">
            <wire x2="1792" y1="352" y2="352" x1="1088" />
            <wire x2="1088" y1="352" y2="528" x1="1088" />
            <wire x2="1104" y1="528" y2="528" x1="1088" />
            <wire x2="1792" y1="240" y2="352" x1="1792" />
        </branch>
        <instance x="1104" y="752" name="XLXI_11" orien="R0">
        </instance>
        <instance x="1296" y="336" name="XLXI_18" orien="R0" />
        <instance x="1136" y="1776" name="XLXI_19" orien="R0">
        </instance>
        <branch name="XLXN_23">
            <wire x2="1072" y1="832" y2="832" x1="384" />
            <wire x2="1552" y1="832" y2="832" x1="1072" />
            <wire x2="1552" y1="832" y2="976" x1="1552" />
            <wire x2="384" y1="832" y2="976" x1="384" />
            <wire x2="432" y1="976" y2="976" x1="384" />
            <wire x2="384" y1="976" y2="1456" x1="384" />
            <wire x2="1120" y1="1456" y2="1456" x1="384" />
            <wire x2="1120" y1="1456" y2="1552" x1="1120" />
            <wire x2="1136" y1="1552" y2="1552" x1="1120" />
            <wire x2="1072" y1="112" y2="112" x1="1024" />
            <wire x2="1408" y1="112" y2="112" x1="1072" />
            <wire x2="1072" y1="112" y2="464" x1="1072" />
            <wire x2="1104" y1="464" y2="464" x1="1072" />
            <wire x2="1072" y1="464" y2="832" x1="1072" />
            <wire x2="1552" y1="976" y2="976" x1="1520" />
        </branch>
        <branch name="XLXN_110">
            <wire x2="1072" y1="976" y2="976" x1="928" />
            <wire x2="1072" y1="976" y2="1616" x1="1072" />
            <wire x2="1136" y1="1616" y2="1616" x1="1072" />
        </branch>
        <branch name="XLXN_111">
            <wire x2="1024" y1="1168" y2="1168" x1="928" />
            <wire x2="1024" y1="1168" y2="1744" x1="1024" />
            <wire x2="1120" y1="1744" y2="1744" x1="1024" />
            <wire x2="1136" y1="1744" y2="1744" x1="1120" />
        </branch>
    </sheet>
</drawing>