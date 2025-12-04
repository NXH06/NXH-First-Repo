-- remember: it's possible to run the code by blocks!
DROP DATABASE IF EXISTS Company; -- so that code can be rerun multiple times (for testing purposes)
-- 1, 2
CREATE DATABASE IF NOT EXISTS Company;
USE Company;
-- 3
CREATE TABLE Employee (
    Fname VARCHAR(20),
    Minit CHAR(1),
    Lname VARCHAR(20),
    Ssn CHAR(9),
    Bdate DATE,
    Address VARCHAR(50),
    Sex CHAR(1)
    CHECK (Sex = "M" OR Sex = "F"),
    Salary INT,
    Super_ssn CHAR(9),
    Dno INT DEFAULT 0,
    PRIMARY KEY (Ssn),
    FOREIGN KEY (Super_ssn) REFERENCES Employee(Ssn)
);
CREATE TABLE Department (
    Dname VARCHAR(20) NOT NULL,
    Dnumber INT DEFAULT 0,
    Mgr_ssn CHAR(9),
    Mgr_start_date DATE,
    PRIMARY KEY (Dnumber),
    UNIQUE (Dname),
    -- since there is a circular foreign key reference, constraints are named so they can be dropped later
    CONSTRAINT Department_ssn
    FOREIGN KEY (Mgr_ssn) REFERENCES Employee(Ssn)
);
ALTER TABLE Employee
ADD CONSTRAINT Employee_dno
FOREIGN KEY (Dno) REFERENCES Department(Dnumber);
CREATE TABLE Dept_locations (
    Dnumber INT DEFAULT 0
    CHECK (Dnumber >= 0 AND Dnumber <= 99),
    Dlocation VARCHAR(50),
    PRIMARY KEY (Dnumber, Dlocation),
    FOREIGN KEY (Dnumber) REFERENCES Department(Dnumber)
);
CREATE TABLE Project (
    Pname VARCHAR(50),
    Pnumber INT,
    Plocation VARCHAR(50),
    Dnum INT,
    PRIMARY KEY (Pnumber),
    FOREIGN KEY (Dnum) REFERENCES Department(Dnumber)
);
CREATE TABLE Works_on (
    Essn CHAR(9),
    Pno INT,
    Hours INT
    CHECK (Hours >= 1 AND Hours <= 56),
    PRIMARY KEY (Essn, Pno),
    FOREIGN KEY (Essn) REFERENCES Employee(Ssn),
    FOREIGN KEY (Pno) REFERENCES Project(Pnumber)
);
CREATE TABLE Dependent (
    Essn CHAR(9) NOT NULL DEFAULT "000000000", -- default value of primary key cannot be NULL
    Dependent_name VARCHAR(20) NOT NULL DEFAULT "Unknown",
    Sex CHAR(1),
    Bdate DATE,
    Relationship VARCHAR(10),
    PRIMARY KEY (Essn, Dependent_name),
    FOREIGN KEY (Essn) REFERENCES Employee(Ssn)
);
-- 4
ALTER TABLE Employee
ADD COLUMN Partner_ssn CHAR(9); -- default is already set to NULL... by default
-- 5: if columns not stated explicitly, insert into all columns
INSERT INTO Department
VALUES
("Adults", 18, NULL, "2025-11-19"),
("Children", 17, NULL, NULL);
INSERT INTO Employee
VALUES
("Hien", "X", "Nguyen", "123456789", "2006-02-24", "Ha Noi", "M", 1000, NULL, NULL, NULL),
("Khoa", "M", "Tran Thi", "333444555", "1980-05-11", "Nghe An", "F", 2000, "123456789", NULL, NULL),
("Mai", "H", "Nguyen", "101010101", "2009-08-23", "Ha Noi", "F", 400, "123456789", NULL, NULL);
UPDATE Department
SET Mgr_ssn = "123456789" WHERE Dnumber = 18;
UPDATE Employee
SET Dno = 18 WHERE Ssn = "123456789";
UPDATE Employee
SET Dno = 18 WHERE Ssn = "333444555";
UPDATE Employee
SET Dno = 17 WHERE Ssn = "101010101";
INSERT INTO Dept_locations
SELECT Dnumber, "Ha Noi" FROM Department;
INSERT INTO Project (Pname, Pnumber, Plocation, Dnum)
SELECT "Grown-up business", 1, "Ha Noi", Dnumber
FROM Department
WHERE Dnumber = 18;
INSERT INTO Project (Pname, Pnumber, Plocation, Dnum)
SELECT "Child's play", 0, "Ha Noi", Dnumber
FROM Department
WHERE Dnumber = 17;
INSERT INTO Works_on
VALUES
("123456789", 1, 30),
("333444555", 1, 40),
("101010101", 0, 10);
INSERT INTO Dependent
VALUES
("123456789", "Sun", "F", "2019-01-01", "Pet"),
("333444555", "Nobody", NULL, NULL, NULL),
("101010101", "Moon", "M", "2020-01-01", "Pet");
-- show work!
SELECT * FROM Employee;
SELECT * FROM Department;
SELECT * FROM Dept_locations;
SELECT * FROM Project;
SELECT * FROM Works_on;
SELECT * FROM Dependent;
/* note: if the above code is run in VSCode instead of MySQL Workbench or command-line,
it may need to be run seperately from the previous code to actually be able to show results. */
-- 6: due to foreign key constraints, tables are dropped in reverse order
ALTER TABLE Department DROP FOREIGN KEY Department_ssn;
ALTER TABLE Employee DROP FOREIGN KEY Employee_dno;
DROP TABLE IF EXISTS Dependent;
DROP TABLE IF EXISTS Works_on;
DROP TABLE IF EXISTS Project;
DROP TABLE IF EXISTS Dept_locations;
DROP TABLE IF EXISTS Department;
DROP TABLE IF EXISTS Employee;
