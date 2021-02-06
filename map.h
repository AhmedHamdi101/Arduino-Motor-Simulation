#ifndef CPROJECT1_MAP_H
#define CPROJECT1_MAP_H
#include "project.h"

#define OK 1
#define ERR -1
#define TRUE 1
#define FALSE 0

#ifndef Tsize
#define Tsize 3 /* Max size of the Track*/
#endif


int length;/* Length of the map*/
int width;/* Width of the map*/
int currtrack;

struct track
{
    int sX;     /* Start X*/
    int eX;     /* End X*/
    int sY;     /* Start Y*/
    int eY;     /* End Y*/
};


struct track tracktab[Tsize];
int updatetrack();
struct track createtrack(int sX,int eX,int sY,int eY);
int testingroad1();
int intializemap();
int isbadpos(int x,int y);
int createmap(int len,int wid);
int betweentrack(int x,int y);
#endif //CPROJECT1_MAP_H
