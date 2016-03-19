<?xml version="1.0" encoding="gb2312" standalone="yes" ?>
<Processor>
    <Info Type="Source" Version="2.0" IsLua="0">
        <FileProperty>
            <Property 描述="" />
        </FileProperty>
        <Wizzard Desc="" />
        <Objects />
        <RefFiles />
        <TextIdSeed Seed="1" />
        <Triggers>
            <Trigger Event="23" />
        </Triggers>
    </Info>
    <Variable />
    <Condition>
        <Param bool="true" type="13" srctype="1" data="AUTOP1" ext="Line" Index="0">
            <Line Type="value" Event="1101" Name="AUTOP1">
                <Param type="13" srctype="4" data="AUTOP2" ext="Line" Index="0">
                    <Line Type="value" Event="1537" Name="AUTOP2">
                        <Param type="2" data="100" seltype="3" Index="0" />
                        <Param type="2" data="1" seltype="3" Index="1" />
                        <Param type="4" data="0" seltype="3" Index="2" />
                        <Param type="6" data="0safa" seltype="3" Index="3" />
                        <Param type="6" data="adfasfe" seltype="3" Index="4" />
                    </Line>
                </Param>
                <Param type="2" data="1" seltype="1" Index="1" />
                <Param type="4" data="1" seltype="3" Index="2" />
            </Line>
        </Param>
    </Condition>
    <Base>
        <Line Type="action" Event="5018">
            <Param type="6" data="-5749.970,79.728,5573.181,1.480" seltype="3" Index="0" />
            <Param type="6" data="npc_FB105_0015" seltype="3" Index="1" />
            <Param type="6" data="Act" seltype="-1" Index="2" />
        </Line>
        <Line Type="action" Event="5005">
            <Param type="2" data="0" seltype="1" Index="0" />
            <Param type="2" data="2" seltype="1" Index="1" />
            <Param type="6" data="talk_special_copy_FB_YGZM_016_1" seltype="6" Index="2" />
            <Param type="6" data=" " seltype="-1" Index="3" />
            <Param type="6" data=" " seltype="-1" Index="4" />
            <Param type="6" data=" " seltype="-1" Index="5" />
        </Line>
        <Line Type="action" Event="4528">
            <Param type="6" data="123131" seltype="3" Index="0" />
        </Line>
    </Base>
</Processor>
