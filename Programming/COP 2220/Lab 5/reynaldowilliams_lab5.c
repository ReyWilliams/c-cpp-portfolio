/*
Reynaldo Williams
COP 2220
Lab 5
March 21, 2020
*/

#include <stdio.h>
void Q1();
void Q2();
void Q3();


int main(void) {
  Q1();
  Q2();
  Q3();
  return 0;
  }

void Q1(){
  printf("\t----Q1 PRINTOUT----\n\n");
  int i = 1;
  double n;
  printf("Watch out! Here come a bunch of fractions!\n");

  while (i < 30){
    n = 1.0/i;
    printf(" %f\n", n);
    ++i;
    }
  printf("That's all, folks!\n");
  }

void Q2(){
  printf("\n\t----Q2 PRINTOUT----\n\n");
  int j = 0;
  int k = 1;

  while(j<7){
    printf("%d\t%d\n", j,k);
    ++j;
    k*=2;
    }
  }
void Q3(){
  printf("\n\t----Q3 PRINTOUT----\n\n");
  int count = 1;
  int sum = 0;
  int next_num;

    while(count<=5){
      printf("Next number> ");
      scanf("%d", &next_num);
      sum+=next_num;
      count+=1;
      }
  printf("%d numbers were added; \n", count-1);
  printf("their sum is %d.\n", sum);
  }