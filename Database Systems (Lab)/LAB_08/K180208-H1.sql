-- VIEWS

CREATE OR REPLACE VIEW ACCOUNTING_EMPLOYEES as SELECT * FROM HR.EMPLOYEES WHERE DEPARTMENT_ID=(SELECT DEPARTMENT_ID FROM HR.DEPARTMENTS WHERE DEPARTMENT_NAME='Accounting');

SELECT * FROM ACCOUNTING_EMPLOYEES;

-- CURSORS (1)

SET SERVEROUTPUT ON;
DECLARE
cursor employee_cursor is SELECT * from hr.employees where salary>2000;
BEGIN
FOR v_emp IN employee_cursor LOOP
DBMS_OUTPUT.PUT_LINE(v_emp.employee_id || ' ' || v_emp.first_name || ' ' || v_emp.last_name || ' ' || v_emp.salary);
END LOOP;
END;
/

SELECT * from hr.employees where salary>2000;

-- CURSORS (2)

SET SERVEROUTPUT ON;
DECLARE
cursor employee_cursor is SELECT * from hr.employees;
temp_cursor employee_cursor%rowtype;

BEGIN
OPEN employee_cursor;
FOR i IN 1 .. 10 LOOP
FETCH employee_cursor into temp_cursor;
DBMS_OUTPUT.PUT_LINE(temp_cursor.employee_id || ' ' || temp_cursor.first_name || ' ' || temp_cursor.last_name || ' ' || temp_cursor.salary);
END LOOP;
END;
/

SELECT * from hr.employees;

-- PROCEDURE

CREATE OR REPLACE PROCEDURE sumOfTwoNumbers (firstNumber IN NUMBER, secondNumber IN NUMBER, summation OUT NUMBER)  
AS 
BEGIN 
    summation:=firstNumber+secondNumber;
END;
/

SET SERVEROUTPUT ON;
DECLARE
firstNumber number; 
secondNumber number; 
summation number;

BEGIN
firstNumber:=1;
secondNumber:=2;
sumOfTwoNumbers(firstNumber,secondNumber,summation);
dbms_output.put_line('SUM: ' ||  summation);

END;
/
