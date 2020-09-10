/*
Reynaldo Williams
COP 2220 - Intro to C
Lab 4
Feb. 27, 2020
*/

//Function Prototyping
void Q1();
  void Q1A();
  void Q1B();
double Q2(int n, int sum);
void Q3();
int Q4(int num1, int num2);

#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int main(void) {
  //Question 1 Function Call
  Q1();


  //Question 2 Function Call
  double Q2Result = Q2(12, 569);
  printf("The value of  function Q2 is: %.2f.\n\n", Q2Result);

  //Question 3 Function Call
  Q3();

  //Question 4 Function Call
  int Q4Result = Q4(5,3);
  printf("The value of  function Q4 is: %d.\n", Q4Result);

  return 0;
}

void Q1(){
printf("Question 1 Printout:\n");
Q1A();
Q1B();

printf("\n"); //Keeps code organized to allow grader to effectively seen printouts. 
printf("\n");
}

void Q1A(){
/*This piece of code uses the value of age to calculate whethere of not that value is greater than or equal to, or less than, 65. The erros within in the code were than the condtitional statement age >= 65 was missing parentheses and also incorrectly had a semicolon after it. The variable age was also not declared nor initialized.*/

  srand(time(0));
  int age = (rand() % (100 - 40 + 1)) + 40;  //Generates a random integer  for age within range [40,100]
  printf("Test value age is equal to: %d.\n", age); //Used to print out test value of age

  if(age >= 65)
    printf("Age is greater than or equal to 65.\n");
  else
    printf("Age is less than 65\n");

printf("\n"); //Keeps code organized to allow grader to effectively seen printouts. 
}

void Q1B(){
/*This piece of code mimicks a that of a bank account and uses an if statement to decide whether a person has enough money in their account for a desired deduction. If they have enough, the deduction is made and a new balance is calculated, if not then the user is informed that the deduction would result in an overdraft as they do not have sufficient funds. The errors of this function include the misplacement of semicolons after if the if and else statement as well as the absence of brackets ({}) that would enable the if/else control structure to run both lines of code following the if and the else. Variables deduct and balance were also neither declared nor initialized to be used effectively in the if/else control structure.*/
  double deduct, balance;
  deduct = 12.78;
  balance = 20.00;
  
  printf("Beginning balance: %.2f.\n", balance);

 if(deduct < balance){
   balance = balance - deduct;
   printf("New balance is: %.2f.\n", balance);
 }
 else{
   printf("Deduction of %.2f refused.\n", deduct);
   printf("Would overdraw account.\n");
 }
 printf("Deduction = %.2f Final Balance = %.2f", deduct, balance);

 printf("\n"); //Keeps code organized to allow grader to effectively seen printouts. 
}

double Q2(int n, int sum){
printf("Question 2 Printout:\n");

printf("The value of n is: %d.\nThe value of sum is: %d.\n", n, sum);

double avg;
if(n>0)
  avg = sum/n;
else
  avg = -1;

  return avg;

printf("\n"); //Keeps code organized to allow grader to effectively seen printouts. 
printf("\n");
}

void Q3(){
printf("Question 3 Printout:\n");

double x,y,z,p;
printf("Enter three numbers, use format (x,y,z):"); //Prompts user to enter 3 numbers
scanf("(%lf,%lf,%lf)",&x,&y,&z); //Assigns entered values to variables. 
p = x+y+z; //Assigns the sum of the variables x, y, and z to variable P

if((p > (2*z)) || ((p < (x*y)) && (p =! 0))){
 printf("The condition is true.");
  }else{
    p = 100;
    printf("The condition is false, a value of 100 has been assigned to p.");
  }

printf("\n"); //Keeps code organized to allow grader to effectively seen printouts. 
printf("\n");

}

int Q4(int num1, int num2){
  printf("Question 4 Printout:\n");

  printf("The value of num1 is: %d.\nThe value of num2 is: %d.\n", num1, num2);

  if(num1 > num2)
    num2 = num1 - num2;
  else
    num2 = num2 - num1;

    return num2;
}
