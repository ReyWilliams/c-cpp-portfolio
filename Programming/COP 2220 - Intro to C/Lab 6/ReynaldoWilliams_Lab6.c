/*
Reynaldo Williams
COP 2220
Lab 6
March 29, 2020
*/

#include <stdio.h>
#include <math.h>
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
  //A
  printf("\n\t----Question 1A Printout----\n\n");
  int x = 1;
  while(x<=10){ //Change semicolon to open bracket and define x as an integer
  printf("%d\n", x); //Test printout to ensure values are working and correct.
  x++;
  }

  //B
  printf("\n\t----Question 1B Printout----\n\n");
  for(double y=0.1; y<=1.0; y+=0.1) //Change loop repitition condition and define y
    printf("%f\n", y);
  
  //C
  printf("\n\t----Question 1C Printout----\n\n");

  int n;
  printf("Enter a value for n: "); //Test to check switch using user input
  scanf("%d", &n);

  switch(n){ //Add break after case 1 and define n
  case 1:
  printf("The number is 1\n");
  break;
  case 2:
  printf("The number is 2\n");
  break;
  default:
  printf("The number is not 1 or 2\n");
  break;
  }

  //D
  printf("\n\t----Question 1D Printout----\n\n");

  n = 1;
  while (n<=10) //change the while loop conditon to be less than or EQUAL TO 10
  printf( "%d ", n++ );

  //E
  printf("\n\n\t----Question 1E Printout----\n\n");

  int z, sum;
  sum = 0; //Declare z and sum, initialize sum;

  printf("Enter a value for z: "); //Test to check loop using user input
  scanf("%d", &z);

  while (z >= 0){
  sum += z; 
  z--; //Add update statement to make sure loop is not infinite
  }

  printf("Sum is equal to: %d",sum);

  //F
  printf("\n\n\t----Question 1F Printout----\n\n");

  for(int mult4 = 0; //Add parentheses, remove extra semicolon
  mult4 < 100;
  mult4 += 4)
  printf("%d\n", mult4);
  }

void Q2(){
  printf("\n\t----Question 2 Printout----\n\n");
  int n, m, p, i, j;
  i=17; //Birth day
  j=11; //Birth month

  n = ++i * --j; //The value assigned is one more than your birth day times one less than your birth month
  printf("At this step..\ni is: %d\nj is: %d\nn is : %d\n\n",i,j,n);


  m = i + j--; //The value assigned is one more than your birth day plus one less than your birth month
  printf("At this step..\ni is: %d\nj is: %d\nn is : %d\nm is: %d\n\n",i,j,n,m);


  p = i + j; //The value assigned is one more than your birth day plus two less than your birth month
  printf("At this step..\ni is: %d\nj is: %d\nn is : %d\nm is: %d\np is: %d\n\n",i,j,n,m,p);
  }
void Q3(){
  printf("\n\t----Question 3 Printout----\n\n");

  int k, low, high;
  printf("Enter the lower limit: ");
  scanf("%d", &low);
  printf("Enter the upper limit: ");
  scanf("%d", &high);
  
  printf("You've entered a range of %d through %d.\n\n", low, high);

  if(high>low){
      for(int k=low; k<=high; k++){
        printf("Integer: %d\tSquare: %d\tCube: %d\n", k, (int)pow(k,2), (int)pow(k,3));
      }
  }else{
    printf("Your limits were invalid.");
  }
  }
