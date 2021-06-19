#include <stdio.h>
main ()

{	int i,number_of_students,studentcount,student_id,student_grades,A,B,C,D,F;
	char grade;
	A=0; B=0; C=0; D=0; F=0;
	printf("		***********************************************			");
	printf("		PROGRAM TO CALCULATE GRADES OF STUDENTS ENTERED			");
	printf("		***********************************************			\n");
	printf("                                                                \n");
	printf("Enter Number Of Students: ");
	scanf("%d", &number_of_students);
	
	studentcount=0;				//90-100 A,78-89 B,65-77 C, 50-64 is D, below 50 is an F.
	i=1;
	while (i<=number_of_students) 
	{	i++;
		studentcount=studentcount+1;
		printf("\nEnter Student Id Of Student #%d: ", studentcount);
		scanf("%d", &student_id);
		printf ("Enter Grades Of Student #%d: ", studentcount);
		scanf("%d", &student_grades);
								
								
			if (student_grades>=90 && student_grades<=100)
					
						{	
							A= A+1;
							grade= 'A';
							printf("\n\n****************");
							printf("\nStudent Id #%d			\nGrade: %c\n", student_id, grade);
							printf("****************\n");
							 }	
							 	
							else if (student_grades>=78 && student_grades<=89)
						{	
							B=B+1;
							grade= 'B';
							printf("\n\n****************");
							printf("\nStudent Id #%d			\nGrade: %c\n", student_id, grade);
							printf("****************\n");
							 }
							 
							else if (student_grades>=65 && student_grades<=77)
						{	
							C=C+1;
							grade= 'C';
							printf("\n\n****************");
							printf("\nStudent Id #%d			\nGrade: %c\n", student_id, grade);
							printf("****************\n");
							 }	
							
							else if (student_grades>=50 && student_grades<=64)
						{	
							D=D+1;
							grade= 'D';
							printf("\n\n****************");
							printf("\nStudent Id #%d			\nGrade: %c\n", student_id, grade);
							printf("****************\n");
							 }
							else if (student_grades<50)
						{	
							F=F+1;
							grade= 'F';
							printf("\n\n****************");
							printf("\nStudent Id #%d			\nGrade: %c\n", student_id, grade);
							printf("****************\n");
							 }			
			else {
			
				printf("You have entered incorrect marks. Please try again\n");
			
					}				 	
							 
		}
	
	
	printf("\nTotal number of A's: %d\n", A);				 
	printf("Total number of B's: %d\n" , B);
	printf("Total number of C's: %d\n" , C);
	printf("Total number of D's: %d\n" , D);
	printf("Total number of F's: %d\n" , F);										 
							 
	
	
	
	
	
	
	
}
