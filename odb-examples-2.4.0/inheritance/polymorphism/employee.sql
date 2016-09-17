/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

IF OBJECT_ID('inh_poly_contractor', 'U') IS NOT NULL
  DROP TABLE [inh_poly_contractor];
GO

IF OBJECT_ID('inh_poly_employee', 'U') IS NOT NULL
  DROP TABLE [inh_poly_employee];
GO

IF OBJECT_ID('inh_poly_person', 'U') IS NOT NULL
  DROP TABLE [inh_poly_person];
GO

CREATE TABLE [inh_poly_person] (
  [id] BIGINT NOT NULL PRIMARY KEY IDENTITY,
  [typeid] VARCHAR(256) NOT NULL,
  [first] VARCHAR(512) NOT NULL,
  [last] VARCHAR(512) NOT NULL);
GO

CREATE TABLE [inh_poly_employee] (
  [id] BIGINT NOT NULL PRIMARY KEY,
  [temporary] BIT NOT NULL,
  CONSTRAINT [inh_poly_employee_id_fk]
    FOREIGN KEY ([id])
    REFERENCES [inh_poly_person] ([id])
    ON DELETE CASCADE);
GO

CREATE TABLE [inh_poly_contractor] (
  [id] BIGINT NOT NULL PRIMARY KEY,
  [email] VARCHAR(512) NOT NULL,
  CONSTRAINT [inh_poly_contractor_id_fk]
    FOREIGN KEY ([id])
    REFERENCES [inh_poly_person] ([id])
    ON DELETE CASCADE);
GO
