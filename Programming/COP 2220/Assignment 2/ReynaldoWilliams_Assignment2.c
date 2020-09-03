/*
Reynaldo Williams
COP 2220
Assignment 2 
Feb. 21, 2020
*/

#include <stdio.h>
#include <math.h>
#define sinMol 3e-23; //defines the mass of a single molecule of water (in grams)
#define qrtWat 950 //defines the mass of a quart of water (in grams)

//Function prototypes
void Q1(void); 
void Q2(void);
void Q3(void);
void Q4(void);
void Q5(void);
void two(void);
void one_three(void);
void sm(void);

int main(void) {
  Q1(); //Function call for Q1

  Q2(); //Function call for Q2

  Q3(); //Function call for Q3

  Q4(); //Function call for Q4

  Q5(); //Function call for Q5
 
  return 0;
}

//Fucntion definitions
void Q1(void){ //Function that uses sm() function to print smile
printf("Number 1 printout\n");
  sm();
  sm();
  sm();
  printf("\n");
  sm();
  sm();
  printf("\n");
  sm();

  printf("\n");
  printf("\n");
}
void sm(void){ 
  printf("Smile!");
}
void Q2(void){
  printf("Number 2 printout\n");
  printf("\a"); //Beep sound
  printf("So excited that she shouted, \"What a wonderful day full of sweets, flowers, and love! Wishing you all the best this Valentine’s Day. \"");

  printf("\n");
  printf("\n");
}
void one_three(void){
  printf("one\n");
  two();
  printf("three\n");
}
void two(void){
  printf("two\n");
}
void Q3(void){
  printf("Number 3 printout\n");
  printf("starting now:\n");
  one_three();
  printf("done!");

  printf("\n");
  printf("\n");
}
void Q4(void){
  printf("Number 4 printout\n");
  int x1,x2,y1,y2,z1,z2;
  double dist;
  printf("Enter the coordinates for two 3D points\n");
  printf("Enter the coordinates for the first object now as integers, use format x,y,z: "); //Prompts user to input first point.
  scanf("%d,%d,%d", &x1,&y1,&z1);
  printf("You've entered [%d,%d,%d] as the first point.\n", x1,y1,z1); //Gives user feedback  for input of first point.
  printf("Enter the coordinates for the second object now as integers, use format x,y,z: "); //Prompts user to input second point.
  scanf("%d,%d,%d", &x2,&y2,&z2);
  printf("You've entered [%d,%d,%d] as the second point.\n", x2,y2,z2); //Gives user feedback for input of second point.

  dist= sqrt(pow((x1-x2),2) + pow((y1-y2),2) + pow((z1-z2),2)); //distance calculation

  printf("\n");
  printf("The distance between the points is: %.2f units\n", dist); //printout

  printf("\n");
  printf("\n");
}
void Q5(void){
  printf("Number 5 printout\n");
  double numQuarts, numGrams, numMol;
  printf("Please enter the amount of water (in quarts): ");
  scanf("%lf", &numQuarts);
  numGrams = numQuarts*qrtWat;
  numMol = numGrams/sinMol;
  printf("The amount of water molecules is: %.2e.", numMol);

  printf("\n");
  printf("\n");


}