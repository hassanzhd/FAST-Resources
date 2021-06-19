SELECT * FROM Worker;

-- Q:1
SELECT FIRST_NAME AS WORKER_NAME FROM Worker;

-- Q:2
SELECT UPPER(FIRST_NAME) FROM Worker;

-- Q:3
SELECT UNIQUE DEPARTMENT FROM Worker;

-- Q:4
SELECT SUBSTR(FIRST_NAME,1,3) FROM Worker;

-- Q:5. Write an SQL query to find the position of the alphabet (‘u’) in the first name column ‘Muhammad Nadeem’ from Worker table.
SELECT INSTR(FIRST_NAME,'u') FROM Worker WHERE Worker.FIRST_NAME='Muhammad Nadeem';

-- Q-6. Write an SQL query to print the FIRST_NAME from Worker table after removing white spaces from the right side.
SELECT RTRIM(FIRST_NAME,' ') FROM Worker;

-- Q-7. Write an SQL query to print the DEPARTMENT from Worker table after removing white spaces from the left side.
SELECT LTRIM(Department,' ') FROM Worker;

-- Q-8. Write an SQL query that fetches the unique values of DEPARTMENT from Worker table and prints its length.
SELECT DISTINCT LENGTH(department) FROM Worker;

-- Q-9. Write an SQL query to print the FIRST_NAME from Worker table after replacing ‘a’ with ‘A’.
SELECT REPLACE(FIRST_NAME,'a','A') FROM Worker;

-- Q-10. Write an SQL query to print the FIRST_NAME and LAST_NAME from Worker table into a single column COMPLETE_NAME. A space char should separate them.
SELECT CONCAT(FIRST_NAME,LAST_NAME) as COMPLETE_NAME FROM Worker;

-- Q-11. Write an SQL query to print all Worker details from the Worker table order by FIRST_NAME Ascending.
SELECT * FROM Worker ORDER BY FIRST_NAME ASC;

-- Q-12. Write an SQL query to print all Worker details from the Worker table order by FIRST_NAME Ascending and DEPARTMENT Descending.
SELECT * FROM Worker ORDER BY FIRST_NAME ASC, DEPARTMENT DESC;

-- Q-13. Write an SQL query to print details for Workers with the first name as “Muhammad Nadeem” and “Muhammad Faheem” from Worker table.
SELECT * FROM Worker WHERE FIRST_NAME IN ('Muhammad Nadeem','Muhammad Faheem');

-- Q-14. Write an SQL query to print details of workers excluding first names, “Muhammad Nadeem” and “Muhammad Faheem” from Worker table.
SELECT * FROM Worker WHERE FIRST_NAME NOT IN ('Muhammad Nadeem','Muhammad Faheem');

-- Q-15. Write an SQL query to print details of Workers with DEPARTMENT name as “CS”.
SELECT * FROM Worker WHERE Department='CS';

-- Q-16. Write an SQL query to print details of the Workers whose FIRST_NAME contains ‘a’.
SELECT * FROM Worker WHERE FIRST_NAME LIKE '%a%';

-- Q-17. Write an SQL query to print details of the Workers whose FIRST_NAME ends with ‘a’.
SELECT * FROM Worker WHERE FIRST_NAME LIKE '%a';

-- Q-18. Write an SQL query to print details of the Workers whose FIRST_NAME ends with ‘h’ and contains six alphabets.
SELECT * FROM Worker WHERE FIRST_NAME LIKE '%h' AND LENGTH(FIRST_NAME)=6;

-- Q-19. Write an SQL query to print details of the Workers whose SALARY lies between 100000 and 500000.
SELECT * FROM Worker WHERE SALARY > 100000 AND SALARY < 500000;

-- Q-20. Write an SQL query to print details of the Workers who have joined in Feb’2014.
SELECT * FROM Worker WHERE TO_CHAR(JOINING_DATE,'MM-YY')='02-14';

-- Q-21. Write an SQL query to fetch the count of employees working in the department ‘CS’.
SELECT COUNT(*) FROM Worker WHERE Department='CS';

-- Q-22. Write an SQL query to fetch worker names with salaries >= 50000 and <= 100000.
SELECT FIRST_NAME FROM Worker WHERE Salary>=50000 AND Salary<=100000;

-- Q-23. Write an SQL query to fetch the no. of workers for each department in the descending order.
SELECT Department, COUNT(*) AS "NUMBER" FROM Worker GROUP BY Department ORDER BY COUNT(*) DESC;

-- Q-24. Write an SQL query to print details of the Workers who are also Managers.
SELECT * FROM Worker JOIN Title ON WORKER_ID=WORKER_REF_ID WHERE WORKER_TITLE='Manager';

-- Q-25. Write an SQL query to fetch duplicate records having matching data in some fields of a table.
SELECT JOINING_DATE,DEPARTMENT,COUNT(*) FROM Worker GROUP BY DEPARTMENT,JOINING_DATE HAVING COUNT(*)>1;

-- Q-26. Write an SQL query to show only odd rows from a table.
SELECT * FROM Worker WHERE MOD(WORKER_ID,2)<>0;

-- Q-27. Write an SQL query to show only even rows from a table.
SELECT * FROM Worker WHERE MOD(WORKER_ID,2)=0;

-- Q-29. Write an SQL query to fetch intersecting records of two tables.
SELECT worker_id FROM Worker INTERSECT SELECT worker_ref_id FROM Title;