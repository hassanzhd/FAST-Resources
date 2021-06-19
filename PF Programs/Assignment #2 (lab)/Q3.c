#include<stdio.h>
float selection(float x, float y)
{	
	float fsc_per,nts_per; 
	fsc_per=(x/1100)*100;
	nts_per=(y/100)*100;

// UOK SELECTION:- 
	if(fsc_per>75.0 && nts_per>=70.0)
	{
		printf("\t\t\tUNIVERSITY OF KARACHI: \n\tYou can get admission in:\nIT: Yes\nElectronics: Yes\nTelecommunication: Yes");
	}
	
		else if((fsc_per>70.0) && (nts_per>=60.0 && nts_per<70.0))
	{
		printf("\t\t\tUNIVERSITY OF KARACHI: \n\tYou can get admission in:\nIT: No\nElectronics: Yes\nTelecommunication: Yes");
	}

		else if((fsc_per>70.0) && (nts_per>=50.0 && nts_per<60.0))
	{
		printf("\t\t\tUNIVERSITY OF KARACHI: \n\tYou can get admission in:\nIT: No\nElectronics: No\nTelecommunication: Yes");
	}
			
		else if((fsc_per<70.0) && (nts_per<50.0) || (fsc_per>70.0) && (nts_per<50.0) || (fsc_per<70.0) && (nts_per>50.0) )
	{
		printf("\t\t\tUNIVERSITY OF KARACHI: \n\tYou can get admission in:\nIT: No\nElectronics: No\nTelecommunication: No");
	}
			
	printf("\n");
	printf("\n");
	printf("\n");

// FAST university:-	
	if(fsc_per>=65.0 && nts_per>=50.0)
	{
		printf("\t\t\tFAST UNIVERSITY: \n\tYou can get admission in:\nComputer Science: Yes\nElectronics: Yes");
	}	
	
		else if((fsc_per>59.0 && fsc_per<65.0) && nts_per>=50.0)
	{
		printf("\t\t\tFAST UNIVERSITY: \n\tYou can get admission in:\nComputer Science: No\nElectronics: Yes");
	}	
		
		else if((fsc_per<59.0) && (nts_per<50.0) || (fsc_per>59.0) && (nts_per<50.0) || (fsc_per<59.0) && (nts_per>50.0))
	{
		printf("\t\t\tFAST UNIVERSITY: \n\tYou can get admission in:\nComputer Science: No\nElectronics: No");
	}	
}

main()
{
	float fsc_marks,nts_marks;
	printf("Enter your Fsc marks (out of 1100): ");
	scanf("%f", &fsc_marks);
	printf("Enter you NTS marks (out of 100): ");
	scanf("%f", &nts_marks);
	printf("\n");
	printf("\n");
	selection(fsc_marks, nts_marks);
}
