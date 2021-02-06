
#ifndef CPROJECT1_THEOBJECT_H
#define CPROJECT1_THEOBJECT_H
#include "project.h"

int speed;
int time;

struct position     /* Position of the current object*/
{
    int x;/* X position*/
    int y;/* Y position*/
    int angle;
};

struct position objpos;

int move(int speed,int time,char dir);
int rotate(char dir);
int setinitpos(int x,int y,int angle);



#endif //CPROJECT1_THEOBJECT_H
