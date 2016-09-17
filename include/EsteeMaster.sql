/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

IF OBJECT_ID('EsteeMaster', 'U') IS NOT NULL
  DROP TABLE [EsteeMaster];
GO

CREATE TABLE [EsteeMaster] (
  [DataFeed_Ticker] VARCHAR(512) NOT NULL,
  [Underlying_Ticker] VARCHAR(512) NOT NULL,
  [ISIN] VARCHAR(512) NOT NULL,
  [Exchange_Code] VARCHAR(512) NOT NULL,
  [Option_Type] VARCHAR(512) NOT NULL,
  [Status] VARCHAR(512) NOT NULL,
  [TOKEN2] VARCHAR(512) NOT NULL,
  [Expiry_Date2] VARCHAR(512) NOT NULL,
  [SERIES] VARCHAR(512) NOT NULL,
  [Source] VARCHAR(512) NOT NULL,
  [UnderlyingEstee_Id] VARCHAR(512) NOT NULL,
  [Strike_Price] FLOAT NOT NULL,
  [Tick_Size] FLOAT NOT NULL,
  [Lot_Size] INT NOT NULL,
  [Security_Type] INT NOT NULL,
  [Token] INT NOT NULL,
  [Quote_Size] INT NOT NULL,
  [Instrument_Type] INT NOT NULL,
  [TradingCurrency] INT NOT NULL,
  [SettlementCurrency] INT NOT NULL,
  [TickSizeSlabId] INT NOT NULL,
  [AsOfDate] DATETIME NULL,
  [Last_update_time] DATETIME NULL,
  [Expiry_Date] DATETIME NULL,
  [SettlementDate] DATETIME NULL,
  [TradingStartDate] DATETIME NULL,
  [LastTradingDate] DATETIME NULL,
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [Estee_ID] VARCHAR(512) NOT NULL);
GO

