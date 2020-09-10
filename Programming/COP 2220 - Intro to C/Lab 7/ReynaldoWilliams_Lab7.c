//
//  main.c
//  Lab 7
//
//  Created by Rey on 4/12/20.
//  Copyright © 2020 Reynaldo Williams. All rights reserved.
//
//
#include <stdio.h>
#define SIZE 25
#define SIZE2 4

void Q1(void);
void Q2(void);
void Q3(void);

int main(void) {
  Q1();
  Q2();
  Q3();
  return 0;
}

void Q1(){
  //B
  double numfrac[SIZE] = {0};
  //C
  numfrac[13] = 6.666;
  //D
  numfrac[14] = -6.666;
  //E
  numfrac[9] = 1.667;
  //F - the wording of this left me unsure
  numfrac[6] = 3.33;
  //G
  printf("\n\t-----Printout 1G------\n");
  printf("Array element with index 14 is: %.2f.\n", numfrac[14]);
  printf("Array element with index 9 is: %.2f.\n", numfrac[9]);

  //H
  printf("\n\t-----Printout 1H------\n");
  for(int i = 0; i < SIZE; i++){
    printf("Index Numer: %d\tElement value: %.2f\n", i, numfrac[i]);
  }

  }

void Q2(){
  //A
  int intable[4][4];

  //B - It contains 16 elements (4 row * 4 columns)
  printf("\n\t-----Printout 2B------\n");
  printf("The size of the array, intable, using the sizeof() operator is: %lu\n", sizeof(intable)/sizeof(intable[0][0]));

  //C
  for(int i=0; i<SIZE2; i++){
    for(int j=0; j<SIZE2; j++){
        intable[i][j]= i+j;
    }
    }
  
  //D
  printf("\n\t-----Printout 2D------\n");
  printf("Array \"intable\" printout:\n");
    for(int h=0; h<SIZE2; h++){
    for(int m=0; m<SIZE2; m++){
        printf("%d ", intable[h][m]);
    }
        printf("\n");
    }
}
void Q3(){

//Orignal Code

/*
#include <stdio.h>; //Remove Semicolon
#define SIZE = 100; //Remove Semicolon
int b[ 10 ] = { 0 }, i; //Remove ", i"
for ( i = 0; i <= 10; i++ ) { //Remove "=" and declare i
b[ i ] = 1;
}
int a[ 2 ][ 2 ] = { { 1, 2, 3 }, { 3, 4 } }; //Remove the first 3 element
a[ 1, 1 ] = 5; //Change to two seperate brackets
*/

//Corrected Code
int b[ 10 ] = { 0 };
for(int i = 0;i < 10;i++){
b[i] = 1;
}

int a[2][2] = {{1,2}, {3,4}};
a[1][1] = 5;
}


