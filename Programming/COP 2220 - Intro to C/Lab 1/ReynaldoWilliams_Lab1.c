/*Reynaldo Williams
Lab 1
January 30, 2020
*/

/* 1 - - Correct the syntax errors in the following program, and rewrite the program so that it follows
the proper style conventions. What does the program do? (Write it out as a comment). */

//This program takes two input integer values and stores them in two variables, x and y, and stores the sum of the two integars in a variable, sum, which is then used to output the three values in a printout. 

#include <stdio.h>
int main(){
  // Calculate and display the sum of two values
  int X; // first input value 
  int x; // secondinput value
  int sum; // sum of inputs

  X=9;
  x=(int)7.5;
  
  sum = X+x;
  printf("%d + %d = %d\n",X,x,sum);

/* 2 - In the same main function as above, and right below the first question, before the return (0);
statement, write another program that calculates the average of 3 numbers.*/

int val1, val2, val3;
double average;
val1 = 7;
val2 = 9;
val3 = 12;

average = ((double)(val1+val2+val3)/3);

printf("The average for the three values %d, %d, and %d is %f. ", val1, val2, val3, average);


return (0);}