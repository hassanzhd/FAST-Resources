-- Write a query in SQL to display the first name, last name, department number, and department name for each employee.
SELECT first_name, last_name,hr.employees.department_id, department_name FROM hr.employees RIGHT JOIN hr.departments ON hr.employees.department_id=hr.departments.department_id;

-- Write a query in SQL to display the first name of all employees and the first name of their manager including those who does not working under any manager.
SELECT a.first_name, b.first_name FROM hr.employees a, hr.employees b WHERE a.employee_id=b.manager_id;

-- Write a query in SQL to display the department name, full name (first and last name) of manager, and their city
SELECT department_name, first_name, last_name, city FROM hr.employees JOIN hr.locations ON hr.employees.location_id=hr.locations.location_id JOIN hr.departments ON hr.employees.department_id=hr.departments.department_id;

SELECT first_name, salary, department_name, city FROM hr.employees JOIN hr.locations ON hr.employees.location_id=hr.locations.location_id JOIN hr.departments ON hr.employees.department_id=hr.departments.department_id WHERE hr.locations.city<>'Oxford';

SELECT first_name,department_name,start_date FROM hr.employees JOIN hr.departments ON hr.employees.department_id=hr.departments.department_id JOIN hr.job_history ON hr.employees.employee_id=hr.job_history.employee_id WHERE hr.job_history.start_date='1-Jan-2007';