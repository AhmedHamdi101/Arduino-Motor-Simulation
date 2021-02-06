/* map*/
#include "project.h"

int intializemap()
{
    currtrack = 0;
    createmap(100,100);
    testingroad1();
    setinitpos(2,0,90);

}
int  createmap(int len,int wid)
{
    length = len;// Change the map length
    width  = wid; // Change the map width
    currtrack = 0;
    return OK;
}
