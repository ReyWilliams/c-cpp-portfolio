/*
Reynaldo Williams
COP 2220
Assignment 5
May 2, 2020
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10
#define WordLen 25
#define SIZE2 50

void Q1(void);
void Q3(void);
void Q4(void);
void sum_n_avg(double db1, double db2, double db3, double *sumPtr, double *avgPtr);


int main(void) {
  Q1();
  //Q2
  printf("\n\t------Q2 Printout-------\n\n");
  double db1, db2, db3, sum3, avg3;
  printf("\nInput three numbers (seperated by comma): ");
  scanf("%lf,%lf,%lf", &db1, &db2, &db3);
  sum_n_avg(db1, db2, db3, &sum3, &avg3);
  printf("Their sum is: %.2lf.\nTheir average is: %.2lf.\n", sum3, avg3);

  Q3();
  Q4();
  
    return 0;
}

void Q1(){
  printf("\n\t------Q1 Printout-------\n\n");
  //A
  int A[SIZE][SIZE]= {0};
  for(int i = 0; i<SIZE; i++){
    for(int j= 0; j<SIZE; j++){
      if(i == j){
        A[i][j] = i*j;
      }
    }
  }

  //B
  for(int r = 0; r<SIZE; r++){
    for(int c= 0; c<SIZE; c++){
        printf("%d", A[r][c]);
      }
      printf("\n");
    }
  }

void sum_n_avg(double db1, double db2, double db3, double *sumPtr, double *avgPtr){
  *sumPtr = db1 + db2 + db3;
  *avgPtr = *sumPtr/3.0;
  }
void Q3(){
  printf("\n\t------Q3 Printout-------\n\n");

  char userWord[WordLen];
  while(userWord[0] != '#'){
  printf("\nEnter a word: ");
  scanf("%s", userWord);
  if(userWord[0] != '#')
  printf("User entered: %s.\n%s begins with '%c'.\n", userWord, userWord, userWord[0]);
  }
  userWord[0] = getchar(); //So that newline is not read by Q4
  }
void Q4(){
  printf("\n\t------Q4 Printout-------\n\n");

  char userString[SIZE2];
  printf("Enter a string: \n");


  fgets((userString),SIZE2, stdin);

  for(int i = 0; i<strlen(userString); i++){
    if(isspace(userString[i]) || ispunct(userString[i])){
      userString[i] = '_';
    }
  }

  printf("\nThe returned string is:\n%s\n", userString);

}
