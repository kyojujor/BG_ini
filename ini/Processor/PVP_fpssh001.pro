<?xml version="1.0" encoding="gb2312" standalone="yes" ?>
<Processor>
    <Info Type="Source" Version="2.0" IsLua="0">
        <FileProperty>
            <Property 描述="" />
        </FileProperty>
        <Wizzard Desc="" />
        <Objects />
        <RefFiles />
        <TextIdSeed Seed="0" />
        <Triggers>
            <Trigger Event="4" />
        </Triggers>
    </Info>
    <Variable />
    <Condition />
    <Base>
        <Line Type="condition">
            <Line Type="if">
                <Param bool="true" type="13" srctype="1" data="AUTOP1" ext="Line" Index="0">
                    <Line Type="value" Event="1101" Name="AUTOP1">
                        <Param type="13" srctype="4" data="AUTOP2" ext="Line" Index="0">
                            <Line Type="value" Event="3204" Name="AUTOP2">
                                <Param type="13" srctype="8" data="AUTOP3" ext="Line" Index="0">
                                    <Line Type="value" Event="2001" Name="AUTOP3" />
                                </Param>
                                <Param type="6" data="HP" seltype="1" Index="1" />
                            </Line>
                        </Param>
                        <Param type="2" data="5" seltype="1" Index="1" />
                        <Param type="13" srctype="4" data="AUTOP4" ext="Line" Index="2">
                            <Line Type="value" Event="5075" Name="AUTOP4">
                                <Param type="4" data="0.3" seltype="3" Index="0" />
                                <Param type="2" data="3" seltype="1" Index="1" />
                                <Param type="13" srctype="4" data="AUTOP5" ext="Line" Index="2">
                                    <Line Type="value" Event="3204" Name="AUTOP5">
                                        <Param type="13" srctype="8" data="AUTOP6" ext="Line" Index="0">
                                            <Line Type="value" Event="2001" Name="AUTOP6" />
                                        </Param>
                                        <Param type="6" data="MaxHP" seltype="1" Index="1" />
                                    </Line>
                                </Param>
                            </Line>
                        </Param>
                    </Line>
                </Param>
            </Line>
            <Line Type="then">
                <Line Type="condition">
                    <Line Type="if">
                        <Param bool="true" type="13" srctype="1" data="AUTOP7" ext="Line" Index="0">
                            <Line Type="value" Event="1101" Name="AUTOP7">
                                <Param type="13" srctype="4" data="AUTOP8" ext="Line" Index="0">
                                    <Line Type="value" Event="1537" Name="AUTOP8">
                                        <Param type="2" data="100" seltype="3" Index="0" />
                                        <Param type="2" data="1" seltype="3" Index="1" />
                                        <Param type="4" data="-1" seltype="3" Index="2" />
                                        <Param type="6" data="jyx05" seltype="3" Index="3" />
                                        <Param type="6" data="jyx05" seltype="3" Index="4" />
                                    </Line>
                                </Param>
                                <Param type="2" data="1" seltype="1" Index="1" />
                                <Param type="4" data="1" seltype="3" Index="2" />
                            </Line>
                        </Param>
                    </Line>
                    <Line Type="then">
                        <Line Type="action" Event="4517">
                            <Param type="13" srctype="8" data="AUTOP9" ext="Line" Index="0">
                                <Line Type="value" Event="2001" Name="AUTOP9" />
                            </Param>
                            <Param type="6" data="BG_fpssh_001" seltype="3" Index="1" />
                        </Line>
                    </Line>
                    <Line Type="else" />
                </Line>
            </Line>
            <Line Type="else" />
        </Line>
    </Base>
</Processor>
