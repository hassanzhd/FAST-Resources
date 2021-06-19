select * from hr.employees where hr.employees.salary > 20000 and hr.employees.salary<50000;
select * from hr.jobs;

-- QUESTION # 2 Write a SQL statement to insert one row in jobs table to ensure that no duplicate value will be entered in the employee_id column.

create table employee (
employee_id number constraint employee_id_pk primary key,
employee_name varchar(20)
);

-- QUESTION # 3 Write a SQL statement to change salary of employee to 8000 who’s ID is 105, if the existing salary is less than 5000.
update hr.employees set hr.employees.salary=8000 where hr.employees.employee_id=105 and hr.employees.salary<5000;

-- QUESTION # 4 Write a SQL statement to change job ID of employee which ID is 118, to ST_CLERK if the employee belongs to department, which ID is 101 and the 
-- existing job ID does not start with SH.
update hr.employees set hr.employees.job_id='ST_CLERK' where hr.employees.employee_id=118 and hr.employees.department_id=101 and substr(hr.employees.job_id,1,2)<>'SH';

-- QUESTION # 5 Write a  SQL statement to create a table named countries including columns country_id, country_name and region_id and make sure that the country_id
-- column will be a key field which will not contain any duplicate data at the time of insertion.
create table countries (
country_id number constraint country_id_pk primary key,
country_name varchar(20),
region_id number
);

-- QUESTION # 6 Write a SQL statement to add a column emp_address to the table Employees.
alter table hr.employees add (emp_address varchar(20));

-- QUESTION # 7 Write a SQL statement to drop the column Commision_PCT from the table Employees.
alter table hr.employees drop column commission_pct;

-- QUESTION # 8 Write a SQL statement to add a foreign key constraint named Dept_id on employee table referencing to the primary key Dept_id of Deprartment table.
alter table hr.employees add (department_id number constraint dept_id_fk references hr.departments (department_id));