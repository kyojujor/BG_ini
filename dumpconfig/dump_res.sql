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

insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('1','����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('5','����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('7','����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('8','����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('10','PVP����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('14','NPCת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('15','��̬���ݰ�ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('17','�����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('19','�����ת��',0,'',1,NULL,NULL,NULL,NULL,NULL);;

insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType0','�ڽ�',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType1','���',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType2','��ȯ',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType3','��Դ',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType4','��ɱ����',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType5','ն������ѫ��',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType6','Ӣ�µ���',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType7','���ṱ�׵�',1,'',2,NULL,NULL,NULL,NULL,NULL);;
insert into nx_res_dumpinfo(id,name,type,property,status,op_name,op_type,op_property,op_status,op_version) values ('CapitalType8','���������׵�',1,'',2,NULL,NULL,NULL,NULL,NULL);;
