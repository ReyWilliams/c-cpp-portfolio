/*
Reynaldo Williams
COP 2220
Lab 3
Feb 18, 2020
*/

#include <stdio.h>
#define galInLit 3.785
#define milInKilom 1.609

//Function prototyping
void Q1(void);
void car(void);
void deny(void);
void Q2(void);
void Q3(void);
double mpgTolphk(double miles, double gallons);

int main(void) {
  //Question 1 Function Call
  Q1();

  //Question 2 Function Call
  Q2();

  //Question 3 Function Call
  Q3();

}

void Q1(void){
 car();
 printf("\t");
 car();
 printf("\t");
 printf("\t");
 car();
 printf("\t");
 printf("\t");
 printf("\t");
 printf("\t");
 printf("\t");
 deny();
}
void car(void){
 printf("For that's a beautiful car!\n");
}
void deny(void){
  printf("Which nobody can deny.");
}
void Q2(void){
  printf("\n\n");
  double numMiles, numGals, MPG;
  double numKilo, numLits, LPHK;

  //Prompts user to enter the number of miles traveled
  printf("Enter the number of miles traveled: "); 
  scanf("%lf", &numMiles);
  numKilo = numMiles * milInKilom;

  printf("Enter the number of gallons of gasoline consumed: ");
  scanf("%lf", &numGals);
  numLits = numGals * galInLit;

  MPG = numMiles/numGals;
  LPHK = numLits/(numKilo/100);
  printf("Your calculated MPG is: %.1f miles-per-gallon.\n", MPG);
  printf("Your calculated LPHK is: %.2f liters-per-100-km.", LPHK);
}
void Q3(void){
  printf("\n\n");
  double myCarLPHK = mpgTolphk(300.0, 10.0);
  printf("Car Info\n");
  printf("Make: Honda\nModel: Civic\nGas Milage (in LPHK): %.2f liters-per-100-km", myCarLPHK);
  
}
double mpgTolphk(double miles, double gallons){
  double kilo = miles * milInKilom;
  double lits = gallons * galInLit;

  double lphk = lits/(kilo/100);
  return lphk;
}
