#include <stdio.h>
main()
{	float lengthofroom, widthofroom, heightofroom, gallon;
	float length_of_window1, width_of_window1, length_of_window2, width_of_window2;
	float Area_of_wall_1, Area_of_wall_2, wall_Area, Area_of_window1, Area_of_window2, window_Area, total_Area ;
	
	printf("\t\tPROGRAM TO CALCULATE AMOUNT OF PAINT REQUIRED.\n");
	printf("\t\t**********************************************\n");
	printf("                                              \n");
	printf("Enter Length Of Room: ");
	scanf("%f",&lengthofroom);
	printf("Enter Width Of Room: ");
	scanf("%f",&widthofroom);
	printf("Enter Height Of Room: ");
	scanf("%f", &heightofroom);
	printf("Enter Length Of Window1: ");
	scanf("%f", &length_of_window1);
	printf("Enter Width Of Window1: ");
	scanf("%f", &width_of_window1);
	printf("Enter Length Of Window2: ");
	scanf("%f", &length_of_window2);
	printf("Enter Width Of Window2: ");
	scanf("%f", &width_of_window2);
	Area_of_wall_1 = 2*(lengthofroom*heightofroom);
	Area_of_wall_2= 2*(widthofroom*heightofroom);
	wall_Area = (Area_of_wall_1 + Area_of_wall_2);
	Area_of_window1 = (length_of_window1*width_of_window1);
	Area_of_window2 = (length_of_window2*width_of_window2);
	window_Area = (Area_of_window1+Area_of_window2);
	total_Area = (wall_Area-window_Area);
	gallon = (total_Area/100);
	printf("Total Area Is %f\n", total_Area);
	printf("The Amount Of Paint Required Is: %f Gallons", gallon);
	
	
	
}
