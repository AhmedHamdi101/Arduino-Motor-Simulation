#ifndef CPROJECT1_QUEUE_H
#define CPROJECT1_QUEUE_H
#include "project.h"

#define MAX 50
int intArray[MAX];
int front;
int rear;
int itemCount;

int initializequeue();
int peek();
bool isEmpty();
bool isFull();
int size();
void insert(int data);
int removeData();

#endif //CPROJECT1_QUEUE_H
