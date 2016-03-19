--delete from nx_config where type=2;;
insert into nx_config values 
('mdf_monster_expratio','怪物经验倍率',2,'<Property><Ratio Type="1" >1</Ratio></Property>',1,NULL,NULL,NULL,NULL,0)
on duplicate key update status=1;;

insert into nx_config values 
('mdf_quest_exp_ratio','奖励包经验倍率',2,'<Property><Ratio Type="2" >1</Ratio></Property>',1,NULL,NULL,NULL,NULL,0)
on duplicate key update status=1;;

-- insert into nx_config values 
-- ('config_liveratio','Global Live Ratio',2,'<Property><Ratio Type="3" >1</Ratio></Property>',1,NULL,NULL,NULL,NULL,0);;

--delete from nx_config where type=4;;
--insert into nx_config  values 
--('config_newplaymail','新手邮件',4,
--'<Property>
--	<Topic>新手邮件</Topic>
--	<Sender>Liang717</Sender>
--	<Content><![CDATA[hello world!]]></Content>
--	<Gold></Gold>
--	<Items></Items>
--</Property>',0,NULL,NULL,NULL,NULL,0);;
