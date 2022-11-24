-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: bankdb
-- ------------------------------------------------------
-- Server version	8.0.29

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `idaccount` int NOT NULL AUTO_INCREMENT,
  `owner` int NOT NULL,
  `cardnum` varchar(20) NOT NULL,
  `balance` decimal(19,4) DEFAULT NULL,
  `credit` decimal(19,4) DEFAULT NULL,
  PRIMARY KEY (`idaccount`),
  UNIQUE KEY `idaccount_UNIQUE` (`idaccount`),
  KEY `card_idx` (`cardnum`),
  CONSTRAINT `card` FOREIGN KEY (`cardnum`) REFERENCES `card` (`cardnum`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=15232 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (15212,1111111,'27858',193.0000,0.0000),(15213,1111111,'63007',1659.0000,0.0000),(15214,1111111,'72996',25.0000,0.0000),(15215,1111111,'93993',15256.0000,0.0000),(15216,1111111,'61773',95644.0000,0.0000),(15217,1111111,'97529',16093.0000,0.0000),(15218,1111111,'43637',112.0000,0.0000),(15219,1111111,'53299',99.0000,0.0000),(15220,1111111,'39904',0.0000,8300.0000),(15221,1111111,'88537',0.0000,756.0000),(15222,1111111,'96590',0.0000,1000.0000),(15223,1111111,'10926',0.0000,5000.0000),(15224,1111111,'88954',0.0000,1000.0000),(15225,1111111,'97414',0.0000,546.0000),(15226,1111111,'14390',0.0000,12.0000),(15227,1111111,'65276',0.0000,10000.0000),(15228,1111111,'31640',163.0000,0.0000),(15229,1111111,'46258',16474.0000,0.0000),(15230,1111111,'79953',7845.0000,0.0000),(15231,1111111,'96984',256.0000,0.0000);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `banklog` AFTER UPDATE ON `account` FOR EACH ROW BEGIN
IF (old.balance<new.balance) THEN
INSERT INTO log VALUES(NULL,NEW.idaccount,new.balance-old.balance,now(),'deposit_DBT');

ELSE IF (old.balance>new.balance) THEN
INSERT INTO log VALUES(NULL,NEW.idaccount,old.balance-new.balance,now(),'withdrawal_DBT');

ELSE 
INSERT INTO log VALUES(NULL,NEW.idaccount,'0',now(),'dbError');

END IF;
END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `cardnum` varchar(20) NOT NULL,
  `cardpin` varchar(255) NOT NULL,
  `iduser` int NOT NULL,
  `iscredit` tinyint(1) NOT NULL,
  `islocked` tinyint(1) DEFAULT NULL,
  `pin_tries` tinyint DEFAULT NULL,
  PRIMARY KEY (`cardnum`),
  UNIQUE KEY `cardnum_UNIQUE` (`cardnum`),
  KEY `user_idx` (`iduser`),
  CONSTRAINT `user` FOREIGN KEY (`iduser`) REFERENCES `user` (`iduser`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES ('10926','1673',5,1,0,0),('14390','8342',8,1,0,0),('27858','1568',2,0,0,0),('31640','2371',10,0,0,0),('39904','2341',13,1,0,0),('43637','8146',7,0,0,0),('46258','2960',11,0,0,0),('53299','9782',8,0,0,0),('61773','4767',6,0,0,0),('63007','5801',2,0,0,0),('65276','8677',9,1,0,0),('72996','8214',3,0,0,0),('79953','5509',12,0,0,0),('88537','3192',9,1,0,0),('88954','8367',7,1,0,0),('93993','6715',4,0,0,0),('96590','6781',1,1,0,0),('96984','9876',14,0,0,0),('97414','8024',7,1,0,0),('97529','9886',6,0,0,0);
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `log`
--

DROP TABLE IF EXISTS `log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `log` (
  `idlog` int NOT NULL AUTO_INCREMENT,
  `idaccount` int NOT NULL,
  `withdraw_amount` decimal(16,4) DEFAULT NULL,
  `transaction_time` datetime DEFAULT NULL,
  `transaction_type` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`idlog`),
  KEY `idaccount_idx` (`idaccount`),
  CONSTRAINT `idaccount` FOREIGN KEY (`idaccount`) REFERENCES `account` (`idaccount`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `log`
--

LOCK TABLES `log` WRITE;
/*!40000 ALTER TABLE `log` DISABLE KEYS */;
INSERT INTO `log` VALUES (1,15212,100.0000,'2022-11-17 16:32:14',NULL),(2,15212,100.0000,'2022-11-17 16:32:49',NULL),(3,15212,100.0000,'2022-11-17 17:22:13',NULL),(4,15220,100.0000,'2022-11-17 17:22:35',NULL),(5,15222,1000.0000,'2022-11-17 17:22:48',NULL),(6,15212,500.0000,'2022-11-24 14:06:05',NULL),(7,15212,500.0000,'2022-11-24 16:15:30',NULL),(8,15216,600.0000,'2022-11-24 19:41:01',NULL),(9,15212,50.0000,'2022-11-24 20:43:02','withdrawal_DBT');
/*!40000 ALTER TABLE `log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `iduser` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(20) NOT NULL,
  `lname` varchar(20) NOT NULL,
  PRIMARY KEY (`iduser`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'Matti','Näsä'),(2,'Juha','Koistinen'),(3,'Mauno','Ahonen'),(4,'Pertti','Keinonen'),(5,'Sakari','Östermalm'),(6,'Esko','Mörkö'),(7,'Gerhard','Rihmakallo'),(8,'Kalervo','Jankko'),(9,'Maxwell','Gothenburg'),(10,'Elmeri','Hautamäki'),(11,'Dean','Kagelberg'),(12,'James','Kagelberg'),(13,'Raili','Rasinkangas'),(14,'Eugen','von Lahtinen');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'bankdb'
--
/*!50003 DROP PROCEDURE IF EXISTS `event_log` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `event_log`(IN account_number INT)
BEGIN 
SELECT * FROM bankdb.log WHERE idaccount=account_number ORDER BY transaction_time DESC LIMIT 100;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `transaction` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `transaction`(IN transfer_account INT,IN amount INT)
BEGIN 
DECLARE test1 INT default 0;
UPDATE account SET balance=balance-amount WHERE 
(idaccount=transfer_account AND balance>=amount) 
OR (idaccount=transfer_account AND credit<=balance-amount);
SET test1=ROW_COUNT();
IF (test1 > 0) THEN
COMMIT;
select balance from account where idaccount=transfer_account;
    ELSE
      ROLLBACK;
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-11-24 20:49:42
