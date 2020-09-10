/*
Reynaldo Williams
Lab 8
COP 2220
April 26, 2020
*/

#include <stdio.h>
#define SIZE 5

void Q1(void);
void Q3(void);

void zero(double bigNums[]){
  printf("\nFucntion zero\n");
}
int add1AndSum(int oneTooSmall[]){
  printf("Fucntion add1AndSum\n");
  return oneTooSmall[0];
}

int main(void) {
  Q1();
  Q3();



  /* Question 2 - Was Unsure how to go about doing some of this but I tried my best to answer the questions as best as I could. The instructions said to do these in the main function, but I defined the functions outside because C does not allow functions to be defined within one another. */

  double array1[SIZE] = {0};
  int array2[SIZE] = {0};

  //A
  void zero(double bigNums[]);

  //B
  zero(array1);

  //C
  int add1AndSum(int oneTooSmall[]);

  //D
  int sum = add1AndSum(array2);
}

void Q1(){
  //A
  int apples[SIZE] = {2,4,6,8,10};
  //B
  int *aPtr;
  //C
  for(int i = 0; i< SIZE; i++){
    printf("apples[%d]: %d\n", i, apples[i]);
  }

  //D
  aPtr = &apples[0];
  printf("\n{aPtr = &apples[0]}\nThis results in: %d\n", *aPtr);

  aPtr = apples;
  printf("\n{aPtr = apples}\nThis results in: %d\n\n", *aPtr);

  //E
  printf("The address aPtr is pointing to is: %p\n\n", aPtr);

  //F
  for(int j=0; j<SIZE; j++){
    printf("apples[%d]: %d\n", j, *(aPtr + j));
  }
  //G
  printf("\nThe address that is referenced by {aPtr + 3} is: %p.\nThis is the address of the fourth element of the array.\n", (aPtr+3));
  printf("The value stored at that location is: %d\n\n", *(aPtr+3));

  //F
  aPtr = &apples[4];
    aPtr -= 4;
    
  printf("Assuming aPtr points to apples[4], the address that is referenced by {aPtr -= 4} is: %p.\nThis is the address of the first element of the array.\nThe value stored at this location is: %d.\n\n", aPtr, *aPtr);
}

void Q3(){

  double number1 = 7.3, number2;
  //A
  double *fPtr;
  //B
  fPtr = &number1;
  //C
  printf("The value of the object pointed to by fPtr is: %.1f.\n\n", *fPtr);
  //D
  number2 = *fPtr;
  //E
  printf("The value of number2 is: %.1f.\n\n", number2);
  //F
  printf("\t{&number1}\nThe address of number1 is: %p.\n", &number1);
  //G
  printf("\t{fPtr}\nThe address of number1 is: %p.\n", fPtr);
    printf("These values are the same.");

  }
