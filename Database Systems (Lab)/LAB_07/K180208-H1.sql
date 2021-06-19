SET SERVEROUTPUT ON;

-- Q:1

DECLARE
    a INTEGER;
    b INTEGER;
    sums INTEGER;
BEGIN
    a:=&a;
    b:=&b;
    sums:=a+b;
    dbms_output.put_line('SUM: '|| sums);
END;
/


-- Q:2

DECLARE
LOWER INTEGER;
UPPER INTEGER;

BEGIN
LOWER := &LOWER;
UPPER := &UPPER;
FOR i in LOWER+1 .. UPPER-1 LOOP
    dbms_output.put_line('i = ' || i);
END LOOP;
END;


-- Q:3 Write a PL/SQL code to retrieve the employee name, hiredate, and the department name in which he works, whose number is input by the user.

DECLARE
    employee_number INTEGER;
    fname varchar(100);
    lname varchar(100);
    hdate Date;
    dname varchar(100);

BEGIN
    employee_number:=&employee_number;
    SELECT FIRST_NAME,LAST_NAME,HIRE_DATE,DEPARTMENT_NAME INTO fname,lname,hdate,dname FROM HR.EMPLOYEES JOIN HR.DEPARTMENTS ON HR.EMPLOYEES.department_id=HR.DEPARTMENTS.department_id WHERE EMPLOYEE_ID=employee_number;
    dbms_output.put_line(': '|| fname);
END;
/


-- Q:4
DECLARE
NUM INTEGER;
DUMMY INTEGER;
J INTEGER;
DIGIT INTEGER;
BEGIN
NUM := &NUM;
DUMMY := NUM;
J := 0;
DIGIT := 0;
WHILE NUM!=0 LOOP
    DIGIT := MOD(NUM,10);
    J:= (J*10)+ DIGIT;
    NUM := NUM/10;
END LOOP;

IF ( DUMMY = J ) THEN
    dbms_output.put_line('THE NUMBER IS A PALINDROME' );
ELSE
    dbms_output.put_line('THE NUMBER IS NOT A PALINDROME' );
END IF;
END;


-- Q:5 Write a PL/SQL code that takes all the required inputs from the user for the Employee table and then insert it into the Employee and Department table in the database.


DECLARE
eid HR.EMPLOYEES.EMPLOYEE_ID%type;
fname HR.EMPLOYEES.FIRST_NAME%type;
lname HR.EMPLOYEES.LAST_NAME%type;
electronicMail HR.EMPLOYEES.EMAIL%type;
pno HR.EMPLOYEES.PHONE_NUMBER%type;
hdate HR.EMPLOYEES.HIRE_DATE%type;
jid HR.EMPLOYEES.JOB_ID%type;

BEGIN
    eid:=&eid;
    fname:=&fname;
    lname:=&lname;
    electronicMail:=electronicMail;
    pno:=&pno;
    jid:=&jid;
    
    INSERT INTO HR.EMPLOYEES VALUES (eid,fname,lname,electronicMail,pno,sysdate,jid);
END;
/



