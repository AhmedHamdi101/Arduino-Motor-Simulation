/* trackfunction.c - createtrack, betweentrack*/
#include "project.h"
/*int updatetrack()
{
    struct track *trptr = &tracktab[currtrack];
    int tracknumber;
    if(trptr->eX == trptr->sX) {
        tracknumber = betweentrack('y');
        if (tracknumber != ERR) {
            printf("\n Track updated %d\n",tracknumber);
            currtrack = tracknumber;
            return OK;
        }
    }
    else if(trptr->eY == trptr->sY){
        tracknumber = betweentrack('x');
        if(tracknumber != ERR){
            printf("\n Track updated %d\n",tracknumber);
            currtrack = tracknumber;
            return OK;
        }
    }
    return ERR;
}*/
int betweentrack(int x, int y)
{
    int i ;
    struct track *trptr;
//    printf("called\n");
    for ( i = 0; i < Tsize; i++) {
//        printf("hi\n");
        trptr = &tracktab[i];
//        printf("\nobjX = %d , objY = %d",x,y);
//        printf("\nsx = %d ex = %d , sy = %d ey = %d\n",trptr->sX,trptr->eX,trptr->sY,trptr->eY);
        if(trptr->eX == trptr->sX){
            if(x == trptr->eX || x == trptr->eX+1 || x == trptr->eX - 1) {
                if (trptr->sY < trptr->eY) {
                    if (y >= trptr->sY - 1 && y <= trptr->eY + 1)
                        return OK;
                }else if(trptr->sY > trptr->eY){
                    if (y >= trptr->eY - 1 && y <= trptr->sY + 1)
                        return OK;
                }
            }

        }
        else if(trptr->eY == trptr->sY){
            if(y == trptr->eY || y == trptr->eY+1 || y == trptr->eY - 1){
                if (trptr->sX < trptr->eX){
                    if (x >= trptr->sX - 1 && x <= trptr->eX + 1)
                        return OK;
                }else if(trptr->sX > trptr->eX){
                    if (x >= trptr->eX - 1 && x <= trptr->sX + 1)
                        return OK;
                }
            }
        }
    }
    return ERR;
}
struct track createtrack(int sX,int eX,int sY,int eY)
{
    struct track trtemp;
    trtemp.sX = sX;
    trtemp.eX = eX;
    trtemp.sY = sY;
    trtemp.eY = eY;
    return trtemp;
}
int testingroad1()
{
    tracktab[0]= createtrack(2,2,0,5);
    tracktab[1]= createtrack(2,7,5,5);
    tracktab[2] = createtrack(7,7,5,10);
    return OK;

}