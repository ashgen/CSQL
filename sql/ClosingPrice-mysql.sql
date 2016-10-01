/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `closingPrice`;

CREATE TABLE `closingPrice` (
  `Open_Interest` DOUBLE NOT NULL,
  `Settlement_price` DOUBLE NOT NULL,
  `Open_Price` DOUBLE NOT NULL,
  `High_Price` DOUBLE NOT NULL,
  `Low_Price` DOUBLE NOT NULL,
  `Close_Price` DOUBLE NOT NULL,
  `Volume` DOUBLE NOT NULL,
  `Net_Traded_Val` DOUBLE NOT NULL,
  `Trades` INT NOT NULL,
  `Source` TEXT NOT NULL,
  `Date` DATETIME NOT NULL,
  `Estee_ID` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`Date`,
               `Estee_ID`))
 ENGINE=InnoDB;
