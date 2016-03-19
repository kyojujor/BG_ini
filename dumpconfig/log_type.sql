DROP TABLE IF EXISTS `log_enumtype`;;
CREATE TABLE `log_enumtype` (
  `type` int(11) NOT NULL DEFAULT '0',
  `desc` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;;

DROP TABLE IF EXISTS `log_enumvalue`;;
CREATE TABLE `log_enumvalue` (
  `type` int(11) NOT NULL,
  `value` varchar(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `text` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `desc` varchar(128) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`value`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;;
