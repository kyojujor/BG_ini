--delete from nx_config where type=2;;
insert into nx_config values 
('mdf_monster_expratio','���ﾭ�鱶��',2,'<Property><Ratio Type="1" >1</Ratio></Property>',1,NULL,NULL,NULL,NULL,0)
on duplicate key update status=1;;

insert into nx_config values 
('mdf_quest_exp_ratio','���������鱶��',2,'<Property><Ratio Type="2" >1</Ratio></Property>',1,NULL,NULL,NULL,NULL,0)
on duplicate key update status=1;;

-- insert into nx_config values 
-- ('config_liveratio','Global Live Ratio',2,'<Property><Ratio Type="3" >1</Ratio></Property>',1,NULL,NULL,NULL,NULL,0);;

--delete from nx_config where type=4;;
--insert into nx_config  values 
--('config_newplaymail','�����ʼ�',4,
--'<Property>
--	<Topic>�����ʼ�</Topic>
--	<Sender>Liang717</Sender>
--	<Content><![CDATA[hello world!]]></Content>
--	<Gold></Gold>
--	<Items></Items>
--</Property>',0,NULL,NULL,NULL,NULL,0);;
