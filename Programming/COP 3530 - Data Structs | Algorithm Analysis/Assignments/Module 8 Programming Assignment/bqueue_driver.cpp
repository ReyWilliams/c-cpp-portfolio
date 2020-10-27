#include<iostream>
#include "bqueue.h"
using namespace std;

/********************************************************************************************
Name: Reynaldo Williams	Z#: 23506395
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 10/27/20	Due Time: 11:59 PM
Total Points: 25 
Assignment 5: Module 8 Assignment

Description: Program that implements a doubly-linked circular queue of integers.
*********************************************************************************************/

int main(){
    bqueue k;
        k.enqueue(60);
        k.print();
        k.enqueue(20);
        k.enqueue(30);
        k.print();
        k.enqueue(10);
        k.print();
        k.enqueue(50);
        k.enqueue(40);
        k.print();
    bqueue j =k;
        j.dequeue();
        j.print();
        j.dequeue();
        j.dequeue();
        j.dequeue();
        j.print();
        j.dequeue();
        j.dequeue();
        j.print();
        j.dequeue();
        j.dequeue();
return 0;
}