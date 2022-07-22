CREATE TABLE Product (ID INTEGER NOT NULL UNIQUE, Name TEXT, Calories INTEGER, PRIMARY KEY(ID AUTOINCREMENT));
CREATE TABLE Day(ID INTEGER NOT NULL UNIQUE, ProductListId INTEGER NOT NULL , date_day TEXT NOT NULL UNIQUE,PRIMARY KEY(ID AUTOINCREMENT));
CREATE TABLE ProductSave(ID INTEGER NOT NULL UNIQUE, Lid INTEGER NOT NULL ,ProductName TEXT,Calories INTEGER,PRIMARY KEY(ID AUTOINCREMENT));


