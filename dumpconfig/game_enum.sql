-- ----------------------------
-- Table structure for `game_enum`
-- ----------------------------
DROP TABLE IF EXISTS `game_enum`;;
CREATE TABLE `game_enum` (
  `name` varchar(32) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `value` int(11) NOT NULL,
  `desc` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`name`,`value`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;;

-- ----------------------------
-- Records of game_enum
-- ----------------------------
INSERT INTO `game_enum` VALUES ('Sex', '0', '��');;
INSERT INTO `game_enum` VALUES ('Sex', '1', 'Ů');;
INSERT INTO `game_enum` VALUES ('Camp', '1', '����');;
INSERT INTO `game_enum` VALUES ('Camp', '2', '���');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '0', '�޹���');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '1', '�᳤');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '2', '���᳤');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '3', '��Ա');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '4', '��Ӣ');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '5', '��Ա');;
INSERT INTO `game_enum` VALUES ('GuildRelation', '1', '����');;
INSERT INTO `game_enum` VALUES ('GuildRelation', '2', '�ж�');;
INSERT INTO `game_enum` VALUES ('Job', '1', '�ٲ���');;
INSERT INTO `game_enum` VALUES ('Job', '2', '����ѧͽ');;
INSERT INTO `game_enum` VALUES ('Job', '3', '�ط�ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '4', '�����ʿ');;
INSERT INTO `game_enum` VALUES ('Job', '5', 'Ұ���ػ���');;
INSERT INTO `game_enum` VALUES ('Job', '6', '��ħ��');;
INSERT INTO `game_enum` VALUES ('Job', '7', '����ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '8', 'ħ��ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '21', '�ͷ���');;
INSERT INTO `game_enum` VALUES ('Job', '22', '��ǹ��');;
INSERT INTO `game_enum` VALUES ('Job', '23', 'ִ����');;
INSERT INTO `game_enum` VALUES ('Job', '24', '��еʦ');;
INSERT INTO `game_enum` VALUES ('Job', '25', '����ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '26', '���ͽ');;
INSERT INTO `game_enum` VALUES ('Job', '27', '����ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '28', '�ڰ���ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '29', 'Ů��');;
INSERT INTO `game_enum` VALUES ('Job', '30', '̩̹��ʿ');;
INSERT INTO `game_enum` VALUES ('Job', '31', '�籩��ʿ');;
INSERT INTO `game_enum` VALUES ('Job', '32', '������ʿ');;
INSERT INTO `game_enum` VALUES ('Job', '33', '����');;
INSERT INTO `game_enum` VALUES ('Job', '34', '��ţ��');;
INSERT INTO `game_enum` VALUES ('Job', '35', '����');;
INSERT INTO `game_enum` VALUES ('Job', '36', '����սʿ');;
INSERT INTO `game_enum` VALUES ('Job', '37', '������');;
INSERT INTO `game_enum` VALUES ('Job', '38', 'ħ��ʿ');;
INSERT INTO `game_enum` VALUES ('Job', '39', '����ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '40', 'ҽʦ');;
INSERT INTO `game_enum` VALUES ('Job', '41', '����ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '42', 'ʥ�ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '43', '���˷�ʦ');;
INSERT INTO `game_enum` VALUES ('Job', '44', 'ƽ�ⷨʦ');;
INSERT INTO `game_enum` VALUES ('QuestCriteriaStatus', '1', 'δ���(������)');;
INSERT INTO `game_enum` VALUES ('QuestCriteriaStatus', '2', '�����');;
INSERT INTO `game_enum` VALUES ('QuestCriteriaStatus', '3', 'ʧ��');;
INSERT INTO `game_enum` VALUES ('QuestState', '1', 'δ���(������)');;
INSERT INTO `game_enum` VALUES ('QuestState', '2', '���ύ');;
INSERT INTO `game_enum` VALUES ('QuestState', '3', 'ʧ��');;
INSERT INTO `game_enum` VALUES ('QuestState', '4', '�ѽ���(���ύ)');;
INSERT INTO `game_enum` VALUES ('Race', '1', '��������');;
INSERT INTO `game_enum` VALUES ('Race', '2', 'Ѫ��');;
INSERT INTO `game_enum` VALUES ('Race', '3', '����');;
INSERT INTO `game_enum` VALUES ('Race', '4', '�������');;
INSERT INTO `game_enum` VALUES ('Race', '5', 'Ұ����');;
INSERT INTO `game_enum` VALUES ('Race', '6', '��ʲ');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '0', '������ְҵ');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '1', '����');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '2', '����');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '3', '����');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '4', '�鱦');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '5', '����');;
