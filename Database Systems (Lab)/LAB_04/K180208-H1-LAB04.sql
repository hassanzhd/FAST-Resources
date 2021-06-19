-- display all department names along with number of employees
select COUNT(employee_id) as number_of_employees,
department_id
from hr.employees
group by hr.employees.department_id;

-- Write a query in SQL to display the first and last name and salary for those employees who earn less than the employee earn whose number is 182
select first_name, last_name, salary
from hr.employees
where hr.employees.salary < (select salary from hr.employees where hr.employees.employee_id=182);

-- Write a query in SQL to display the first name, last name, and department number for those employees who works in the same department as the employee who holds the last name as Taylor.
select first_name, last_name, department_id 
from hr.employees
where hr.employees.department_id in (
select department_id from hr.employees where hr.employees.last_name='Taylor'
);

-- Write a query in SQL to display the name of the department, average salary and number of employees working in that department who got commission.
select department_id, AVG(salary) , COUNT(*)
from hr.employees
where department_id in (
select department_id from hr.employees where commission_pct!=0
);