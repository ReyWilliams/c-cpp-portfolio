/*
Reynaldo Williams
COP 2220
Assignment 4
April 1 2020
*/

#include <stdio.h>
#define PI4 4.0
void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

int main(void) {
  Q1(); 
  Q2();
  Q3();
  Q4();
  Q5();
return 0;
}

void Q1(){
  printf("\n\t-----Q1 Printout-----\n\n");

  int count = 1;
  while(count<=(int)3e8){
    if(count%(int)1e8==0){
      printf("%d\n", count);
      }
    count++;
    }

  printf("\nThe first multiple takes: %.2f seconds\nThe second multiple takes: %.2f seconds\nThe third multiple takes %.2f seconds\n", 1.18, 1.39, 1.73); 
  }

void Q2(){
  printf("\n\t-----Q2 Printout-----\n\n");
    
  int n, sum, sum2;
  sum = 0;

  printf("Enter a value for n: "); 
  scanf("%d", &n);
  sum2 = (n*(n+1))/2;

  while (n >= 0){
    sum += n; 
    n--; 
    }

  if(sum==sum2){
    printf("B) The calculated sum is equal to the formula sum for n.\n");
    } 

  printf("C) The calculated sum is equal to the formula sum for all values for n\n");
  }
  
void Q3(){
  printf("\n\t-----Q3 Printout-----\n\n");

  double PI = 4;
  int count2=0;
    
  for(int count=3; count<=51; count+=2){
    count2++;
    if(count2%2==0)
    PI += PI4/count;
    else
    PI -= PI4/count;
    
    printf("PI approximated by %d term(s) is: %.6f\n", count2, PI);
  }

  printf("\nYou must use %d terms of this series before you first get 3.14.\nYou must use %d terms of this series before you first get 3.141.\nYou must use %d terms of this series before you first get 3.1415.\nYou must use %d terms of this series before you first get 3.14159.\n", 126, 1557, 10241, 146062);
}

void Q4(){
    printf("\n\t-----Q4 Printout-----\n\n");

    int pass = 1223;
    int tries = 4;
    int usPass;

    do{
      printf("Guess the four digit passcode: ");
      scanf("%d", &usPass);
      tries--;

      if(tries==0 && usPass!= pass){
        printf("You have unsuccessfully entered the pass within the allotted tries, you have been locked out.\n");

      //printf("You have %d tries left.\n\n", tries);
      }
      }while(tries > 0 && usPass!=pass);

      if(usPass==pass){
        printf("You've entered the correct passcode!\n");
      }
    }
void Q5(){
  printf("\n\t-----Q5 Printout-----\n\n");
  for(int j=0; j<6; j++){
      for(int k=0; k<=j; k++){
        printf("%d", k);
      }
      printf("\n");
  }
  for(int h=4; h>=0; h--){
      for(int m=0; m<=h; m++){
        printf("%d", m);
      }
      printf("\n");
  }
  }