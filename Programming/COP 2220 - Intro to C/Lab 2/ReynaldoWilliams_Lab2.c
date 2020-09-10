/*
Reynaldo Williams
COP 2220
Lab 2
Feb. 06, 2020
*/


#include <stdio.h>
#include <math.h>
#define PI 3.14
#define mileRate 0.35

int main(void) {

/* 1 - Write a program that given the radius, computes the area and circumference of a circle,
as well as the volume of a sphere that is built with that circle*/

//Declarations
char circName;
double radius, area, circum, vol;

//Gets user input for cicle name (circName)
printf("Enter a single character to represent your circle: ");
scanf("%c", &circName); //stores circle name
printf("Great! Your circle, %c, is ready to be formatted!\n\n", circName);

//Gets user input for circle radius (radiis)
printf("Enter the desired radius for your circle (in inches): ");
scanf("%lf", &radius); //stores radius value
printf("You've entered %.2f inches as your circle %c's radius!. Thank you!\n\n", radius, circName);

//Calculations
area = PI*(pow(radius,2.0));
circum = 2*(PI*radius);
vol = ((double)(4/3))*PI*pow(radius, 3.0);

//Printout
printf("The area of your circle, %c, is: %.2f sqaure inche(s).\nThe circumfrience of your circle, %c, is: %.2f inche(s).\nThe volume of your cicle, %c, is: %.2f cubic inche(s).\n\n", circName, area, circName, circum, circName, vol);



/* 2- Write a program that calculates mileage reimbursement for a salesperson that travels
for work at a rate of $.35 per mile. */
  
double initialRead;
double finalRead;
double trvlDist;
double reImb;

printf("Enter beginning odometer reading: ");
scanf("%lf", &initialRead); //Stores initial reading
printf("You have entered %.1f miles as your initial odometer reading.\n", initialRead);

printf("Enter ending odometer reading: ");
scanf("%lf", &finalRead); //Stores final reading
printf("You have entered %.1f miles as your final odometer reading.\n\n", finalRead);

trvlDist = finalRead - initialRead; //Calculates distance traveled
reImb = trvlDist * mileRate;

printf("You travaled %.1f miles during your trip. At $%.2f per mile, your reimbursement is $%.2f", trvlDist, mileRate, reImb);



  return 0;
}