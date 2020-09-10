/*
Reynaldo Williams
COP 2220
March 18 2020
Assignment 3
*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

void Q1();
double findFact(int n1);
void Q2a();
void Q2b();
void Q3();
double BMI(double h, double w);
void Q4();
void cordFunc(double x, double y);
void Q5a();
void Q5b();
void Q5c();

int main(void) {
  Q1();
  Q2a();
  Q2b();
  Q3();
  Q4();
  Q5a();
  Q5b();
  Q5c();

  return 0;
}

void Q1(){
  printf("\t----Q1 PRINTOUT----\n\n");

  int n;
  printf("Enter an integer(n): ");
  scanf("%d",&n);
  double fact = findFact(n);
  printf("%d! equals approximately %.5f", n, fact);}
double findFact(int n1){
  double res;
  if(n1>0){
    res = ((pow(n1,n1) * pow(exp(1),-n1)) * sqrt(((2*n1)+(1.0/3.0))*PI));
  }else{
    res = 1;
  }
  return res;}
void Q2a(){
  printf("\n\n\t----Q2a PRINTOUT----\n\n");

 int watts;
 int lumens;
 printf("Enter the number of watts: ");
 scanf("%d", &watts);

 switch(watts){
   case 15:
    lumens = 125;
    break;
   case 25:
    lumens = 215;
    break;
   case 40:
    lumens = 500;
    break;
   case 60:
    lumens = 880;
    break;
   case 75:
    lumens = 1000;
    break;
   case 100:
    lumens = 1675;
    break;
    default:
    lumens = -1;
 }

 printf("For a light bulb with %d watts, the expected brightness(in lumens) is: %d", watts, lumens);
 }



void Q2b(){
  printf("\n\n\t----Q2b PRINTOUT----\n\n");
  int lumensb, wattsb;
  printf("Enter the number of watts: ");
  scanf(" %d", &wattsb);

  if(wattsb==100){
    lumensb=1675;
  }else if(wattsb==75){
    lumensb=1000;
  }else if(wattsb==60){
    lumensb=880;
  }else if(wattsb==40){
    lumensb=500;
  }else if(wattsb==25){
    lumensb=215;
  }else if(wattsb==15){
    lumensb=125;
  }else{
    lumensb=-1;
  }

    printf("For a light bulb with %d watts, the expected brightness(in lumens) is: %d", wattsb, lumensb);}  
void Q3(){
  printf("\n\n\t----Q3 PRINTOUT----\n\n");
  double height, weight;

  printf("Enter the height (in inches) and weight (in pounds).\nFormat - (Height,Weight): ");

  scanf(" (%lf,%lf)", &height, &weight);
  double userBMI = BMI(height, weight);

  printf("For a height of %.1f inches and a weight of %.1f pounds, the calculated BMI is %.2f. ", height, weight, userBMI);

  if(userBMI >= 30){
   printf("Weight status is obese.");
  }else if(userBMI >= 25.0 && userBMI <= 29.9){
    printf("Weight status is overweight.");
  }else if(userBMI >= 18.5 && userBMI <= 24.9){
    printf("Weight status is normal.");
  }else{
   printf("Weight status is underweight.");
  }
 }

 double BMI(double h, double w){
   double result = (703.0 * w)/(pow(h,2.0));
   return result;
 }

void Q4(){
  printf("\n\n\t----Q4 PRINTOUT----\n\n");
  double xp, yp;
  printf("Enter the x and y coordinates of the point.\nFormat - (x,y): ");
  scanf(" (%lf,%lf)",&xp,&yp);
  cordFunc(xp,yp);}
void cordFunc(double x,double y){
  if(x==0 && y==0){
  printf("(%.1f,%.1f) is on the origin", x,y);
  }else if(x==0){
    printf("(%.1f,%.1f) is on the y-axis", x,y);
  }else if(y==0){
    printf("(%.1f,%.1f) is on the x-axis", x,y);
  }else if(x>0 && y>0){
    printf("(%.1f,%.1f) is in quadrant I", x,y);
  }else if(x>0 && y<0){
    printf("(%.1f,%.1f) is in quadrant IV", x,y);
  }else if(x<0 && y>0){
    printf("(%.1f,%.1f) is in quadrant II", x,y);
  }else{
    printf("(%.1f,%.1f) is in quadrant III", x,y);
  }}

void Q5a(){
  printf("\n\n\t----Q5a PRINTOUT----\n\n");
int x=5,y=8;

//No modification is necessary
if(y==8)
if(x==5)
printf( "@@@@@\n" );
else
printf( "#####\n" );
printf( "$$$$$\n" );
printf( "&&&&&\n" );
}
void Q5b(){
  printf("\n\n\t----Q5b PRINTOUT----\n\n");
int x=5,y=8;

if(y==8)
if(x==5){
printf( "@@@@@\n" );
}else{
printf( "#####\n" );
printf( "$$$$$\n" );
}
printf( "&&&&&\n" );
}
void Q5c(){
  printf("\n\n\t----Q5c PRINTOUT----\n\n");
int x=5,y=7;

if(y==8){
if(x==5)
printf( "@@@@@\n" );
}
else{
printf( "#####\n" );
}
printf( "$$$$$\n" );
printf( "&&&&&\n" );
}

