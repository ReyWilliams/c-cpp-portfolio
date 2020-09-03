/*
Reynaldo Williams
COP 2220
Assignment 1
Feb. 11, 2020
*/


#include <stdio.h>
#include <math.h>

int main(void) {
  
/*Write a program that uses one printf() call to print your first name and last name on one line,
uses a second printf() call to print your first and last names on two separate lines, and uses a
pair of printf() calls to print your first and last names on one line. The output should look
similar to this:*/printf("Number 1\n\n");

printf("Reynaldo Williams\n");
printf("Reynaldo\nWilliams\n");
printf("Reynaldo");
printf(" Williams\n");

/*2- Write a program that creates an integer variable called toes.*/ printf("\n\nNumber 2\n\n");

int toes, toesTwice, toesSquared;
toes = 10;
toesTwice = 2*10;
toesSquared = pow(toes,2.0);

printf("The value of toes is: %d.\nThe value of toes twice is: %d.\nThe value of toes squared is: %d\n", toes, toesTwice, toesSquared);

/*3- Write a program to convert a temperature in degrees Fahrenheit to degrees Celsius*/printf("\n\nNumber 3\n\n");

int farTemp;
double celTemp;

printf("Enter the temperature (in Fahrenheit): ");
scanf("%d", &farTemp);

celTemp = (5.0/9.0)*(farTemp-32);

printf("The temperature, %d degrees Fahrenheit, is %.2f degrees Celsius.", farTemp, celTemp);

/*4- Write a program that computes the time it takes to cut the grass based on the size of the lawn.*/printf("\n\nNumber 4\n\n");

double yardLenth, yardWidth, hLenth, hWidth;
double yardArea, houseArea, lawnArea;
double timeNeeded;


printf("What is the length of the yard (in feet)?: ");
scanf("%lf", &yardLenth);
printf("What is the width of the yard (in feet)?: ");
scanf("%lf", &yardWidth);
printf("What is the length of the house (in feet)?: ");
scanf("%lf", &hLenth);
printf("What is the width of the house (in feet)?: ");
scanf("%lf", &hWidth);


houseArea = hLenth * hWidth;
yardArea = yardLenth * yardWidth;
lawnArea = yardArea - houseArea;
timeNeeded = (lawnArea/2.0);

printf("\nThe area of the lawn is %.2f square feet, it will take %.2f seconds to mow this lawn.", lawnArea, timeNeeded);

/*Write a program that estimates the temperature in a freezer (in °C) given the elapsed time (hours) since a power failure.*/
printf("\n\nNumber 5\n\n");

int timeSince;
int timeConvMins;
double timeConvHours;
double temp;

printf("Enter how long is has been since the start of the freezer power failure in whole hours and minutes. (Ex: 230 for 2 hours and 30 minutes): ");
scanf("%d", &timeSince);

timeConvMins = ((timeSince/100)*60) + (timeSince%100);
timeConvHours = (double)timeConvMins/60.0;
temp = ((4*pow(timeConvHours,2.0))/(timeConvHours+2)) - 20;

printf("The temperatrue of the freezer after %d minutes, or %.2f hours, is %.2f degrees Celsius.", timeConvMins, timeConvHours, temp);
  return 0;
}