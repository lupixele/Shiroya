# DBMS Lab Test — Independent Code Blocks

> **Purpose:** Each experiment is fully self-contained. A student can execute any single block without running previous experiments. All tables, data, and queries are included.

> **Usage:** Copy the entire block for your assigned question. Run it in Oracle SQL, then write answers and code on paper.

---

## EXPERIMENT 1: University Database — Schema & Queries

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 1: UNIVERSITY DATABASE ============

-- SETUP: Create tables
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

-- SETUP: Create Course-Faculty mapping (required for Q1(b).2)
CREATE TABLE Course_Faculty (
    CourseID NUMBER,
    FacultyID NUMBER,
    PRIMARY KEY (CourseID, FacultyID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID),
    FOREIGN KEY (FacultyID) REFERENCES Faculty(FacultyID)
);

-- SETUP: Insert sample data
INSERT INTO Department VALUES (1, 'Computer Science', 'Block A');
INSERT INTO Department VALUES (2, 'Electronics', 'Block B');

INSERT INTO Faculty VALUES (101, 'Dr. Kumar', 1, 'kumar@uni.edu');
INSERT INTO Faculty VALUES (102, 'Dr. Meena', 2, 'meena@uni.edu');

INSERT INTO Student VALUES (1, 'Alice', TO_DATE('2005-04-12', 'YYYY-MM-DD'), 1, 'alice@uni.edu');
INSERT INTO Student VALUES (2, 'Bob', TO_DATE('2005-09-21', 'YYYY-MM-DD'), 2, 'bob@uni.edu');
INSERT INTO Student VALUES (3, 'Charlie', TO_DATE('2004-11-05', 'YYYY-MM-DD'), 1, 'charlie@uni.edu');

INSERT INTO Course VALUES (10, 'DBMS', 1, 4);
INSERT INTO Course VALUES (20, 'Circuits', 2, 3);

INSERT INTO Course_Faculty VALUES (10, 101);
INSERT INTO Course_Faculty VALUES (20, 102);

INSERT INTO Enrollment VALUES (1001, 1, 10, 'III', 'A');
INSERT INTO Enrollment VALUES (1002, 3, 10, 'III', 'B');
INSERT INTO Enrollment VALUES (1003, 2, 20, 'III', 'A');

COMMIT;

-- ============ QUERIES: Write answers for the following ============

-- Q1(b).1: List Computer Science students
SELECT s.StudentID, s.StudentName
FROM Student s
JOIN Department d ON s.DeptID = d.DeptID
WHERE d.DeptName = 'Computer Science';

-- Q1(b).2: List courses with faculty names
SELECT c.CourseName, f.FacultyName
FROM Course c
JOIN Course_Faculty cf ON c.CourseID = cf.CourseID
JOIN Faculty f ON cf.FacultyID = f.FacultyID;

-- Q1(b).3: Display students' enrollments and grades
SELECT s.StudentName, c.CourseName, e.Semester, e.Grade
FROM Enrollment e
JOIN Student s ON e.StudentID = s.StudentID
JOIN Course c ON e.CourseID = c.CourseID;

-- Q1(b).4: Count students in each department
SELECT d.DeptName, COUNT(s.StudentID) AS TotalStudents
FROM Department d
LEFT JOIN Student s ON d.DeptID = s.DeptID
GROUP BY d.DeptID, d.DeptName;

-- Q1(b).5: Show departments and locations
SELECT DeptName, Location
FROM Department;

-- Q1(b).6: Show faculty with department names
SELECT f.FacultyName, d.DeptName
FROM Faculty f
JOIN Department d ON f.DeptID = d.DeptID;

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Enrollment;
-- DROP TABLE Course_Faculty;
-- DROP TABLE Course;
-- DROP TABLE Faculty;
-- DROP TABLE Student;
-- DROP TABLE Department;
```

---

## EXPERIMENT 2: Data Manipulation Language (DML)

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 2: DATA MANIPULATION LANGUAGE (DML) ============

-- SETUP: Create Employee table
CREATE TABLE Employee (
    EmpID NUMBER PRIMARY KEY,
    Name VARCHAR2(50),
    Department VARCHAR2(40),
    Salary NUMBER,
    City VARCHAR2(40)
);

-- SETUP: Insert six records
INSERT INTO Employee VALUES (201, 'John', 'HR', 50000, 'Hyderabad');
INSERT INTO Employee VALUES (202, 'Alice', 'IT', 60000, 'Chennai');
INSERT INTO Employee VALUES (203, 'Bob', 'Finance', 55000, 'Bangalore');
INSERT INTO Employee VALUES (204, 'Emma', 'IT', 65000, 'Pune');
INSERT INTO Employee VALUES (205, 'David', 'Marketing', 48000, 'Delhi');
INSERT INTO Employee VALUES (206, 'Sophia', 'IT', 70000, 'Chennai');

COMMIT;

-- ============ QUERIES: Write answers for the following ============

-- Q2.1: INSERT a new employee (example)
INSERT INTO Employee VALUES (207, 'Frank', 'IT', 62000, 'Mumbai');

-- Q2.2: SELECT all employees
SELECT * FROM Employee;

-- Q2.3: SELECT with WHERE clause
SELECT * FROM Employee
WHERE Department = 'IT';

-- Q2.4: UPDATE an employee's city
UPDATE Employee
SET City = 'Mumbai'
WHERE EmpID = 201;

-- Q2.5: DELETE an employee
DELETE FROM Employee
WHERE EmpID = 205;

-- COMMIT all changes
COMMIT;

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Employee;
```

---

## EXPERIMENT 3: SQL Functions (String, Numeric, Date)

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 3: SQL FUNCTIONS ============

-- Note: Functions are shown using DUAL (Oracle's dummy table)
-- Run each query separately to see results

-- ============ STRING FUNCTIONS ============

SELECT UPPER('database') AS UpperText FROM DUAL;
-- Expected: DATABASE

SELECT LOWER('SQL LAB') AS LowerText FROM DUAL;
-- Expected: sql lab

SELECT INITCAP('hello world') AS TitleCase FROM DUAL;
-- Expected: Hello World

SELECT LENGTH('ORACLE') AS LengthValue FROM DUAL;
-- Expected: 6

SELECT SUBSTR('DATABASE', 1, 4) AS Part FROM DUAL;
-- Expected: DATA

SELECT CONCAT('Data', 'base') AS Combined FROM DUAL;
-- Expected: Database

SELECT TRIM('  SQL  ') AS CleanText FROM DUAL;
-- Expected: SQL

-- ============ NUMERIC FUNCTIONS ============

SELECT ABS(-15) AS Answer FROM DUAL;
-- Expected: 15

SELECT ROUND(12.567, 2) AS Answer FROM DUAL;
-- Expected: 12.57

SELECT TRUNC(12.567, 2) AS Answer FROM DUAL;
-- Expected: 12.56

SELECT CEIL(4.2) AS Answer FROM DUAL;
-- Expected: 5

SELECT FLOOR(4.9) AS Answer FROM DUAL;
-- Expected: 4

SELECT MOD(10, 3) AS Answer FROM DUAL;
-- Expected: 1

SELECT POWER(2, 3) AS Answer FROM DUAL;
-- Expected: 8

SELECT SQRT(25) AS Answer FROM DUAL;
-- Expected: 5

-- ============ DATE FUNCTIONS ============

SELECT SYSDATE AS CurrentDate FROM DUAL;
-- Expected: Current server date/time

SELECT CURRENT_TIMESTAMP AS CurrentTime FROM DUAL;
-- Expected: Current timestamp with timezone

SELECT ADD_MONTHS(DATE '2026-01-15', 2) AS NewDate FROM DUAL;
-- Expected: 15-MAR-2026

SELECT MONTHS_BETWEEN(DATE '2026-03-15', DATE '2026-01-15')
       AS MonthGap FROM DUAL;
-- Expected: 2

SELECT EXTRACT(YEAR FROM DATE '2026-10-08') AS YearValue FROM DUAL;
-- Expected: 2026

SELECT TO_CHAR(DATE '2026-10-08', 'DD-MM-YYYY') AS FormattedDate
FROM DUAL;
-- Expected: 08-10-2026

SELECT LAST_DAY(DATE '2026-02-10') AS MonthEnd FROM DUAL;
-- Expected: 28-FEB-2026

-- ============ COMBINED FUNCTION EXAMPLE ============

CREATE TABLE Employee3 (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(50),
    JoinDate DATE,
    Salary NUMBER
);

INSERT INTO Employee3 VALUES (101, 'alice', DATE '2023-01-15', 50000);
INSERT INTO Employee3 VALUES (102, 'bob', DATE '2022-06-20', 60000);

COMMIT;

-- Use functions on table data
SELECT EmpID,
       INITCAP(EmpName) AS Name,
       TO_CHAR(JoinDate, 'DD-MM-YYYY') AS JoinedOn,
       ROUND(Salary, -3) AS RoundedSalary
FROM Employee3;

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Employee3;
```

---

## EXPERIMENT 4: Aggregate Functions, GROUP BY, HAVING

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 4: AGGREGATE FUNCTIONS, GROUP BY, HAVING ============

-- SETUP: Create Employee table with fresh data
CREATE TABLE Employee4 (
    EmpID NUMBER PRIMARY KEY,
    Name VARCHAR2(50),
    Department VARCHAR2(40),
    Salary NUMBER
);

-- SETUP: Insert six records (BEFORE any UPDATE/DELETE)
INSERT INTO Employee4 VALUES (201, 'John', 'HR', 50000);
INSERT INTO Employee4 VALUES (202, 'Alice', 'IT', 60000);
INSERT INTO Employee4 VALUES (203, 'Bob', 'Finance', 55000);
INSERT INTO Employee4 VALUES (204, 'Emma', 'IT', 65000);
INSERT INTO Employee4 VALUES (205, 'David', 'Marketing', 48000);
INSERT INTO Employee4 VALUES (206, 'Sophia', 'IT', 70000);

COMMIT;

-- ============ QUERIES: Write answers for the following ============

-- Q4.1: Basic aggregates (all employees)
SELECT
    SUM(Salary) AS TotalSalary,
    AVG(Salary) AS AverageSalary,
    MIN(Salary) AS MinimumSalary,
    MAX(Salary) AS MaximumSalary,
    COUNT(*) AS TotalEmployees
FROM Employee4;

-- Expected: 348000 | 58000 | 48000 | 70000 | 6

-- Q4.2: GROUP BY — employees per department
SELECT Department,
       COUNT(*) AS Employees,
       SUM(Salary) AS TotalSalary,
       AVG(Salary) AS AverageSalary
FROM Employee4
GROUP BY Department;

-- Expected: HR=1/50000/50000, IT=3/195000/65000, Finance=1/55000/55000, Marketing=1/48000/48000

-- Q4.3: HAVING — departments with more than 1 employee
SELECT Department, COUNT(*) AS Total
FROM Employee4
GROUP BY Department
HAVING COUNT(*) > 1;

-- Expected: IT | 3

-- Q4.4: GROUP BY + HAVING + ORDER BY
SELECT Department, AVG(Salary) AS AvgSalary
FROM Employee4
GROUP BY Department
HAVING AVG(Salary) > 55000
ORDER BY AvgSalary DESC;

-- Expected: IT | 65000

-- Q4.5: MAX salary per department
SELECT Department, MAX(Salary) AS HighestSalary
FROM Employee4
GROUP BY Department
ORDER BY HighestSalary DESC;

-- Expected: IT=70000, Finance=55000, HR=50000, Marketing=48000

-- Q4.6: Departments with total salary > 60000
SELECT Department, SUM(Salary) AS TotalSalary
FROM Employee4
GROUP BY Department
HAVING SUM(Salary) > 60000;

-- Expected: IT | 195000

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Employee4;
```

---

## EXPERIMENT 5: Joins and Set Operations

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 5: JOINS AND SET OPERATIONS ============

-- ============ PART A: JOINS ============

-- SETUP: Create Department and Employee tables
CREATE TABLE Dept5 (
    DeptID NUMBER PRIMARY KEY,
    DeptName VARCHAR2(30)
);

CREATE TABLE Emp5 (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(30),
    DeptID NUMBER
);

-- SETUP: Insert data
INSERT INTO Dept5 VALUES (1, 'HR');
INSERT INTO Dept5 VALUES (2, 'IT');
INSERT INTO Dept5 VALUES (3, 'Finance');

INSERT INTO Emp5 VALUES (101, 'Alice', 1);
INSERT INTO Emp5 VALUES (102, 'Bob', 2);
INSERT INTO Emp5 VALUES (103, 'Charlie', 2);
INSERT INTO Emp5 VALUES (104, 'David', NULL);

COMMIT;

-- ============ JOIN QUERIES: Write answers for the following ============

-- Q5.1: NATURAL JOIN
SELECT EmpName, DeptName
FROM Emp5 NATURAL JOIN Dept5;

-- Expected: Alice-HR, Bob-IT, Charlie-IT

-- Q5.2: EQUI-JOIN (old syntax)
SELECT e.EmpName, d.DeptName
FROM Emp5 e, Dept5 d
WHERE e.DeptID = d.DeptID;

-- Expected: Alice-HR, Bob-IT, Charlie-IT

-- Q5.3: INNER JOIN
SELECT e.EmpName, d.DeptName
FROM Emp5 e
INNER JOIN Dept5 d ON e.DeptID = d.DeptID;

-- Expected: Alice-HR, Bob-IT, Charlie-IT

-- Q5.4: LEFT OUTER JOIN
SELECT e.EmpName, d.DeptName
FROM Emp5 e
LEFT OUTER JOIN Dept5 d ON e.DeptID = d.DeptID;

-- Expected: Alice-HR, Bob-IT, Charlie-IT, David-NULL

-- Q5.5: RIGHT OUTER JOIN
SELECT e.EmpName, d.DeptName
FROM Emp5 e
RIGHT OUTER JOIN Dept5 d ON e.DeptID = d.DeptID;

-- Expected: Alice-HR, Bob-IT, Charlie-IT, NULL-Finance

-- Q5.6: FULL OUTER JOIN
SELECT e.EmpName, d.DeptName
FROM Emp5 e
FULL OUTER JOIN Dept5 d ON e.DeptID = d.DeptID;

-- Expected: Alice-HR, Bob-IT, Charlie-IT, David-NULL, NULL-Finance

-- ============ PART B: SET OPERATIONS ============

-- SETUP: Create SetA and SetB tables
CREATE TABLE SetA (Value NUMBER);
CREATE TABLE SetB (Value NUMBER);

INSERT INTO SetA VALUES (1);
INSERT INTO SetA VALUES (2);
INSERT INTO SetA VALUES (3);

INSERT INTO SetB VALUES (2);
INSERT INTO SetB VALUES (3);
INSERT INTO SetB VALUES (4);

COMMIT;

-- ============ SET OPERATION QUERIES: Write answers for the following ============

-- Q5.7: UNION (all unique values)
SELECT Value FROM SetA
UNION
SELECT Value FROM SetB;

-- Expected: 1, 2, 3, 4 (order may vary)

-- Q5.8: INTERSECT (common values)
SELECT Value FROM SetA
INTERSECT
SELECT Value FROM SetB;

-- Expected: 2, 3

-- Q5.9: MINUS (first set only — Oracle-specific)
SELECT Value FROM SetA
MINUS
SELECT Value FROM SetB;

-- Expected: 1

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Emp5;
-- DROP TABLE Dept5;
-- DROP TABLE SetA;
-- DROP TABLE SetB;
```

---

## EXPERIMENT 6: Correlated Subqueries and Nested Queries

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 6: CORRELATED SUBQUERIES AND NESTED QUERIES ============

-- SETUP: Create Department and Employee tables
CREATE TABLE Department6 (
    DeptID NUMBER PRIMARY KEY,
    DeptName VARCHAR2(30)
);

CREATE TABLE Employee6 (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(30),
    DeptID NUMBER,
    Salary NUMBER,
    FOREIGN KEY (DeptID) REFERENCES Department6(DeptID)
);

-- SETUP: Insert sample data
INSERT INTO Department6 VALUES (1, 'HR');
INSERT INTO Department6 VALUES (2, 'IT');
INSERT INTO Department6 VALUES (3, 'Finance');

INSERT INTO Employee6 VALUES (101, 'Alice', 1, 50000);
INSERT INTO Employee6 VALUES (102, 'Bob', 2, 60000);
INSERT INTO Employee6 VALUES (103, 'Charlie', 2, 70000);
INSERT INTO Employee6 VALUES (104, 'David', 3, 55000);
INSERT INTO Employee6 VALUES (105, 'Eve', 1, 45000);

COMMIT;

-- ============ QUERIES: Write answers for the following ============

-- Q6.1: Employees earning more than average salary
SELECT EmpName, Salary
FROM Employee6
WHERE Salary > (SELECT AVG(Salary) FROM Employee6);

-- Expected: Bob (60000), Charlie (70000)

-- Q6.2: Highest-paid employee(s)
SELECT EmpName, Salary
FROM Employee6
WHERE Salary = (SELECT MAX(Salary) FROM Employee6);

-- Expected: Charlie (70000)

-- Q6.3: Employees in Finance department
SELECT EmpName
FROM Employee6
WHERE DeptID = (
    SELECT DeptID
    FROM Department6
    WHERE DeptName = 'Finance'
);

-- Expected: David

-- Q6.4: Employees in IT department
SELECT EmpName
FROM Employee6
WHERE DeptID = (
    SELECT DeptID
    FROM Department6
    WHERE DeptName = 'IT'
);

-- Expected: Bob, Charlie

-- Q6.5: Employees earning less than David
SELECT EmpName, Salary
FROM Employee6
WHERE Salary < (
    SELECT Salary
    FROM Employee6
    WHERE EmpName = 'David'
);

-- Expected: Alice (50000), Eve (45000)

-- Q6.6: Departments that have employees
SELECT DeptName
FROM Department6
WHERE DeptID IN (
    SELECT DeptID
    FROM Employee6
);

-- Expected: HR, IT, Finance

-- Q6.7 (BONUS): Employees earning more than average in their own department (CORRELATED)
SELECT e.EmpName, e.Salary, e.DeptID
FROM Employee6 e
WHERE e.Salary > (
    SELECT AVG(e2.Salary)
    FROM Employee6 e2
    WHERE e2.DeptID = e.DeptID
);

-- Expected: Alice (HR), Charlie (IT)

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Employee6;
-- DROP TABLE Department6;
```

---

## EXPERIMENT 7: Views and Materialized Views

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 7: VIEWS AND MATERIALIZED VIEWS ============

-- SETUP: Create Employee table
CREATE TABLE Employee7 (
    EmpID NUMBER PRIMARY KEY,
    EmpName VARCHAR2(30),
    DeptID NUMBER,
    Salary NUMBER
);

-- SETUP: Insert sample data
INSERT INTO Employee7 VALUES (101, 'Alice', 1, 50000);
INSERT INTO Employee7 VALUES (102, 'Bob', 2, 60000);
INSERT INTO Employee7 VALUES (103, 'Charlie', 2, 70000);

COMMIT;

-- ============ QUERIES: Write answers for the following ============

-- Q7.1: Create a normal VIEW
CREATE OR REPLACE VIEW HighSalaryEmployees AS
SELECT EmpID, EmpName, Salary
FROM Employee7
WHERE Salary > 55000;

-- Query the view
SELECT * FROM HighSalaryEmployees;

-- Expected: Bob (60000), Charlie (70000)

-- Q7.2: Create a MATERIALIZED VIEW
CREATE MATERIALIZED VIEW EmployeeSalarySummary
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND
AS
SELECT DeptID,
       COUNT(*) AS EmployeeCount,
       SUM(Salary) AS TotalSalary
FROM Employee7
GROUP BY DeptID;

-- Query the materialized view
SELECT * FROM EmployeeSalarySummary;

-- Expected: Dept 1 (1 emp, 50000); Dept 2 (2 emp, 130000)

-- Q7.3: Update source data
UPDATE Employee7
SET Salary = 65000
WHERE EmpID = 102;

COMMIT;

-- Check normal view (reflects changes immediately)
SELECT * FROM HighSalaryEmployees;

-- Check materialized view (may show old data)
SELECT * FROM EmployeeSalarySummary;

-- Q7.4: Refresh the materialized view
BEGIN
    DBMS_MVIEW.REFRESH('EMPLOYEESALARYSUMMARY', 'C');
END;
/

-- Query materialized view again (should be updated)
SELECT * FROM EmployeeSalarySummary;

-- Expected after refresh: Dept 2 total becomes 135000

-- ============ CLEANUP (if needed) ============
-- DROP MATERIALIZED VIEW EmployeeSalarySummary;
-- DROP VIEW HighSalaryEmployees;
-- DROP TABLE Employee7;
```

---

## EXPERIMENT 8: Normalized Database Schema

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 8: NORMALIZED DATABASE SCHEMA ============

-- SETUP: Create five tables
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

-- SETUP: Insert sample data
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

-- ============ QUERIES: Write answers for the following ============

-- Q8.1: All students and their majors
SELECT StudentName, Major
FROM Students;

-- Expected: Alice-CS, Bob-DS, Charlie-Electronics

-- Q8.2: Courses with credits
SELECT CourseName, Credits
FROM Courses;

-- Expected: 3 courses with their credits

-- Q8.3: Students enrolled in "Introduction to Programming"
SELECT s.StudentName
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
JOIN Courses c ON e.CourseID = c.CourseID
WHERE c.CourseName = 'Introduction to Programming';

-- Expected: Alice, Bob

-- Q8.4: Instructors teaching "Introduction to Programming"
SELECT i.InstructorName
FROM Instructors i
JOIN Course_Instructors ci ON i.InstructorID = ci.InstructorID
JOIN Courses c ON ci.CourseID = c.CourseID
WHERE c.CourseName = 'Introduction to Programming';

-- Expected: Dr. Kumar

-- Q8.5: Count students enrolled in each course
SELECT c.CourseName,
       COUNT(e.StudentID) AS TotalStudents
FROM Courses c
LEFT JOIN Enrollments e ON c.CourseID = e.CourseID
GROUP BY c.CourseID, c.CourseName;

-- Expected: Intro Prog=2, DB Systems=1, Networks=0

-- Q8.6: Students not enrolled in any course
SELECT s.StudentName
FROM Students s
LEFT JOIN Enrollments e ON s.StudentID = e.StudentID
WHERE e.StudentID IS NULL;

-- Expected: Charlie

-- Q8.7: Courses with instructor names
SELECT c.CourseName, i.InstructorName
FROM Courses c
LEFT JOIN Course_Instructors ci ON c.CourseID = ci.CourseID
LEFT JOIN Instructors i ON ci.InstructorID = i.InstructorID;

-- Expected: 3 courses (some may have NULL instructors)

-- Q8.8: Number of courses taught by each instructor
SELECT i.InstructorName,
       COUNT(ci.CourseID) AS TotalCourses
FROM Instructors i
LEFT JOIN Course_Instructors ci
    ON i.InstructorID = ci.InstructorID
GROUP BY i.InstructorID, i.InstructorName;

-- Expected: Dr. Kumar=1, Dr. Meena=1

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Enrollments;
-- DROP TABLE Course_Instructors;
-- DROP TABLE Courses;
-- DROP TABLE Students;
-- DROP TABLE Instructors;
```

---

## EXPERIMENT 9: Data Control Language (DCL) and Transaction Control Language (TCL)

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 9: DCL AND TCL ============

-- ============ PART A: TRANSACTION CONTROL LANGUAGE (TCL) ============

-- SETUP: Create a test table
CREATE TABLE Account9 (
    AccountID NUMBER PRIMARY KEY,
    Balance NUMBER
);

INSERT INTO Account9 VALUES (1, 1000);
COMMIT;

-- ============ TRANSACTION QUERIES: Write answers for the following ============

-- Q9.1: Basic UPDATE with COMMIT
UPDATE Account9 SET Balance = 900 WHERE AccountID = 1;

COMMIT;

SELECT * FROM Account9;
-- Expected: 1 | 900

-- Q9.2: SAVEPOINT demonstration
UPDATE Account9 SET Balance = 700 WHERE AccountID = 1;

-- Create a savepoint before another change
SAVEPOINT checkpoint1;

UPDATE Account9 SET Balance = 500 WHERE AccountID = 1;

-- Rollback to savepoint (undo only the last update)
ROLLBACK TO checkpoint1;

COMMIT;

SELECT * FROM Account9;
-- Expected: 1 | 700

-- Q9.3: Full ROLLBACK demonstration
UPDATE Account9 SET Balance = 300 WHERE AccountID = 1;

-- Don't commit; just rollback the entire transaction
ROLLBACK;

SELECT * FROM Account9;
-- Expected: 1 | 700 (back to committed state)

-- Q9.4: Multiple updates with selective rollback
UPDATE Account9 SET Balance = 600 WHERE AccountID = 1;

SAVEPOINT sp1;

UPDATE Account9 SET Balance = 550 WHERE AccountID = 1;

SAVEPOINT sp2;

UPDATE Account9 SET Balance = 450 WHERE AccountID = 1;

-- Rollback to sp2 only
ROLLBACK TO sp2;

COMMIT;

SELECT * FROM Account9;
-- Expected: 1 | 550

-- ============ PART B: DATA CONTROL LANGUAGE (DCL) ============

-- Note: The following commands assume you have administrative privileges.
-- Replace 'lab_user' with an actual database user if testing these commands.

-- Q9.5: GRANT permissions (conceptual — adjust user name as needed)
-- GRANT SELECT, INSERT ON Account9 TO lab_user;
-- GRANT UPDATE ON Account9 TO lab_user;

-- Q9.6: REVOKE permissions (conceptual)
-- REVOKE INSERT ON Account9 FROM lab_user;

-- Q9.7: View granted privileges (for current user's objects)
-- SELECT * FROM USER_TAB_PRIVS_MADE;

-- ============ CLEANUP (if needed) ============
-- DROP TABLE Account9;
```

---

## EXPERIMENT 10: Indexing Techniques

**Copy and run this entire block:**

```sql
-- ============ EXPERIMENT 10: INDEXING TECHNIQUES ============

-- SETUP: Create Student table
CREATE TABLE Student10 (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(50),
    Dept VARCHAR2(30)
);

-- SETUP: Insert sample data
INSERT INTO Student10 VALUES (101, 'Alice', 'CSE');
INSERT INTO Student10 VALUES (102, 'Bob', 'ECE');
INSERT INTO Student10 VALUES (103, 'Charlie', 'CSE');

COMMIT;

-- ============ QUERIES: Write answers for the following ============

-- Q10.1: View existing indexes (including primary key index)
SELECT Index_Name, Uniqueness
FROM USER_INDEXES
WHERE Table_Name = 'STUDENT10';

-- Expected: An index on StudentID (primary key)

-- Q10.2: Create a secondary index on Department
CREATE INDEX idx_student_dept
ON Student10(Dept);

-- Verify the index was created
SELECT Index_Name, Uniqueness
FROM USER_INDEXES
WHERE Table_Name = 'STUDENT10';

-- Q10.3: Query using the primary key (indexed column)
SELECT *
FROM Student10
WHERE StudentID = 102;

-- Expected: Bob | ECE

-- Q10.4: Query using the secondary index (Department)
SELECT *
FROM Student10
WHERE Dept = 'CSE';

-- Expected: Alice, Charlie

-- Q10.5: INSERT a new record (index updated automatically)
INSERT INTO Student10 VALUES (104, 'David', 'CSE');

COMMIT;

SELECT * FROM Student10 WHERE Dept = 'CSE';

-- Expected: Alice, Charlie, David

-- Q10.6: DELETE a record (index updated automatically)
DELETE FROM Student10
WHERE StudentID = 102;

COMMIT;

SELECT * FROM Student10 WHERE StudentID = 102;

-- Expected: No rows

-- Q10.7: Verify index still exists (even with deleted rows)
SELECT Index_Name
FROM USER_INDEXES
WHERE Table_Name = 'STUDENT10';

-- Q10.8 (BONUS): View execution plan (EXPLAIN PLAN)
EXPLAIN PLAN FOR
SELECT * FROM Student10 WHERE Dept = 'CSE';

SELECT * FROM TABLE(DBMS_XPLAN.DISPLAY);

-- Look for "INDEX RANGE SCAN" or "TABLE ACCESS" in the plan

-- ============ CLEANUP (if needed) ============
-- DROP INDEX idx_student_dept;
-- DROP TABLE Student10;
```

---

## Quick Reference: Run Order for Testing

| Experiment | Table Names | Key Concept |
|---|---|---|
| 1 | Department, Faculty, Student, Course, Enrollment, Course_Faculty | CREATE TABLE + PK/FK + JOIN |
| 2 | Employee | INSERT, SELECT, UPDATE, DELETE |
| 3 | Employee3, DUAL | String/Numeric/Date Functions |
| 4 | Employee4 | SUM, AVG, MIN, MAX, COUNT, GROUP BY, HAVING |
| 5 | Dept5, Emp5, SetA, SetB | INNER/LEFT/RIGHT/FULL JOIN; UNION/INTERSECT/MINUS |
| 6 | Department6, Employee6 | Nested & Correlated Subqueries |
| 7 | Employee7, Views, Materialized Views | CREATE VIEW; CREATE MATERIALIZED VIEW |
| 8 | Students, Courses, Enrollments, Instructors, Course_Instructors | Normalized Schema with Bridge Tables |
| 9 | Account9 | COMMIT, SAVEPOINT, ROLLBACK; GRANT, REVOKE |
| 10 | Student10, Indexes | CREATE INDEX; Automatic Maintenance |

---

## Testing Tips for Students

1. **Copy the entire block** for your assigned question.
2. **Run the SETUP section** first to create tables and insert data.
3. **Execute each QUERY** one by one.
4. **Write your answers on paper** — include:
   - The SQL code
   - Expected output
   - Explanation of the query logic
5. **Use CLEANUP** at the end if testing another experiment in the same session.

**Each experiment is completely independent. You do NOT need to run experiments in order.**

---

**End of Independent Test Code.**
