# DBMS Lab Internal — Complete Answers & Revision Guide

> **Scope:** All 10 experiments and their subquestions from the supplied **DBMS Lab Internal Question Paper** (3 pages).  
> **SQL dialect:** Oracle SQL (including Oracle materialized views, `MINUS`, `DUAL`, and `TO_DATE`).  
> **Exam method:** Read the **Idea**, practice the **SQL**, then revise the **Remember** line.  
> **Important:** Run each experiment **separately**. Some use the same table names with different columns. Do not execute all experiments in one shared schema without renaming/recreating those tables.
>
> Get Oracle10g.exe from [here](https://adityagroup-my.sharepoint.com/:u:/g/personal/25b11ds190_adityauniversity_in/IQCHlMTn8svaTJv08O6BrD0qAZ2WJvZsQjqBFXPhKE1Mqdc?e=FMSYlb)
---

# 1. University Database — Schema Creation and SQL Queries

## 1(a) Create the University database tables

**Idea:** A **primary key (PK)** uniquely identifies a row; a **foreign key (FK)** links a row to another table.

The question paper specifies these tables and columns:

| Table | Columns |
|---|---|
| Department | DeptID, DeptName, Location |
| Faculty | FacultyID, FacultyName, DeptID, Email |
| Student | StudentID, StudentName, DOB, DeptID, Email |
| Course | CourseID, CourseName, DeptID, Credits |
| Enrollment | EnrollmentID, StudentID, CourseID, Semester, Grade |

```sql
CREATE TABLE Department (
    DeptID NUMBER PRIMARY KEY,
    DeptName VARCHAR2(50) NOT NULL,
    Location VARCHAR2(50)
);

CREATE TABLE Faculty (
    FacultyID NUMBER PRIMARY KEY,
    FacultyName VARCHAR2(50) NOT NULL,
    DeptID NUMBER,
    Email VARCHAR2(100),
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

CREATE TABLE Student (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(50) NOT NULL,
    DOB DATE,
    DeptID NUMBER,
    Email VARCHAR2(100),
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

CREATE TABLE Course (
    CourseID NUMBER PRIMARY KEY,
    CourseName VARCHAR2(100) NOT NULL,
    DeptID NUMBER,
    Credits NUMBER,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

CREATE TABLE Enrollment (
    EnrollmentID NUMBER PRIMARY KEY,
    StudentID NUMBER,
    CourseID NUMBER,
    Semester VARCHAR2(20),
    Grade VARCHAR2(5),
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);
```

### Sample records (run in this order)

```sql
INSERT INTO Department VALUES (1, 'Computer Science', 'Block A');
INSERT INTO Department VALUES (2, 'Electronics', 'Block B');

INSERT INTO Faculty VALUES (101, 'Dr. Kumar', 1, 'kumar@uni.edu');
INSERT INTO Faculty VALUES (102, 'Dr. Meena', 2, 'meena@uni.edu');

INSERT INTO Student VALUES
(1, 'Alice', TO_DATE('2005-04-12', 'YYYY-MM-DD'), 1, 'alice@uni.edu');
INSERT INTO Student VALUES
(2, 'Bob', TO_DATE('2005-09-21', 'YYYY-MM-DD'), 2, 'bob@uni.edu');
INSERT INTO Student VALUES
(3, 'Charlie', TO_DATE('2004-11-05', 'YYYY-MM-DD'), 1, 'charlie@uni.edu');

INSERT INTO Course VALUES (10, 'DBMS', 1, 4);
INSERT INTO Course VALUES (20, 'Circuits', 2, 3);

INSERT INTO Enrollment VALUES (1001, 1, 10, 'III', 'A');
INSERT INTO Enrollment VALUES (1002, 3, 10, 'III', 'B');
INSERT INTO Enrollment VALUES (1003, 2, 20, 'III', 'A');

COMMIT;
```

## 1(b) Six queries

### 1. List Computer Science students

```sql
SELECT s.StudentID, s.StudentName
FROM Student s
JOIN Department d ON s.DeptID = d.DeptID
WHERE d.DeptName = 'Computer Science';
```

**Result from sample data:** Alice, Charlie.

**Remember:** `JOIN` tables, `WHERE` department name.

### 2. List courses with faculty names

**Schema limitation:** The paper does **not** include `FacultyID` in `Course`, nor a course–faculty mapping table. It is therefore **not possible to identify which faculty member actually teaches each course** from the given five tables.

For a correct implementation, add this **extra mapping table** (not part of the question paper):

```sql
CREATE TABLE Course_Faculty (
    CourseID NUMBER,
    FacultyID NUMBER,
    PRIMARY KEY (CourseID, FacultyID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID),
    FOREIGN KEY (FacultyID) REFERENCES Faculty(FacultyID)
);

INSERT INTO Course_Faculty VALUES (10, 101);
INSERT INTO Course_Faculty VALUES (20, 102);

SELECT c.CourseName, f.FacultyName
FROM Course c
JOIN Course_Faculty cf ON c.CourseID = cf.CourseID
JOIN Faculty f ON cf.FacultyID = f.FacultyID;
```

**Result:** DBMS — Dr. Kumar; Circuits — Dr. Meena.

> Some simplified lab solutions join `Course` and `Faculty` by `DeptID`. That only lists faculty from the **same department**; it does **not** prove who teaches the course.

### 3. Display students' enrollments and grades

```sql
SELECT s.StudentName, c.CourseName, e.Semester, e.Grade
FROM Enrollment e
JOIN Student s ON e.StudentID = s.StudentID
JOIN Course c ON e.CourseID = c.CourseID;
```

**Remember:** `Enrollment` links students and courses.

### 4. Count students in each department

```sql
SELECT d.DeptName, COUNT(s.StudentID) AS TotalStudents
FROM Department d
LEFT JOIN Student s ON d.DeptID = s.DeptID
GROUP BY d.DeptID, d.DeptName;
```

**Result:** Computer Science = 2; Electronics = 1.

**Remember:** `COUNT + GROUP BY`. `LEFT JOIN` also shows departments with zero students.

### 5. Show departments and locations

```sql
SELECT DeptName, Location
FROM Department;
```

### 6. Show faculty with department names

```sql
SELECT f.FacultyName, d.DeptName
FROM Faculty f
JOIN Department d ON f.DeptID = d.DeptID;
```

**Quick memory:** **CREATE → INSERT → JOIN → COUNT**.

---

# 2. Data Manipulation Language (DML)

**Idea:** DML works with **rows**.

| Command | Purpose |
|---|---|
| `INSERT` | Add a row |
| `SELECT` | Read rows |
| `UPDATE` | Change existing rows |
| `DELETE` | Remove rows |

## Create the Employee table

```sql
CREATE TABLE Employee (
    EmpID NUMBER PRIMARY KEY,
    Name VARCHAR2(50),
    Department VARCHAR2(40),
    Salary NUMBER,
    City VARCHAR2(40)
);
```

## 1. INSERT the six records specified in the paper

```sql
INSERT INTO Employee VALUES (201, 'John', 'HR', 50000, 'Hyderabad');
INSERT INTO Employee VALUES (202, 'Alice', 'IT', 60000, 'Chennai');
INSERT INTO Employee VALUES (203, 'Bob', 'Finance', 55000, 'Bangalore');
INSERT INTO Employee VALUES (204, 'Emma', 'IT', 65000, 'Pune');
INSERT INTO Employee VALUES (205, 'David', 'Marketing', 48000, 'Delhi');
INSERT INTO Employee VALUES (206, 'Sophia', 'IT', 70000, 'Chennai');

COMMIT;
```

## 2. SELECT all employees

```sql
SELECT * FROM Employee;
```

`*` means **all columns**.

## 3. SELECT with WHERE

```sql
SELECT * FROM Employee
WHERE Department = 'IT';
```

**Result:** Alice (202), Emma (204), Sophia (206).

## 4. UPDATE an employee's city

```sql
UPDATE Employee
SET City = 'Mumbai'
WHERE EmpID = 201;
```

**Result:** John's city changes from Hyderabad to Mumbai.

## 5. DELETE an employee

```sql
DELETE FROM Employee
WHERE EmpID = 205;
```

**Result:** David (205) is deleted.

```sql
COMMIT;
```

**Remember:** `UPDATE` uses `SET`, `DELETE` uses `WHERE`. **Without WHERE, UPDATE/DELETE may affect all rows.**

---

# 3. SQL Functions

**Idea:** Functions take input and return a calculated or transformed value.

## 1. String functions

```sql
SELECT UPPER('database') AS UpperText FROM DUAL;
-- DATABASE

SELECT LOWER('SQL LAB') AS LowerText FROM DUAL;
-- sql lab

SELECT INITCAP('hello world') AS TitleCase FROM DUAL;
-- Hello World

SELECT LENGTH('ORACLE') AS LengthValue FROM DUAL;
-- 6

SELECT SUBSTR('DATABASE', 1, 4) AS Part FROM DUAL;
-- DATA

SELECT CONCAT('Data', 'base') AS Combined FROM DUAL;
-- Database

SELECT TRIM('  SQL  ') AS CleanText FROM DUAL;
-- SQL
```

**Remember:** `UPPER` big letters, `LOWER` small letters, `LENGTH` count, `SUBSTR` extract.

## 2. Numeric functions

```sql
SELECT ABS(-15) AS Answer FROM DUAL;
-- 15

SELECT ROUND(12.567, 2) AS Answer FROM DUAL;
-- 12.57

SELECT TRUNC(12.567, 2) AS Answer FROM DUAL;
-- 12.56

SELECT CEIL(4.2) AS Answer FROM DUAL;
-- 5

SELECT FLOOR(4.9) AS Answer FROM DUAL;
-- 4

SELECT MOD(10, 3) AS Answer FROM DUAL;
-- 1

SELECT POWER(2, 3) AS Answer FROM DUAL;
-- 8

SELECT SQRT(25) AS Answer FROM DUAL;
-- 5
```

**Remember:** `ROUND` changes by rounding; `TRUNC` simply cuts off extra decimal digits.

## 3. Date and time functions

```sql
SELECT SYSDATE AS CurrentDate FROM DUAL;
-- Current date/time from the database server

SELECT CURRENT_TIMESTAMP AS CurrentTime FROM DUAL;
-- Current timestamp with session time zone

SELECT ADD_MONTHS(DATE '2026-01-15', 2) AS NewDate FROM DUAL;
-- 15-MAR-2026 (display format depends on session)

SELECT MONTHS_BETWEEN(DATE '2026-03-15', DATE '2026-01-15')
       AS MonthGap FROM DUAL;
-- 2

SELECT EXTRACT(YEAR FROM DATE '2026-10-08') AS YearValue FROM DUAL;
-- 2026

SELECT TO_CHAR(DATE '2026-10-08', 'DD-MM-YYYY') AS FormattedDate
FROM DUAL;
-- 08-10-2026

SELECT LAST_DAY(DATE '2026-02-10') AS MonthEnd FROM DUAL;
-- 28-FEB-2026
```

**Remember:** Oracle uses `DUAL` for simple expressions; use `TO_CHAR` for predictable date display.

---

# 4. Aggregate Functions, GROUP BY, HAVING

**Idea:** Aggregates calculate results over many rows.

| Function | Meaning |
|---|---|
| `SUM` | Total |
| `AVG` | Average |
| `MIN` | Smallest |
| `MAX` | Largest |
| `COUNT` | Number |

**Setup:** Use a fresh copy of the experiment 2 `Employee` table with **all six original rows**, before its UPDATE and DELETE.

## Basic aggregates

```sql
SELECT
    SUM(Salary) AS TotalSalary,
    AVG(Salary) AS AverageSalary,
    MIN(Salary) AS MinimumSalary,
    MAX(Salary) AS MaximumSalary,
    COUNT(*) AS TotalEmployees
FROM Employee;
```

**Expected results from the original six rows:**

| SUM | AVG | MIN | MAX | COUNT |
|---:|---:|---:|---:|---:|
| 348000 | 58000 | 48000 | 70000 | 6 |

## GROUP BY — group employees department-wise

```sql
SELECT Department,
       COUNT(*) AS Employees,
       SUM(Salary) AS TotalSalary,
       AVG(Salary) AS AverageSalary
FROM Employee
GROUP BY Department;
```

For the IT department: **3 employees**, salary total **195000**, average **65000**.

## HAVING — filter groups

```sql
SELECT Department, COUNT(*) AS Total
FROM Employee
GROUP BY Department
HAVING COUNT(*) > 1;
```

**Result:** IT — 3. All other departments have 1 employee.

## GROUP BY + HAVING + ORDER BY

```sql
SELECT Department, AVG(Salary) AS AvgSalary
FROM Employee
GROUP BY Department
HAVING AVG(Salary) > 55000
ORDER BY AvgSalary DESC;
```

**Result:** IT — 65000.

**Remember:**
- `WHERE` filters **rows before grouping**.
- `GROUP BY` creates **groups**.
- `HAVING` filters **groups after aggregation**.
- `ORDER BY` sorts the result.

---

# 5. Joins and Set Operations

**Idea:** A **JOIN** combines columns from tables; a **set operation** combines/compares result rows.

## Setup (independent of other experiments)

```sql
CREATE TABLE Dept5 (
    DeptID NUMBER PRIMARY KEY,
    DeptName VARCHAR2(30)
);

CREATE TABLE Emp5 (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(30),
    DeptID NUMBER
);

INSERT INTO Dept5 VALUES (1, 'HR');
INSERT INTO Dept5 VALUES (2, 'IT');
INSERT INTO Dept5 VALUES (3, 'Finance');

INSERT INTO Emp5 VALUES (101, 'Alice', 1);
INSERT INTO Emp5 VALUES (102, 'Bob', 2);
INSERT INTO Emp5 VALUES (103, 'Charlie', 2);
INSERT INTO Emp5 VALUES (104, 'David', NULL);
COMMIT;
```

`Finance` has no employee, and `David` has no assigned department. This makes unmatched rows easy to observe.

## 1. NATURAL JOIN

Automatically joins columns with the **same name** (`DeptID` here).

```sql
SELECT EmpName, DeptName
FROM Emp5 NATURAL JOIN Dept5;
```

**Result:** Alice–HR, Bob–IT, Charlie–IT.

**Remember:** `NATURAL` matches shared column names. Use cautiously if tables have several identically named columns.

## 2. EQUI-JOIN

A join whose condition uses `=`.

```sql
SELECT e.EmpName, d.DeptName
FROM Emp5 e, Dept5 d
WHERE e.DeptID = d.DeptID;
```

**Result:** Three matched employee–department pairs.

**Remember:** **Equi** means **equal (`=`)**.

## 3. OUTER JOIN (FULL OUTER JOIN example)

```sql
SELECT e.EmpName, d.DeptName
FROM Emp5 e
FULL OUTER JOIN Dept5 d ON e.DeptID = d.DeptID;
```

**Result:** Matched employees, **David with NULL department**, and **Finance with NULL employee**.

**Remember:** `FULL` keeps unmatched rows from **both** tables.

## 4. LEFT OUTER JOIN

```sql
SELECT e.EmpName, d.DeptName
FROM Emp5 e
LEFT OUTER JOIN Dept5 d ON e.DeptID = d.DeptID;
```

**Result:** All four employees, including **David–NULL**.

**Remember:** `LEFT` keeps **all left-table** rows (`Emp5`).

## 5. RIGHT OUTER JOIN

```sql
SELECT e.EmpName, d.DeptName
FROM Emp5 e
RIGHT OUTER JOIN Dept5 d ON e.DeptID = d.DeptID;
```

**Result:** HR, IT, and Finance are present; **Finance has NULL employee**.

**Remember:** `RIGHT` keeps **all right-table** rows (`Dept5`).

## 6. INNER JOIN

```sql
SELECT e.EmpName, d.DeptName
FROM Emp5 e
INNER JOIN Dept5 d ON e.DeptID = d.DeptID;
```

**Result:** Three matched pairs; no David and no empty Finance row.

**Remember:** `INNER` keeps **matches only**.

### Join cheat sheet

| Join | Rows kept |
|---|---|
| INNER | Only matching |
| LEFT | All left + matching right |
| RIGHT | All right + matching left |
| FULL OUTER | All rows from either side |
| NATURAL | Automatically matches common column names |
| EQUI | Joins on equality condition |

## Set operations — setup

```sql
CREATE TABLE SetA (Value NUMBER);
CREATE TABLE SetB (Value NUMBER);

INSERT INTO SetA VALUES (1);
INSERT INTO SetA VALUES (2);
INSERT INTO SetA VALUES (3);

INSERT INTO SetB VALUES (2);
INSERT INTO SetB VALUES (3);
INSERT INTO SetB VALUES (4);
COMMIT;
```

### 1. UNION — all unique values from both

```sql
SELECT Value FROM SetA
UNION
SELECT Value FROM SetB;
```

**Result (regardless of order):** 1, 2, 3, 4.

### 2. INTERSECTION — common values

```sql
SELECT Value FROM SetA
INTERSECT
SELECT Value FROM SetB;
```

**Result:** 2, 3.

### 3. SET DIFFERENCE — first set only

In **Oracle SQL**, set difference is `MINUS` (other database products may use `EXCEPT`).

```sql
SELECT Value FROM SetA
MINUS
SELECT Value FROM SetB;
```

**Result:** 1.

**Remember:** `UNION` = both, `INTERSECT` = common, `MINUS` = left-only. Set queries must have compatible column counts and data types.

---

# 6. Correlated Subqueries and Nested Queries

**Idea:** A **nested query** is a query inside another query. A **correlated query** refers to a row in the outer query.

## Create the exact sample dataset given in the paper

> **Note:** This experiment's `Employee` table is **different** from the Employee table used in experiments 2 and 4. Use a fresh schema or drop/recreate that table.

```sql
CREATE TABLE Department (
    DeptID NUMBER PRIMARY KEY,
    DeptName VARCHAR2(30)
);

CREATE TABLE Employee (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(30),
    DeptID NUMBER,
    Salary NUMBER,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

INSERT INTO Department VALUES (1, 'HR');
INSERT INTO Department VALUES (2, 'IT');
INSERT INTO Department VALUES (3, 'Finance');

INSERT INTO Employee VALUES (101, 'Alice', 1, 50000);
INSERT INTO Employee VALUES (102, 'Bob', 2, 60000);
INSERT INTO Employee VALUES (103, 'Charlie', 2, 70000);
INSERT INTO Employee VALUES (104, 'David', 3, 55000);
INSERT INTO Employee VALUES (105, 'Eve', 1, 45000);
COMMIT;
```

## 1. Employees earning more than the average salary

```sql
SELECT EmpName, Salary
FROM Employee
WHERE Salary > (SELECT AVG(Salary) FROM Employee);
```

**Average = 56000. Result:** Bob (60000), Charlie (70000).

**Remember:** Compare each salary against the inner `AVG`.

## 2. Highest-paid employee(s)

```sql
SELECT EmpName, Salary
FROM Employee
WHERE Salary = (SELECT MAX(Salary) FROM Employee);
```

**Result:** Charlie (70000). `=` allows ties to appear if more than one employee earns the maximum.

## 3. Employees in Finance

```sql
SELECT EmpName
FROM Employee
WHERE DeptID = (
    SELECT DeptID
    FROM Department
    WHERE DeptName = 'Finance'
);
```

**Result:** David.

## 4. Employees in IT

```sql
SELECT EmpName
FROM Employee
WHERE DeptID = (
    SELECT DeptID
    FROM Department
    WHERE DeptName = 'IT'
);
```

**Result:** Bob, Charlie.

## 5. Employees earning less than David

```sql
SELECT EmpName, Salary
FROM Employee
WHERE Salary < (
    SELECT Salary
    FROM Employee
    WHERE EmpName = 'David'
);
```

**Result:** Alice (50000), Eve (45000).

**Note:** Assumes the name David uniquely identifies the intended employee in the sample data. For real databases, use `EmpID`.

## 6. Departments that have employees — using IN

```sql
SELECT DeptName
FROM Department
WHERE DeptID IN (
    SELECT DeptID
    FROM Employee
);
```

**Result:** HR, IT, Finance.

## Extra example: a true CORRELATED subquery

The six requested queries above are conveniently solved using ordinary nested queries. To demonstrate **correlation** explicitly, find employees earning more than the average salary **in their own department**:

```sql
SELECT e.EmpName, e.Salary, e.DeptID
FROM Employee e
WHERE e.Salary > (
    SELECT AVG(e2.Salary)
    FROM Employee e2
    WHERE e2.DeptID = e.DeptID
);
```

**Result:** Alice (HR), Charlie (IT).

**Why correlated?** `e.DeptID` comes from the **outer query**, so the inner average depends on the employee being examined.

**Remember:** **Nested = query within query; correlated = inner query refers to outer row.**

---

# 7. Views and Materialized Views

**Idea:**
- **View:** A saved query; normally does **not** separately store its output rows.
- **Materialized view:** Stores the query result physically and can be **refreshed**.

## Setup

Use a fresh experiment 6 `Employee` table, or create:

```sql
CREATE TABLE Employee7 (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(30),
    DeptID NUMBER,
    Salary NUMBER
);

INSERT INTO Employee7 VALUES (101, 'Alice', 1, 50000);
INSERT INTO Employee7 VALUES (102, 'Bob', 2, 60000);
INSERT INTO Employee7 VALUES (103, 'Charlie', 2, 70000);
COMMIT;
```

## 1. Create and query a normal view

```sql
CREATE OR REPLACE VIEW HighSalaryEmployees AS
SELECT EmpID, EmpName, Salary
FROM Employee7
WHERE Salary > 55000;

SELECT * FROM HighSalaryEmployees;
```

**Result:** Bob (60000), Charlie (70000).

A query against a regular view reflects the current underlying table data, subject to transaction visibility.

## 2. Create and query a materialized view (Oracle)

```sql
CREATE MATERIALIZED VIEW EmployeeSalarySummary
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND
AS
SELECT DeptID,
       COUNT(*) AS EmployeeCount,
       SUM(Salary) AS TotalSalary
FROM Employee7
GROUP BY DeptID;

SELECT * FROM EmployeeSalarySummary;
```

**Initial result:**

| DeptID | EmployeeCount | TotalSalary |
|---:|---:|---:|
| 1 | 1 | 50000 |
| 2 | 2 | 130000 |

## 3. Modify source data, then refresh

```sql
UPDATE Employee7
SET Salary = 65000
WHERE EmpID = 102;

COMMIT;
```

Because the materialized view uses **ON DEMAND**, the stored result may still show IT's previous total (**130000**) until refreshed.

```sql
BEGIN
    DBMS_MVIEW.REFRESH('EMPLOYEESALARYSUMMARY', 'C');
END;
/

SELECT * FROM EmployeeSalarySummary;
```

**After refresh:** IT total becomes **135000**.

> **Oracle note:** Creating materialized views requires appropriate privileges. The materialized-view refresh procedure is run in an Oracle-compatible environment.

**Remember:** **View = saved query. Materialized view = saved results + refresh.**

---

# 8. SQL Queries on a Normalized Database Schema

**Idea:** **Normalization** separates information into related tables to reduce duplication.

The question paper specifies five tables:

| Table | Columns |
|---|---|
| Students | StudentID, StudentName, Major |
| Courses | CourseID, CourseName, Credits |
| Enrollments | StudentID, CourseID, EnrollmentDate |
| Instructors | InstructorID, InstructorName, Phone |
| Course_Instructors | CourseID, InstructorID |

## 8(a) Create all five tables

```sql
CREATE TABLE Students (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(50),
    Major VARCHAR2(50)
);

CREATE TABLE Courses (
    CourseID NUMBER PRIMARY KEY,
    CourseName VARCHAR2(100),
    Credits NUMBER
);

CREATE TABLE Enrollments (
    StudentID NUMBER,
    CourseID NUMBER,
    EnrollmentDate DATE,
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);

CREATE TABLE Instructors (
    InstructorID NUMBER PRIMARY KEY,
    InstructorName VARCHAR2(50),
    Phone VARCHAR2(20)
);

CREATE TABLE Course_Instructors (
    CourseID NUMBER,
    InstructorID NUMBER,
    PRIMARY KEY (CourseID, InstructorID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID),
    FOREIGN KEY (InstructorID) REFERENCES Instructors(InstructorID)
);
```

**Note:** The composite PK on `Enrollments` allows one row per student/course combination. A system allowing repeated enrollment in the same course would need a different key (e.g., including term or attempt).

## Sample data (added for practicing; not specified by the paper)

```sql
INSERT INTO Students VALUES (1, 'Alice', 'Computer Science');
INSERT INTO Students VALUES (2, 'Bob', 'Data Science');
INSERT INTO Students VALUES (3, 'Charlie', 'Electronics');

INSERT INTO Courses VALUES (10, 'Introduction to Programming', 4);
INSERT INTO Courses VALUES (20, 'Database Systems', 3);
INSERT INTO Courses VALUES (30, 'Networks', 3);

INSERT INTO Instructors VALUES (101, 'Dr. Kumar', '9000000001');
INSERT INTO Instructors VALUES (102, 'Dr. Meena', '9000000002');

INSERT INTO Enrollments VALUES (1, 10, DATE '2026-08-01');
INSERT INTO Enrollments VALUES (2, 10, DATE '2026-08-02');
INSERT INTO Enrollments VALUES (2, 20, DATE '2026-08-03');

INSERT INTO Course_Instructors VALUES (10, 101);
INSERT INTO Course_Instructors VALUES (20, 102);

COMMIT;
```

## 1. All students and their majors

```sql
SELECT StudentName, Major
FROM Students;
```

## 2. Courses with credits

```sql
SELECT CourseName, Credits
FROM Courses;
```

## 3. Students enrolled in Introduction to Programming

```sql
SELECT s.StudentName
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
JOIN Courses c ON e.CourseID = c.CourseID
WHERE c.CourseName = 'Introduction to Programming';
```

**Result:** Alice, Bob.

## 4. Instructors teaching a specific course

```sql
SELECT i.InstructorName
FROM Instructors i
JOIN Course_Instructors ci ON i.InstructorID = ci.InstructorID
JOIN Courses c ON ci.CourseID = c.CourseID
WHERE c.CourseName = 'Introduction to Programming';
```

**Result:** Dr. Kumar.

## 5. Count students enrolled in each course

```sql
SELECT c.CourseName,
       COUNT(e.StudentID) AS TotalStudents
FROM Courses c
LEFT JOIN Enrollments e ON c.CourseID = e.CourseID
GROUP BY c.CourseID, c.CourseName;
```

**Result:** Introduction to Programming = 2; Database Systems = 1; Networks = 0.

**Remember:** `LEFT JOIN` includes courses with no enrollments.

## 6. Students not enrolled in any course

```sql
SELECT s.StudentName
FROM Students s
LEFT JOIN Enrollments e ON s.StudentID = e.StudentID
WHERE e.StudentID IS NULL;
```

**Result:** Charlie.

**Remember:** `LEFT JOIN + IS NULL` finds missing matches.

## 7. Courses with instructor names

```sql
SELECT c.CourseName, i.InstructorName
FROM Courses c
LEFT JOIN Course_Instructors ci ON c.CourseID = ci.CourseID
LEFT JOIN Instructors i ON ci.InstructorID = i.InstructorID;
```

**Result:** Introduction to Programming–Dr. Kumar; Database Systems–Dr. Meena; Networks–NULL (unassigned).

## 8. Number of courses taught by each instructor

```sql
SELECT i.InstructorName,
       COUNT(ci.CourseID) AS TotalCourses
FROM Instructors i
LEFT JOIN Course_Instructors ci
    ON i.InstructorID = ci.InstructorID
GROUP BY i.InstructorID, i.InstructorName;
```

**Result:** Dr. Kumar = 1; Dr. Meena = 1.

**Remember:** `Enrollments` connects students ↔ courses. `Course_Instructors` connects courses ↔ instructors.

---

# 9. Data Control Language (DCL) and Transaction Control Language (TCL)

**Idea:**
- **DCL:** Who is allowed to do something?
- **TCL:** Should a change be saved or undone?

## 1. DCL — GRANT and REVOKE

These commands assume the table is owned by the current user and the target database account `lab_user` already exists. Replace `lab_user` with an actual account as necessary.

```sql
GRANT SELECT, INSERT ON Employee7 TO lab_user;
-- Allow lab_user to read and insert into Employee7

REVOKE INSERT ON Employee7 FROM lab_user;
-- Remove the previously granted INSERT permission
```

You may also grant another privilege:

```sql
GRANT UPDATE ON Employee7 TO lab_user;
```

> **Requirements:** You must own the object or have permission to grant these privileges. REVOKE removes the specified grant; it does not necessarily eliminate privileges obtained through other routes.

**Remember:** `GRANT` gives permission; `REVOKE` takes it back.

## 2. TCL — COMMIT, SAVEPOINT, ROLLBACK

### Demonstration using a separate table

```sql
CREATE TABLE Account9 (
    AccountID NUMBER PRIMARY KEY,
    Balance NUMBER
);

INSERT INTO Account9 VALUES (1, 1000);
COMMIT;

UPDATE Account9 SET Balance = 900 WHERE AccountID = 1;
SAVEPOINT checkpoint1;

UPDATE Account9 SET Balance = 700 WHERE AccountID = 1;

ROLLBACK TO checkpoint1;
-- Undo the second UPDATE only; Balance returns to 900.

COMMIT;
-- Permanently commit the 900 balance.
```

Check:

```sql
SELECT * FROM Account9;
-- 1 | 900
```

### Full ROLLBACK example

```sql
UPDATE Account9 SET Balance = 500 WHERE AccountID = 1;

ROLLBACK;

SELECT * FROM Account9;
-- 1 | 900
```

**Remember:**
- `COMMIT` = **save** transaction.
- `SAVEPOINT` = **bookmark** within a transaction.
- `ROLLBACK` = **undo** uncommitted changes.
- `ROLLBACK TO name` = **return to bookmark**.

**Oracle warning:** DDL such as `CREATE TABLE` causes implicit commits; don't rely on `ROLLBACK` to undo table creation.

---

# 10. Indexing Techniques

**Idea:** An **index** is an auxiliary data structure that helps the database locate rows efficiently, much like a book's index. Indexes can speed up reads but add storage and maintenance work during inserts/deletes.

**Terminology note:** In textbook discussions, **primary index** can mean an index tied to the data's physical ordering, while **secondary index** accesses rows through another search key. In Oracle, a primary key typically uses a unique index, but this does **not** mean Oracle's storage matches every textbook definition of a physical "primary index." Below is the practical Oracle lab demonstration.

## Setup

```sql
CREATE TABLE Student10 (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(50),
    Dept VARCHAR2(30)
);

INSERT INTO Student10 VALUES (101, 'Alice', 'CSE');
INSERT INTO Student10 VALUES (102, 'Bob', 'ECE');
INSERT INTO Student10 VALUES (103, 'Charlie', 'CSE');
COMMIT;
```

## 1. Create primary and secondary indexes

### Primary-key index

The `PRIMARY KEY` constraint on `StudentID` normally causes Oracle to create or reuse a **unique supporting index** automatically.

View indexes:

```sql
SELECT Index_Name, Uniqueness
FROM USER_INDEXES
WHERE Table_Name = 'STUDENT10';
```

You generally **do not need to manually create another unique index on StudentID**.

### Secondary index on Dept

```sql
CREATE INDEX idx_student_dept
ON Student10(Dept);
```

**Remember:** Primary-key support is for the unique ID; secondary index here assists searches by department.

## 2. Retrieve records using the indexed column

```sql
SELECT *
FROM Student10
WHERE StudentID = 102;
-- Bob, ECE

SELECT *
FROM Student10
WHERE Dept = 'CSE';
-- Alice, Charlie
```

> Oracle's optimizer decides whether to use an index. Writing `WHERE Dept = 'CSE'` makes index use possible, but **does not guarantee** the optimizer will use it.

### Optional: inspect the execution plan

```sql
EXPLAIN PLAN FOR
SELECT * FROM Student10 WHERE Dept = 'CSE';

SELECT * FROM TABLE(DBMS_XPLAN.DISPLAY);
```

Look for `INDEX RANGE SCAN` if the optimizer chooses that access path.

## 3. Insert a record and observe index maintenance

```sql
INSERT INTO Student10 VALUES (104, 'David', 'CSE');

COMMIT;

SELECT * FROM Student10 WHERE Dept = 'CSE';
-- Alice, Charlie, David
```

**Explanation:** Oracle automatically maintains both the primary-key supporting index and the department index for the new row. You **do not manually insert index entries**.

## 4. Delete a record and observe index maintenance

```sql
DELETE FROM Student10
WHERE StudentID = 102;

COMMIT;

SELECT * FROM Student10 WHERE StudentID = 102;
-- No rows
```

**Explanation:** Oracle automatically updates the relevant index structures as the row is deleted. An index can remain present even when some of its indexed rows are removed.

### Confirm that the secondary index still exists

```sql
SELECT Index_Name
FROM USER_INDEXES
WHERE Table_Name = 'STUDENT10';
```

**Remember:** `CREATE INDEX` once → `INSERT/DELETE` maintain entries automatically → optimizer chooses whether to use index for `SELECT`.

---
