/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

IF OBJECT_ID('query_person', 'U') IS NOT NULL
  DROP TABLE [query_person];
GO

CREATE TABLE [query_person] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [first] VARCHAR(512) NOT NULL,
  [middle] VARCHAR(512) NULL,
  [last] VARCHAR(512) NOT NULL,
  [age] SMALLINT NOT NULL);
GO

