-- GET ALL EMPLOYEES
SELECT * FROM hr.employees;

-- QUESTION # 1 Write An SQL Query To Print Details Of The Workers Who Have Joined In Feb’2014.
SELECT * FROM hr.employees WHERE EXTRACT(MONTH FROM hr.employees.hire_date)=2 AND EXTRACT(YEAR FROM hr.employees.hire_date)=2014;

-- QUESTION # 2 Write An SQL Query To Show Only Odd Rows From A Table
SELECT * FROM hr.employees WHERE MOD(hr.employees.employee_id,2)=1;

-- QUESTION # 3 List the employees whose salary is more than 3000 after giving 20% increment.
SELECT hr.employees.*, 1.2*hr.employees.salary as increment_salary FROM hr.employees WHERE hr.employees.salary > 3000;

-- QUESTION # 4 Write a SQL statement that counts all employees hiring on date August 17th, 2012
SELECT COUNT(*) FROM hr.employees WHERE hr.employees.hire_date='17-AUG-12'; 

-- QUESTION # 5 Write a query to find the details of those employees who contain eight or more characters in their first name
SELECT * FROM hr.employees WHERE LENGTH(hr.employees.first_name)>=8;

-- QEUSTION # 6 Write a query to get the employee id, email id to discard the last three characters.
SELECT employee_id, first_name, last_name, SUBSTR(email,1,LENGTH(email)-3) as short_email FROM hr.employees;

-- QUESTION # 7 Write a query to find all the employees which first name contains the entire uppercase letter
SELECT * FROM hr.employees WHERE first_name=UPPER(hr.employees.first_name);

-- QUESTION # 8 Write a query which returns a date after which a certain time/date interval has been subtracted
SELECT TO_CHAR(systimestamp,'DD')-1 as day_subtract FROM dual;
SELECT TO_CHAR(systimestamp,'HH')-1 as time_subtract FROM dual;

-- QUESTION # 9 Convert a date which is in the character string to a date value.
SELECT TO_DATE('12-12-2012','DD-MM-YY') as string_to_date FROM dual;

-- QUESTION # 10 Write a query which returns employees whose last names begin with the letter L, whose ASCII equivalent is 76
SELECT * FROM hr.employees WHERE ASCII(hr.employees.last_name)=76;