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
INSERT INTO `game_enum` VALUES ('Sex', '0', '男');;
INSERT INTO `game_enum` VALUES ('Sex', '1', '女');;
INSERT INTO `game_enum` VALUES ('Camp', '1', '蒸汽');;
INSERT INTO `game_enum` VALUES ('Camp', '2', '奇幻');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '0', '无公会');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '1', '会长');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '2', '副会长');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '3', '官员');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '4', '精英');;
INSERT INTO `game_enum` VALUES ('GuildPosition', '5', '会员');;
INSERT INTO `game_enum` VALUES ('GuildRelation', '1', '联盟');;
INSERT INTO `game_enum` VALUES ('GuildRelation', '2', '敌对');;
INSERT INTO `game_enum` VALUES ('Job', '1', '仲裁者');;
INSERT INTO `game_enum` VALUES ('Job', '2', '蒸汽学徒');;
INSERT INTO `game_enum` VALUES ('Job', '3', '秘法师');;
INSERT INTO `game_enum` VALUES ('Job', '4', '麦克骑士');;
INSERT INTO `game_enum` VALUES ('Job', '5', '野性守护者');;
INSERT INTO `game_enum` VALUES ('Job', '6', '猎魔人');;
INSERT INTO `game_enum` VALUES ('Job', '7', '炼金师');;
INSERT INTO `game_enum` VALUES ('Job', '8', '魔法师');;
INSERT INTO `game_enum` VALUES ('Job', '21', '惩罚者');;
INSERT INTO `game_enum` VALUES ('Job', '22', '神枪手');;
INSERT INTO `game_enum` VALUES ('Job', '23', '执行者');;
INSERT INTO `game_enum` VALUES ('Job', '24', '器械师');;
INSERT INTO `game_enum` VALUES ('Job', '25', '构造师');;
INSERT INTO `game_enum` VALUES ('Job', '26', '异教徒');;
INSERT INTO `game_enum` VALUES ('Job', '27', '咒术师');;
INSERT INTO `game_enum` VALUES ('Job', '28', '黑暗祭师');;
INSERT INTO `game_enum` VALUES ('Job', '29', '女巫');;
INSERT INTO `game_enum` VALUES ('Job', '30', '泰坦骑士');;
INSERT INTO `game_enum` VALUES ('Job', '31', '风暴骑士');;
INSERT INTO `game_enum` VALUES ('Job', '32', '破碎骑士');;
INSERT INTO `game_enum` VALUES ('Job', '33', '熊人');;
INSERT INTO `game_enum` VALUES ('Job', '34', '蛮牛人');;
INSERT INTO `game_enum` VALUES ('Job', '35', '狼人');;
INSERT INTO `game_enum` VALUES ('Job', '36', '刀锋战士');;
INSERT INTO `game_enum` VALUES ('Job', '37', '狩猎者');;
INSERT INTO `game_enum` VALUES ('Job', '38', '魔剑士');;
INSERT INTO `game_enum` VALUES ('Job', '39', '炼器师');;
INSERT INTO `game_enum` VALUES ('Job', '40', '医师');;
INSERT INTO `game_enum` VALUES ('Job', '41', '变能师');;
INSERT INTO `game_enum` VALUES ('Job', '42', '圣殿法师');;
INSERT INTO `game_enum` VALUES ('Job', '43', '流浪法师');;
INSERT INTO `game_enum` VALUES ('Job', '44', '平衡法师');;
INSERT INTO `game_enum` VALUES ('QuestCriteriaStatus', '1', '未完成(进行中)');;
INSERT INTO `game_enum` VALUES ('QuestCriteriaStatus', '2', '已完成');;
INSERT INTO `game_enum` VALUES ('QuestCriteriaStatus', '3', '失败');;
INSERT INTO `game_enum` VALUES ('QuestState', '1', '未完成(进行中)');;
INSERT INTO `game_enum` VALUES ('QuestState', '2', '可提交');;
INSERT INTO `game_enum` VALUES ('QuestState', '3', '失败');;
INSERT INTO `game_enum` VALUES ('QuestState', '4', '已奖励(已提交)');;
INSERT INTO `game_enum` VALUES ('Race', '1', '蒸汽人类');;
INSERT INTO `game_enum` VALUES ('Race', '2', '血族');;
INSERT INTO `game_enum` VALUES ('Race', '3', '矮人');;
INSERT INTO `game_enum` VALUES ('Race', '4', '奇幻人类');;
INSERT INTO `game_enum` VALUES ('Race', '5', '野蛮人');;
INSERT INTO `game_enum` VALUES ('Race', '6', '喀什');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '0', '无生活职业');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '1', '锻造');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '2', '精工');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '3', '炼金');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '4', '珠宝');;
INSERT INTO `game_enum` VALUES ('LifeOccupFirstType', '5', '铸甲');;
