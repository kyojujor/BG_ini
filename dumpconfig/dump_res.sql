DROP TABLE IF EXISTS `nx_res_dumpinfo`;;
CREATE TABLE `nx_res_dumpinfo` (
  `id` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `name` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `type` int(11) DEFAULT NULL,
  `property` varchar(16384) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  `op_name` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `op_type` int(11) DEFAULT NULL,
  `op_property` longtext CHARACTER SET utf8 COLLATE utf8_bin,
  `op_status` int(11) DEFAULT NULL,
  `op_version` int(11) DEFAULT NULL,
  `key_id` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`key_id`),
  KEY `IX_id_1` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;;

insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('1','道具转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('5','任务转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('7','场景转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('8','技能转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('10','PVP任务转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('14','NPC转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('15','静态数据包转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('17','掉落包转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('19','复活点转储',0,'',1,NULL,NULL,NULL,NULL,NULL);;

insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType0','黑金',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType1','金币',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType2','点券',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType3','本源',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType4','猎杀点数',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType5','斩首荣誉勋章',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType6','英勇点数',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType7','公会贡献点',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType8','能量井贡献点',1,'',2,NULL,NULL,NULL,NULL,NULL);;
