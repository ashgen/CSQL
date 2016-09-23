CREATE TABLE [closingPrice] (
[Estee_ID] VARCHAR(256) NOT NULL,
  [Date] DATETIME NOT NULL,  
[Open_Interest] FLOAT NOT NULL,
  [Settlement_price] FLOAT NOT NULL,
  [Open_Price] FLOAT NOT NULL,
  [High_Price] FLOAT NOT NULL,
  [Low_Price] FLOAT NOT NULL,
  [Close_Price] FLOAT NOT NULL,
  [Volume] FLOAT NOT NULL,
  [Net_Traded_Val] FLOAT NOT NULL,
  [Trades] INT NOT NULL,
  [Source] VARCHAR(512) NOT NULL,

  PRIMARY KEY ([Date],
               [Estee_ID]));
select count(*) from closingPrice
