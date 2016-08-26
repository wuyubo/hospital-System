CREATE DATABASE  IF NOT EXISTS `trsystem` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `trsystem`;
-- MySQL dump 10.13  Distrib 5.6.17, for Win64 (x86_64)
--
-- Host: localhost    Database: trsystem
-- ------------------------------------------------------
-- Server version	5.6.21-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `disease`
--

DROP TABLE IF EXISTS `disease`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `disease` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dname` varchar(30) NOT NULL DEFAULT '',
  `dtype` varchar(8) NOT NULL DEFAULT '外科',
  `drank` varchar(8) NOT NULL DEFAULT '一般严重',
  `dsymp` text NOT NULL,
  `ddesc` text,
  `dcount` int(11) DEFAULT NULL,
  `didate` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  FULLTEXT KEY `dname` (`dname`,`dsymp`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `disease`
--

LOCK TABLES `disease` WRITE;
/*!40000 ALTER TABLE `disease` DISABLE KEYS */;
INSERT INTO `disease` VALUES (13,'发烧','内科','非常严重','头痛，发热，流鼻涕','鞋柜 在',10,20150203),(14,'胃病','内科','一般严重','<胃病>肚子痛\n吃不消\n','吃太多了\n',0,20150203),(15,'牙痛','外科','一般严重','牙痛','蛀牙，上火',2,20150203),(17,'感冒','内科','较严重','<感冒>头痛，流鼻涕\n','感冒是病毒引起的',0,20150204);
/*!40000 ALTER TABLE `disease` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `doctorhis`
--

DROP TABLE IF EXISTS `doctorhis`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `doctorhis` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `did` char(10) NOT NULL DEFAULT '',
  `dname` varchar(20) NOT NULL DEFAULT '',
  `ddate` char(8) NOT NULL DEFAULT '20150101',
  `pid` varchar(18) NOT NULL DEFAULT '440982199303295753',
  `pname` varchar(20) NOT NULL DEFAULT '',
  `psex` char(2) NOT NULL DEFAULT '男',
  `pdname` varchar(30) NOT NULL DEFAULT '',
  `pdrank` varchar(8) NOT NULL DEFAULT '一般严重',
  `pdmedi` text,
  PRIMARY KEY (`id`),
  KEY `did` (`did`,`dname`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doctorhis`
--

LOCK TABLES `doctorhis` WRITE;
/*!40000 ALTER TABLE `doctorhis` DISABLE KEYS */;
INSERT INTO `doctorhis` VALUES (15,'3113001629','吴玉波','20150203','999999999999999999','需要','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(16,'3113001629','吴玉波','20150203','555555555555555555','搬了遥','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(17,'3113001629','吴玉波','20150203','555555555555555555','搬了遥','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(18,'3113001629','吴玉波','20150203','555555555555555555','搬了遥','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(19,'3113001629','吴玉波','20150203','555555555555555555','搬了遥','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(20,'3113001629','吴玉波','20150203','555555555555555555','搬了遥','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(21,'3113001629','吴玉波','20150203','888888888888888888','4','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(22,'3113001629','吴玉波','20150204','555555555555555555','搬了遥','男','牙痛','一般严重','一直在枯'),(23,'3113001629','吴玉波','20150204','555555555555555555','搬了遥','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(24,'3113001629','吴玉波','20150204','555555555555555555','搬了遥','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(25,'3113001629','吴玉波','20150204','555555555555555555','搬了遥','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(26,'3113001629','吴玉波','20150204','888888888888888888','4','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(27,'3113001629','吴玉波','20150204','888888888888888888','4','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(28,'3113001629','吴玉波','20150204','999999999999999999','需要','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(29,'3113001629','吴玉波','20150204','000000000000000000','0','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(30,'3113001629','吴玉波','20150204','000000000000000000','0','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(31,'3113001629','吴玉波','20150204','111111111111111111','11111','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(32,'3113001629','吴玉波','20150204','000000000000000000','0','男','感冒药','较严重','0001.睦地\n0003.发结\n0007.玩具'),(33,'3113001629','吴玉波','20150204','000000000000000000','0','男','发烧','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药'),(34,'3113001629','吴玉波','20150204','111111111111111111','11111','男','牙痛','一般严重','0007.止痛药');
/*!40000 ALTER TABLE `doctorhis` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `doctorinf`
--

DROP TABLE IF EXISTS `doctorinf`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `doctorinf` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `did` char(10) NOT NULL DEFAULT '',
  `dname` varchar(20) NOT NULL DEFAULT '',
  `dsex` varchar(2) NOT NULL DEFAULT '男',
  `dbirth` varchar(7) NOT NULL DEFAULT '1990/01',
  `dpost` varchar(10) NOT NULL DEFAULT '医生',
  `ddepart` varchar(10) NOT NULL DEFAULT '外科',
  `dright` varchar(3) NOT NULL DEFAULT 'no',
  `dresume` text,
  `dpasswa` varchar(6) NOT NULL DEFAULT '123456',
  `dcount` int(11) DEFAULT NULL,
  `didate` int(11) DEFAULT NULL,
  `dpay` int(11) DEFAULT NULL,
  `picdress` text,
  PRIMARY KEY (`id`),
  UNIQUE KEY `did` (`did`),
  KEY `did_2` (`did`,`dname`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doctorinf`
--

LOCK TABLES `doctorinf` WRITE;
/*!40000 ALTER TABLE `doctorinf` DISABLE KEYS */;
INSERT INTO `doctorinf` VALUES (4,'3113001619','缪志鹏','男','1993/01','主任','内科','no','广东工业大学','123456',0,20150201,8000,''),(5,'3113001629','吴玉波','男','1993/03','院长','全科','yes','2015.01任本院院长','123456',20,20150203,8000,''),(6,'3113001628','吴华艺','男','1994/01','副院长','妇科','yes','2015.02任本院副院长','123456',0,20150203,8000,'');
/*!40000 ALTER TABLE `doctorinf` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hungnum`
--

DROP TABLE IF EXISTS `hungnum`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hungnum` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `hnum` int(11) NOT NULL,
  `date` int(11) NOT NULL,
  `pid` varchar(18) NOT NULL DEFAULT '440982199303295753',
  `hret` varchar(3) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `date` (`date`,`pid`)
) ENGINE=InnoDB AUTO_INCREMENT=52 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hungnum`
--

LOCK TABLES `hungnum` WRITE;
/*!40000 ALTER TABLE `hungnum` DISABLE KEYS */;
INSERT INTO `hungnum` VALUES (22,1,20150201,'999999999999999999','no'),(23,2,20150201,'555555555555555555','no'),(24,1,20150201,'555555555555555555','no'),(25,2,20150201,'777777777777777777','no'),(26,1,20150201,'888888888888888888','no'),(27,1,20150202,'444444444444444444','no'),(28,2,20150202,'777777777788888888','no'),(29,1,20150202,'222222222233333333','no'),(30,4,20150202,'111111111122222222','no'),(31,5,20150202,'888888888888888888','no'),(32,6,20150202,'111111112222222222','no'),(33,7,20150202,'111111111122222222','no'),(34,8,20150202,'000000000000000000','no'),(35,9,20150202,'888888888888888888','no'),(36,10,20150202,'999999999999999999','no'),(37,1,20150202,'000000000000000000','no'),(38,2,20150202,'888888888888888888','no'),(39,13,20150202,'000000000000000000','no'),(40,14,20150202,'000000000000000000','no'),(41,15,20150202,'000000000000000000','no'),(42,16,20150202,'111111111111112222','no'),(43,17,20150202,'111111111111112222','no'),(44,18,20150202,'111111111111112222','no'),(45,19,20150202,'111111111111112222','no'),(46,1,20150203,'111111111111111111','no'),(47,2,20150203,'000000000000000000','no'),(48,3,20150203,'888888888888888888','no'),(49,1,20150204,'000000000000000000','no'),(50,2,20150204,'888888888888888888','no'),(51,3,20150204,'111111111111111111','no');
/*!40000 ALTER TABLE `hungnum` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `medicines`
--

DROP TABLE IF EXISTS `medicines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `medicines` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `mid` varchar(18) NOT NULL DEFAULT '',
  `mname` varchar(30) NOT NULL DEFAULT '',
  `mtype` varchar(8) NOT NULL DEFAULT '外科',
  `musage` varchar(8) NOT NULL DEFAULT '外用',
  `mdesc` text,
  `mprice` int(11) NOT NULL DEFAULT '1',
  `mcount` int(11) NOT NULL DEFAULT '100',
  `mecount` int(11) DEFAULT NULL,
  `midate` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `mid` (`mid`),
  KEY `mid_2` (`mid`,`mname`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `medicines`
--

LOCK TABLES `medicines` WRITE;
/*!40000 ALTER TABLE `medicines` DISABLE KEYS */;
INSERT INTO `medicines` VALUES (9,'0001','退烧药','内科','内服','',10,9999,0,20150204),(10,'0002','下火药','内科','内服','',5,10000,0,20150204),(11,'0003','消炎药','外科','外用','',15,9999,0,20150204),(12,'0004','眼药水','眼科','外用','',18,1000,0,20150204),(13,'0005','999感冒药','内科','内服','',2,10000,0,20150204),(14,'0006','板蓝根','外科','外用','',1,999,0,20150204),(15,'0007','止痛药','外科','可口服可外用','',30,99999,0,20150204),(16,'0009','胃药','内科','内服','',50,10000,0,20150204),(17,'0010','消化药','内科','内服','1',5,10000,0,20150204);
/*!40000 ALTER TABLE `medicines` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `patienthis`
--

DROP TABLE IF EXISTS `patienthis`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `patienthis` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(18) NOT NULL DEFAULT '440982199303295753',
  `pname` varchar(20) NOT NULL DEFAULT '',
  `ddate` char(8) NOT NULL DEFAULT '20150101',
  `pdname` varchar(30) NOT NULL DEFAULT '',
  `pdtype` varchar(8) NOT NULL DEFAULT '外科',
  `pdrank` varchar(8) NOT NULL DEFAULT '一般严重',
  `pdmedi` text NOT NULL,
  `dname` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`,`pname`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `patienthis`
--

LOCK TABLES `patienthis` WRITE;
/*!40000 ALTER TABLE `patienthis` DISABLE KEYS */;
INSERT INTO `patienthis` VALUES (4,'098765432112345678','顶替','20150201','12345','外科','一般严重','0002:2\n0001:1\n0004:在\n','1'),(5,'098765432112345678','顶替','20150201','12345','外科','一般严重','0002:2\n0001:1\n0004:在\n','1'),(6,'098765432112345678','顶替','20150201','在震天','外科','一般严重','0004:在\n0002:2\n0005:124322\n','1'),(7,'888888888888888888','4','20150201','十大震天 睛睛睚下 天二压下压下压下上压下于上直 下','外科','一般严重','1.:\n2.:\n3.:\n4.:\n5.:\n','1'),(8,'888888888888888888','4','20150201','在震天','外科','一般严重','0004:在\n0002:2\n0005:124322\n','1'),(9,'000000000000000000','0','20150202','在震天','外科','一般严重','0004:在\n0002:2\n0005:124322\n','11111'),(10,'111111111111112222','顶替工','20150202','十大震天 睛睛睚下 天二压下压下压下上压下于上直 下','外科','一般严重','1.:\n2.:\n3.:\n4.:\n5.:\n','11111'),(11,'111111111111112222','顶替工','20150202','在震天','外科','一般严重','0004:在\n0002:2\n0005:124322\n','11111'),(12,'111111111111112222','顶替工','20150202','在震天','外科','一般严重','0004:在\n0002:2\n0005:124322\n','11111'),(13,'999999999999999999','需要','20150203','在震天','外科','一般严重','0004:在\n0002:2\n0005:124322\n0003：是\n0001：申\n','11111'),(14,'999999999999999999','需要','20150203','发烧','内科','非常严重','0005.退烧药:\n0006.增强药:\n','11111'),(15,'999999999999999999','需要','20150203','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(16,'555555555555555555','搬了遥','20150203','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(17,'555555555555555555','搬了遥','20150203','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(18,'555555555555555555','搬了遥','20150203','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(19,'555555555555555555','搬了遥','20150203','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(20,'555555555555555555','搬了遥','20150203','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(21,'888888888888888888','4','20150203','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(22,'555555555555555555','搬了遥','20150204','牙痛','外科','一般严重','一直在枯','吴玉波'),(23,'555555555555555555','搬了遥','20150204','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(24,'555555555555555555','搬了遥','20150204','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(25,'555555555555555555','搬了遥','20150204','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(26,'888888888888888888','4','20150204','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(27,'888888888888888888','4','20150204','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(28,'999999999999999999','需要','20150204','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(29,'000000000000000000','0','20150204','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(30,'000000000000000000','0','20150204','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(31,'111111111111111111','11111','20150204','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(32,'000000000000000000','0','20150204','感冒药','内科','较严重','0001.睦地\n0003.发结\n0007.玩具','吴玉波'),(33,'000000000000000000','0','20150204','发烧','内科','非常严重','0005.退烧药\n0006.增强药\n0003.开挂药','吴玉波'),(34,'111111111111111111','11111','20150204','牙痛','外科','一般严重','0007.止痛药','吴玉波');
/*!40000 ALTER TABLE `patienthis` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `patientinf`
--

DROP TABLE IF EXISTS `patientinf`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `patientinf` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` varchar(18) NOT NULL DEFAULT '440982199303295753',
  `pname` varchar(20) NOT NULL DEFAULT '',
  `psex` char(2) NOT NULL DEFAULT '男',
  `pbirth` char(7) NOT NULL DEFAULT '1990/01',
  `pdrug` text,
  `pihis` text,
  `pvip` varchar(6) DEFAULT '非会员',
  `pcount` int(11) DEFAULT NULL,
  `pidate` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`,`pname`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `patientinf`
--

LOCK TABLES `patientinf` WRITE;
/*!40000 ALTER TABLE `patientinf` DISABLE KEYS */;
INSERT INTO `patientinf` VALUES (8,'000000000000000000','0','男','1999/03','0','0','no',15,20150201),(9,'123456781234567890','1','男','1999/03','1','1','no',2,20150201),(10,'098765432112345678','顶替','男','1999/03','村','村','no',4,20150201),(11,'444444444444444444','4','男','1999/03','4','4','no',0,20150201),(12,'888888888888888888','4','男','1999/03','4','4','no',5,20150201),(13,'999999999999999999','需要','男','1999/03','睛','于','no',4,20150201),(14,'555555555555555555','搬了遥','男','1999/03','夺城一',' 夺','no',9,20150201),(15,'777777777777777777','奇才','男','1999/03',' 地','','no',0,20150201),(16,'777777777788888888','原','男','1999/03','顶替','夺','no',0,20150202),(17,'222222222233333333','要奇才','男','1999/03','大规模','标有','no',0,20150202),(18,'111111111122222222','需要奇才','男','1999/03','枯棋','械','no',0,20150202),(19,'111111112222222222','肛械','男','1999/03','奇才','顶替','no',0,20150202),(20,'111111111111112222','顶替工','男','1999/03','枯','','no',3,20150202),(21,'111111111111111111','11111','男','1999/03','械左','夺','no',2,20150203);
/*!40000 ALTER TABLE `patientinf` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `trprojects`
--

DROP TABLE IF EXISTS `trprojects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `trprojects` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tdname` varchar(30) NOT NULL DEFAULT '',
  `tdtype` varchar(8) NOT NULL DEFAULT '外科',
  `tdrank` varchar(8) NOT NULL DEFAULT '一般严重',
  `tdmedi` text NOT NULL,
  `tsugg` text,
  PRIMARY KEY (`id`),
  KEY `tdname` (`tdname`,`tdtype`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `trprojects`
--

LOCK TABLES `trprojects` WRITE;
/*!40000 ALTER TABLE `trprojects` DISABLE KEYS */;
INSERT INTO `trprojects` VALUES (1,'感冒','内科','较严重','0005.999感冒药\n 0006.板蓝根','多喝水'),(2,'发烧','外科','一般严重','0001.退烧药\n0002.下火药','多喝开水'),(3,'1','外科','一般严重','1.001\n\n','1'),(4,'123','外科','一般严重','1.0\n2.1\n3.2\n4.4\n5.3\n','1'),(6,'463','外科','一般严重','1.\n2.\n3.\n4.\n5.\n',''),(15,'发烧','内科','非常严重','0001.退烧药\n0002.下火药','多喝开水'),(16,'胃病','内科','一般严重','0009.胃药\n0010.消化药','多吃饭'),(17,'牙痛','外科','一般严重','0007.止痛药','把蛀牙拔了'),(19,'感冒','内科','较严重','0005.999感冒药\n 0006.板蓝根','多喝水');
/*!40000 ALTER TABLE `trprojects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'trsystem'
--

--
-- Dumping routines for database 'trsystem'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-02-04 20:41:04
