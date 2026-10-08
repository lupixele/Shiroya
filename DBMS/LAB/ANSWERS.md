# DBMS Lab Internal — Complete Answers & Revision Guide

**SQL:** Oracle Database 10g

> Run the table setup once for your assigned question, then run its numbered parts. Each question is independent.
>
> [Oracle 10g installer](https://adityagroup-my.sharepoint.com/:u:/g/personal/25b11ds190_adityauniversity_in/IQCHlMTn8svaTJv08O6BrD0qAZ2WJvZsQjqBFXPhKE1Mqdc?e=FMSYlb)

---

# 1. University Database — Schema Creation and SQL Queries

## 1(a) Create the university tables

**Idea:** A **primary key** identifies each record. `DeptID` identifies a department; `StudentID`, `FacultyID`, and `CourseID` identify their respective records.

| Table | Attributes |
|---|---|
| Department | DeptID, DeptName, Location |
| Faculty | FacultyID, FacultyName, DeptID, Email |
| Student | StudentID, StudentName, DOB, DeptID, Email |
| Course | CourseID, CourseName, DeptID, Credits |
| Enrollment | EnrollmentID, StudentID, CourseID, Semester, Grade |

```sql
CREATE TABLE Department (
    DeptID NUMBER PRIMARY KEY,
    DeptName VARCHAR2(30),
    Location VARCHAR2(30)
);

CREATE TABLE Faculty (
    FacultyID NUMBER PRIMARY KEY,
    FacultyName VARCHAR2(30),
    DeptID NUMBER,
    Email VARCHAR2(50)
);

CREATE TABLE Student (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(30),
    DOB DATE,
    DeptID NUMBER,
    Email VARCHAR2(50)
);

CREATE TABLE Course (
    CourseID NUMBER PRIMARY KEY,
    CourseName VARCHAR2(30),
    DeptID NUMBER,
    Credits NUMBER
);

CREATE TABLE Enrollment (
    EnrollmentID NUMBER PRIMARY KEY,
    StudentID NUMBER,
    CourseID NUMBER,
    Semester VARCHAR2(10),
    Grade VARCHAR2(5)
);
```

### Sample records — run once

```sql
INSERT INTO Department VALUES (1, 'Computer Science', 'Block A');
INSERT INTO Department VALUES (2, 'Electronics', 'Block B');

INSERT INTO Faculty VALUES (101, 'Kumar', 1, 'kumar@uni.com');
INSERT INTO Faculty VALUES (102, 'Meena', 2, 'meena@uni.com');

INSERT INTO Student VALUES (1, 'Alice', DATE '2005-01-10', 1, 'alice@uni.com');
INSERT INTO Student VALUES (2, 'Bob', DATE '2005-02-10', 2, 'bob@uni.com');
INSERT INTO Student VALUES (3, 'Charlie', DATE '2005-03-10', 1, 'charlie@uni.com');

INSERT INTO Course VALUES (10, 'DBMS', 1, 4);
INSERT INTO Course VALUES (20, 'Circuits', 2, 3);

INSERT INTO Enrollment VALUES (1, 1, 10, 'III', 'A');
INSERT INTO Enrollment VALUES (2, 2, 20, 'III', 'B');
INSERT INTO Enrollment VALUES (3, 3, 10, 'III', 'A');
COMMIT;
```

## 1(b) Write SQL queries

### 1. List Computer Science students

```sql
SELECT Student.StudentName
FROM Student
JOIN Department ON Student.DeptID = Department.DeptID
WHERE Department.DeptName = 'Computer Science';
```

**Output:** Alice, Charlie.

**Remember:** `JOIN` matches department IDs; `WHERE` selects Computer Science.

### 2. List courses with faculty names

```sql
SELECT Course.CourseName, Faculty.FacultyName
FROM Course
JOIN Faculty ON Course.DeptID = Faculty.DeptID;
```

**Output:** DBMS — Kumar; Circuits — Meena.

**Explanation:** Matches courses and faculty from the same department. In our sample, each department has one faculty member. The given schema does not identify who teaches each course, so this is a department-based match, not a confirmed teaching assignment.

### 3. Display student enrollments with grades

```sql
SELECT Student.StudentName, Course.CourseName, Enrollment.Grade
FROM Enrollment
JOIN Student ON Enrollment.StudentID = Student.StudentID
JOIN Course ON Enrollment.CourseID = Course.CourseID;
```

**Output:** Alice — DBMS — A; Bob — Circuits — B; Charlie — DBMS — A.

**Remember:** `Enrollment` connects `Student` and `Course`.

### 4. Count students in each department

```sql
SELECT Department.DeptName, COUNT(Student.StudentID)
FROM Department
LEFT JOIN Student ON Department.DeptID = Student.DeptID
GROUP BY Department.DeptID, Department.DeptName;
```

**Output:** Computer Science — 2; Electronics — 1.

**Remember:** `LEFT JOIN` includes departments with no students; `GROUP BY` counts by department.

### 5. Display departments with locations

```sql
SELECT DeptName, Location FROM Department;
```

**Output:** Computer Science — Block A; Electronics — Block B.

### 6. Display faculty with department names

```sql
SELECT Faculty.FacultyName, Department.DeptName
FROM Faculty
JOIN Department ON Faculty.DeptID = Department.DeptID;
```

**Output:** Kumar — Computer Science; Meena — Electronics.

---

# 2. Data Manipulation Language (DML)

**Idea:** DML commands add, read, change, and delete records.

| Command | Action |
|---|---|
| `INSERT` | Add a record |
| `SELECT` | Display records |
| `UPDATE` | Change a record |
| `DELETE` | Remove a record |

## Create the Employee table

```sql
CREATE TABLE Employee (
    EmpID NUMBER PRIMARY KEY,
    Name VARCHAR2(30),
    Department VARCHAR2(30),
    Salary NUMBER,
    City VARCHAR2(30)
);
```

### 1. Insert the given employee records

```sql
INSERT INTO Employee VALUES (201, 'John', 'HR', 50000, 'Hyderabad');
INSERT INTO Employee VALUES (202, 'Alice', 'IT', 60000, 'Chennai');
INSERT INTO Employee VALUES (203, 'Bob', 'Finance', 55000, 'Bangalore');
INSERT INTO Employee VALUES (204, 'Emma', 'IT', 65000, 'Pune');
INSERT INTO Employee VALUES (205, 'David', 'Marketing', 48000, 'Delhi');
INSERT INTO Employee VALUES (206, 'Sophia', 'IT', 70000, 'Chennai');
COMMIT;
```

**Explanation:** `INSERT INTO ... VALUES` adds one employee per statement.

### 2. Display all employees using SELECT

```sql
SELECT * FROM Employee;
```

**Output:** All 6 employee records.

**Remember:** `*` means all columns.

### 3. Display employees using WHERE

```sql
SELECT * FROM Employee WHERE Department = 'IT';
```

**Output:** Alice, Emma, Sophia.

**Remember:** `WHERE` filters records.

### 4. Change a specified employee's city

```sql
UPDATE Employee SET City = 'Mumbai' WHERE EmpID = 201;
SELECT * FROM Employee WHERE EmpID = 201;
```

**Output:** John's city is now Mumbai.

**Remember:** `SET` changes the value; `WHERE` chooses the row.

### 5. Delete a specified employee

```sql
DELETE FROM Employee WHERE EmpID = 205;
SELECT * FROM Employee;
COMMIT;
```

**Output:** David (EmpID 205) is no longer in the table.

**Remember:** Always check the `WHERE` condition before `DELETE` or `UPDATE`.

---

# 3. SQL Functions

**Idea:** A function performs an operation and returns a result. Oracle uses the built-in `DUAL` table for these examples.

## 1. String functions

```sql
SELECT UPPER('hello') FROM DUAL;
SELECT LOWER('HELLO') FROM DUAL;
SELECT LENGTH('ORACLE') FROM DUAL;
SELECT SUBSTR('DATABASE', 1, 4) FROM DUAL;
SELECT CONCAT('SQL', 'LAB') FROM DUAL;
```

| Function | Output |
|---|---|
| UPPER | HELLO |
| LOWER | hello |
| LENGTH | 6 |
| SUBSTR | DATA |
| CONCAT | SQLLAB |

**Remember:** Uppercase, lowercase, count letters, take a portion, join text.

## 2. Numeric functions

```sql
SELECT ABS(-10) FROM DUAL;
SELECT ROUND(12.567, 2) FROM DUAL;
SELECT MOD(10, 3) FROM DUAL;
SELECT CEIL(4.2) FROM DUAL;
SELECT FLOOR(4.9) FROM DUAL;
```

| Function | Output |
|---|---:|
| ABS | 10 |
| ROUND | 12.57 |
| MOD | 1 |
| CEIL | 5 |
| FLOOR | 4 |

**Remember:** `ABS` removes minus; `ROUND` rounds; `MOD` gives remainder; `CEIL` rounds up; `FLOOR` rounds down.

## 3. Date and time functions

```sql
SELECT SYSDATE FROM DUAL;
SELECT ADD_MONTHS(SYSDATE, 2) FROM DUAL;
SELECT LAST_DAY(SYSDATE) FROM DUAL;
SELECT TO_CHAR(SYSDATE, 'DD-MM-YYYY') FROM DUAL;
SELECT MONTHS_BETWEEN(DATE '2026-03-01', DATE '2026-01-01') FROM DUAL;
```

**Output:** The first four depend on today's database date. `MONTHS_BETWEEN` returns **2**.

**Remember:** `SYSDATE` = today; `ADD_MONTHS` = move forward; `LAST_DAY` = month end; `TO_CHAR` = date format.

---

# 4. Aggregate Functions — GROUP BY and HAVING

**Idea:** Aggregate functions calculate results from several rows.

| Function | Meaning |
|---|---|
| SUM | Total |
| AVG | Average |
| MIN | Smallest |
| MAX | Largest |
| COUNT | Number of rows |

## Create and fill the table

```sql
CREATE TABLE Employee (
    EmpID NUMBER,
    EmpName VARCHAR2(30),
    Department VARCHAR2(20),
    Salary NUMBER
);

INSERT INTO Employee VALUES (1, 'Alice', 'IT', 60000);
INSERT INTO Employee VALUES (2, 'Bob', 'IT', 50000);
INSERT INTO Employee VALUES (3, 'John', 'HR', 40000);
INSERT INTO Employee VALUES (4, 'Emma', 'HR', 45000);
INSERT INTO Employee VALUES (5, 'David', 'Finance', 55000);
COMMIT;
```

### 1. SUM, AVG, MIN, MAX and COUNT

```sql
SELECT SUM(Salary), AVG(Salary), MIN(Salary),
       MAX(Salary), COUNT(*)
FROM Employee;
```

| SUM | AVG | MIN | MAX | COUNT |
|---:|---:|---:|---:|---:|
| 250000 | 50000 | 40000 | 60000 | 5 |

### 2. Use GROUP BY

```sql
SELECT Department, COUNT(*), SUM(Salary)
FROM Employee
GROUP BY Department;
```

**Output:** IT — 2 employees, 110000; HR — 2, 85000; Finance — 1, 55000.

**Remember:** `GROUP BY` makes one result group per department.

### 3. Use HAVING

```sql
SELECT Department, COUNT(*)
FROM Employee
GROUP BY Department
HAVING COUNT(*) > 1;
```

**Output:** IT — 2; HR — 2.

**Remember:** `WHERE` filters rows; `HAVING` filters groups.

---

# 5. Joins and Set Operations

**Idea:** Joins combine related rows from two tables. Set operations combine or compare the results of two SELECT statements.

## Create and fill the tables

```sql
CREATE TABLE Department (
    DeptID NUMBER,
    DeptName VARCHAR2(30)
);

CREATE TABLE Employee (
    EmpID NUMBER,
    EmpName VARCHAR2(30),
    DeptID NUMBER
);

INSERT INTO Department VALUES (1, 'HR');
INSERT INTO Department VALUES (2, 'IT');
INSERT INTO Department VALUES (3, 'Finance');

INSERT INTO Employee VALUES (101, 'Alice', 1);
INSERT INTO Employee VALUES (102, 'Bob', 2);
INSERT INTO Employee VALUES (103, 'Charlie', 2);
INSERT INTO Employee VALUES (104, 'David', 4);
COMMIT;
```

## 5(1) Join operations

### 1. Natural join

```sql
SELECT EmpName, DeptName
FROM Employee NATURAL JOIN Department;
```

**Output:** Alice — HR; Bob — IT; Charlie — IT.

**Remember:** `NATURAL JOIN` matches columns with the same name (`DeptID`).

### 2. Equi-join

```sql
SELECT Employee.EmpName, Department.DeptName
FROM Employee
JOIN Department ON Employee.DeptID = Department.DeptID;
```

**Output:** Alice — HR; Bob — IT; Charlie — IT.

**Remember:** Equi-join uses `=` to match columns.

### 3. Outer join (full outer join)

```sql
SELECT Employee.EmpName, Department.DeptName
FROM Employee FULL OUTER JOIN Department
ON Employee.DeptID = Department.DeptID;
```

**Output:** Three matches, plus David — NULL and NULL — Finance.

**Remember:** `FULL OUTER JOIN` includes unmatched records from both tables.

### 4. Left outer join

```sql
SELECT Employee.EmpName, Department.DeptName
FROM Employee LEFT JOIN Department
ON Employee.DeptID = Department.DeptID;
```

**Output:** All four employees, including David — NULL.

**Remember:** `LEFT JOIN` keeps all rows from the left table.

### 5. Right outer join

```sql
SELECT Employee.EmpName, Department.DeptName
FROM Employee RIGHT JOIN Department
ON Employee.DeptID = Department.DeptID;
```

**Output:** HR and IT matches, plus NULL — Finance.

**Remember:** `RIGHT JOIN` keeps all rows from the right table.

### 6. Inner join

```sql
SELECT Employee.EmpName, Department.DeptName
FROM Employee INNER JOIN Department
ON Employee.DeptID = Department.DeptID;
```

**Output:** Alice — HR; Bob — IT; Charlie — IT.

**Remember:** `INNER JOIN` returns only matching rows.

## 5(2) Set operations

### 1. UNION

```sql
SELECT DeptID FROM Employee
UNION
SELECT DeptID FROM Department;
```

**Output:** 1, 2, 3, 4.

**Remember:** `UNION` combines values and removes duplicates.

### 2. INTERSECTION (INTERSECT)

```sql
SELECT DeptID FROM Employee
INTERSECT
SELECT DeptID FROM Department;
```

**Output:** 1, 2.

**Remember:** `INTERSECT` returns values present in both results.

### 3. SET DIFFERENCE (MINUS)

```sql
SELECT DeptID FROM Department
MINUS
SELECT DeptID FROM Employee;
```

**Output:** 3.

**Remember:** Oracle `MINUS` returns values from the first SELECT that are missing from the second.

---

# 6. Correlated Subqueries and Nested Queries

**Idea:** A nested query is a `SELECT` inside another query. A correlated query uses a value from the outer query.

## Create the tables and insert the question-paper data

```sql
CREATE TABLE Department (
    DeptID NUMBER,
    DeptName VARCHAR2(30)
);

CREATE TABLE Employee (
    EmpID NUMBER,
    EmpName VARCHAR2(30),
    DeptID NUMBER,
    Salary NUMBER
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

### 1. Employees earning above the average salary

```sql
SELECT EmpName FROM Employee
WHERE Salary > (SELECT AVG(Salary) FROM Employee);
```

**Output:** Bob, Charlie. The average salary is 56000.

**Remember:** The inner query calculates `AVG`; the outer query compares salaries.

### 2. Employees with the highest salary

```sql
SELECT EmpName FROM Employee
WHERE Salary = (SELECT MAX(Salary) FROM Employee);
```

**Output:** Charlie (70000).

**Remember:** `MAX` finds the highest value.

### 3. Employees in the Finance department

```sql
SELECT EmpName FROM Employee
WHERE DeptID = (SELECT DeptID FROM Department
                WHERE DeptName = 'Finance');
```

**Output:** David.

### 4. Employees in the IT department

```sql
SELECT EmpName FROM Employee
WHERE DeptID = (SELECT DeptID FROM Department
                WHERE DeptName = 'IT');
```

**Output:** Bob, Charlie.

### 5. Employees earning less than David

```sql
SELECT EmpName FROM Employee
WHERE Salary < (SELECT Salary FROM Employee
                WHERE EmpName = 'David');
```

**Output:** Alice, Eve. David earns 55000.

**Remember:** The inner query first finds David's salary.

### 6. Departments with employees using IN

```sql
SELECT DeptName FROM Department
WHERE DeptID IN (SELECT DeptID FROM Employee);
```

**Output:** HR, IT, Finance.

**Remember:** `IN` checks whether a value appears in the subquery result.

### Correlated subquery example

```sql
SELECT e.EmpName FROM Employee e
WHERE e.Salary > (SELECT AVG(Salary) FROM Employee x
                  WHERE x.DeptID = e.DeptID);
```

**Output:** Alice, Charlie.

**Explanation:** For each employee, the inner query calculates the average salary **of that employee's department** using `e.DeptID` from the outer query.

---

# 7. Views and Materialized Views

**Idea:** A view is a saved query. A materialized view stores a copy of the query result.

## Create the Employee table

```sql
CREATE TABLE Employee (
    EmpID NUMBER,
    EmpName VARCHAR2(30),
    Salary NUMBER
);

INSERT INTO Employee VALUES (1, 'Alice', 50000);
INSERT INTO Employee VALUES (2, 'Bob', 60000);
INSERT INTO Employee VALUES (3, 'Charlie', 70000);
COMMIT;
```

### 1. Create and query a view

```sql
CREATE VIEW HighSalary AS
SELECT * FROM Employee WHERE Salary > 55000;

SELECT * FROM HighSalary;
```

**Output:** Bob, Charlie.

**Remember:** A view displays rows returned by its saved `SELECT`.

### 2. Create and query a materialized view

```sql
CREATE MATERIALIZED VIEW SalaryCopy AS
SELECT * FROM Employee;

SELECT * FROM SalaryCopy;
```

**Output:** Alice, Bob, Charlie and their salaries.

**Remember:** Materialized views store results. Your Oracle user must have `CREATE MATERIALIZED VIEW` privilege.

---

# 8. SQL Queries on a Normalized Database Schema

**Idea:** The five tables separate student, course, enrollment, and instructor details. `Enrollments` links students to courses; `Course_Instructors` links courses to instructors.

| Table | Attributes |
|---|---|
| Students | StudentID, StudentName, Major |
| Courses | CourseID, CourseName, Credits |
| Enrollments | StudentID, CourseID, EnrollmentDate |
| Instructors | InstructorID, InstructorName, Phone |
| Course_Instructors | CourseID, InstructorID |

## Create tables and insert sample records

```sql
CREATE TABLE Students (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(30),
    Major VARCHAR2(30)
);

CREATE TABLE Courses (
    CourseID NUMBER PRIMARY KEY,
    CourseName VARCHAR2(50),
    Credits NUMBER
);

CREATE TABLE Enrollments (
    StudentID NUMBER NOT NULL,
    CourseID NUMBER,
    EnrollmentDate DATE
);

CREATE TABLE Instructors (
    InstructorID NUMBER PRIMARY KEY,
    InstructorName VARCHAR2(30),
    Phone VARCHAR2(15)
);

CREATE TABLE Course_Instructors (
    CourseID NUMBER,
    InstructorID NUMBER
);

INSERT INTO Students VALUES (1, 'Alice', 'CSE');
INSERT INTO Students VALUES (2, 'Bob', 'Data Science');
INSERT INTO Students VALUES (3, 'Charlie', 'ECE');

INSERT INTO Courses VALUES (10, 'Introduction to Programming', 4);
INSERT INTO Courses VALUES (20, 'DBMS', 3);
INSERT INTO Courses VALUES (30, 'Networks', 3);

INSERT INTO Instructors VALUES (101, 'Kumar', '9000000001');
INSERT INTO Instructors VALUES (102, 'Meena', '9000000002');

INSERT INTO Enrollments VALUES (1, 10, DATE '2026-08-01');
INSERT INTO Enrollments VALUES (2, 10, DATE '2026-08-02');
INSERT INTO Enrollments VALUES (2, 20, DATE '2026-08-03');

INSERT INTO Course_Instructors VALUES (10, 101);
INSERT INTO Course_Instructors VALUES (20, 102);
COMMIT;
```

### 1. Retrieve all students with majors

```sql
SELECT StudentName, Major FROM Students;
```

**Output:** Alice — CSE; Bob — Data Science; Charlie — ECE.

### 2. List courses with credits

```sql
SELECT CourseName, Credits FROM Courses;
```

**Output:** Introduction to Programming — 4; DBMS — 3; Networks — 3.

### 3. Find students enrolled in Introduction to Programming

```sql
SELECT Students.StudentName
FROM Students
JOIN Enrollments ON Students.StudentID = Enrollments.StudentID
JOIN Courses ON Enrollments.CourseID = Courses.CourseID
WHERE Courses.CourseName = 'Introduction to Programming';
```

**Output:** Alice, Bob.

**Remember:** Join students to enrollments, then enrollments to courses.

### 4. Find instructors teaching Introduction to Programming

```sql
SELECT Instructors.InstructorName
FROM Instructors
JOIN Course_Instructors ON Instructors.InstructorID = Course_Instructors.InstructorID
JOIN Courses ON Course_Instructors.CourseID = Courses.CourseID
WHERE Courses.CourseName = 'Introduction to Programming';
```

**Output:** Kumar.

**Remember:** `Course_Instructors` connects courses and instructors.

### 5. Count students enrolled in each course

```sql
SELECT Courses.CourseName, COUNT(Enrollments.StudentID)
FROM Courses
LEFT JOIN Enrollments ON Courses.CourseID = Enrollments.CourseID
GROUP BY Courses.CourseID, Courses.CourseName;
```

**Output:** Introduction to Programming — 2; DBMS — 1; Networks — 0.

**Remember:** `LEFT JOIN` also displays a course with zero enrollments.

### 6. Find students who have no enrollment

```sql
SELECT Students.StudentName
FROM Students
LEFT JOIN Enrollments ON Students.StudentID = Enrollments.StudentID
WHERE Enrollments.StudentID IS NULL;
```

**Output:** Charlie.

**Remember:** `LEFT JOIN` plus `IS NULL` finds students without an enrollment.

### 7. List courses with their instructor names

```sql
SELECT Courses.CourseName, Instructors.InstructorName
FROM Courses
LEFT JOIN Course_Instructors ON Courses.CourseID = Course_Instructors.CourseID
LEFT JOIN Instructors ON Course_Instructors.InstructorID = Instructors.InstructorID;
```

**Output:** Introduction to Programming — Kumar; DBMS — Meena; Networks — NULL (no instructor assigned).

**Remember:** Join course → course-instructor table → instructor.

### 8. Count courses taught by each instructor

```sql
SELECT Instructors.InstructorName, COUNT(Course_Instructors.CourseID)
FROM Instructors
LEFT JOIN Course_Instructors
ON Instructors.InstructorID = Course_Instructors.InstructorID
GROUP BY Instructors.InstructorID, Instructors.InstructorName;
```

**Output:** Kumar — 1; Meena — 1.

**Remember:** `GROUP BY` counts courses for each instructor; `LEFT JOIN` includes instructors with zero courses.

---

# 9. Data Control Language (DCL) and Transaction Control Language (TCL)

**Idea:** DCL handles permissions. TCL saves or undoes changes made to data.

## Create the Marks table

```sql
CREATE TABLE Marks (
    RollNo NUMBER,
    Marks NUMBER
);

INSERT INTO Marks VALUES (1, 70);
COMMIT;
```

### 1. DCL — GRANT and REVOKE

```sql
GRANT SELECT ON Marks TO lab_user;
REVOKE SELECT ON Marks FROM lab_user;
```

**Explanation:** `GRANT` gives `lab_user` permission to read `Marks`. `REVOKE` removes that grant.

**Note:** `lab_user` must already exist, and your account must be allowed to grant access.

### 2. TCL — COMMIT, SAVEPOINT, ROLLBACK

```sql
UPDATE Marks SET Marks = 80 WHERE RollNo = 1;
SAVEPOINT s1;

UPDATE Marks SET Marks = 40 WHERE RollNo = 1;
ROLLBACK TO s1;

COMMIT;
SELECT * FROM Marks;
```

**Output:** RollNo = 1, Marks = 80.

**Explanation:** `SAVEPOINT s1` marks the value 80. `ROLLBACK TO s1` cancels the change to 40. `COMMIT` saves 80.

### Full ROLLBACK

```sql
UPDATE Marks SET Marks = 99 WHERE RollNo = 1;
ROLLBACK;
SELECT * FROM Marks;
```

**Output:** Marks is still 80.

**Remember:** `COMMIT` = save; `SAVEPOINT` = bookmark; `ROLLBACK` = undo.

---

# 10. Indexing Techniques

**Idea:** An index helps Oracle find records by a column. Oracle automatically maintains indexes when rows are inserted or deleted.

## Create the table and insert records

```sql
CREATE TABLE Student (
    StudentID NUMBER PRIMARY KEY,
    StudentName VARCHAR2(30),
    Department VARCHAR2(20)
);

INSERT INTO Student VALUES (1, 'Alice', 'CSE');
INSERT INTO Student VALUES (2, 'Bob', 'ECE');
INSERT INTO Student VALUES (3, 'Charlie', 'CSE');
COMMIT;
```

### 1. Create a primary and secondary index

`StudentID NUMBER PRIMARY KEY` normally makes Oracle create an index to support the primary key. Create a separate index on `Department`:

```sql
CREATE INDEX idx_dept ON Student(Department);
```

**Remember:** Primary key = unique ID; secondary index here = department search. In Oracle, a primary-key index is not necessarily a physically ordered textbook primary index.

### 2. Retrieve records using indexed columns

```sql
SELECT * FROM Student WHERE StudentID = 2;
SELECT * FROM Student WHERE Department = 'CSE';
```

**Output:** First query returns Bob. Second returns Alice and Charlie.

**Note:** Oracle decides whether an index is actually used for a query.

### 3. Insert a record and observe index updates

```sql
INSERT INTO Student VALUES (4, 'David', 'CSE');
SELECT * FROM Student WHERE Department = 'CSE';
```

**Output:** Alice, Charlie, David.

**Explanation:** The new record is added to the table; Oracle also updates its indexes automatically.

### 4. Delete a record and observe index updates

```sql
DELETE FROM Student WHERE StudentID = 2;
SELECT * FROM Student WHERE StudentID = 2;
COMMIT;
```

**Output:** No rows found for StudentID 2.

**Explanation:** Oracle removes the deleted record's index entries automatically; the indexes themselves remain available.

---

# Quick Revision

| Question | Main topic | Key words |
|---:|---|---|
| 1 | University database | CREATE, JOIN, WHERE, GROUP BY |
| 2 | DML | INSERT, SELECT, UPDATE, DELETE |
| 3 | SQL functions | UPPER, ROUND, SYSDATE |
| 4 | Aggregates | SUM, AVG, MIN, MAX, COUNT, HAVING |
| 5 | Joins and sets | LEFT, RIGHT, FULL, UNION, INTERSECT, MINUS |
| 6 | Subqueries | SELECT inside SELECT, IN |
| 7 | Views | VIEW, MATERIALIZED VIEW |
| 8 | Normalized database | JOIN, LEFT JOIN, GROUP BY |
| 9 | DCL/TCL | GRANT, REVOKE, COMMIT, ROLLBACK |
| 10 | Indexes | PRIMARY KEY, CREATE INDEX |
