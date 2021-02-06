/* move.c , move ,setinitpos,*/
#include "project.h"
int setinitpos(int x,int y,int angle)
{
    if(!isbadpos(x,y))
        return ERR;
    objpos.x    = x;
    objpos.y    = y;
    objpos.angle = angle;
}
int isbadpos(int x,int y)
{
    if(x < 0 || x > width)
        return ERR;
    if(y < 0 || y > length)
        return ERR;

    if(betweentrack(x,y) == ERR) {
        return ERR;
    }

    return OK;

}

int move(int speed,int time,char dir)
{
    char newdir;
    if (dir == 'f' ){
        if(objpos.angle == 0)
            newdir = 'r';
        else if(objpos.angle == 90)
            newdir = 'u';
        else if(objpos.angle == 180)
            newdir = 'l';
        else if (objpos.angle == 270 )
            newdir = 'd';
    }
    else if(dir == 'b'){
        if(objpos.angle == 0)
            newdir = 'l';
        else if(objpos.angle == 90)
            newdir = 'd';
        else if(objpos.angle == 180)
            newdir = 'r';
        else if (objpos.angle == 270 )
            newdir = 'u';
    }
    int remaintime = time;
    switch (newdir)
    {

        case 'u':
            printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
            while(remaintime > 0)
            {

                sleep(speed);
                objpos.y = objpos.y + 1;
                if(isbadpos(objpos.x,objpos.y) == ERR)
                {
                    printf("\n Crashed! at position X= %d , Y= %d\n",objpos.x,objpos.y);
                    //objpos.y = objpos.y - 1;
                    return ERR;
                }

                remaintime = remaintime - speed;

                printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
//                updatetrack();

            }
            break;
        case 'd':
            printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
            while(remaintime > 0)
            {
                sleep(speed);

                objpos.y = objpos.y - 1;
                if(isbadpos(objpos.x,objpos.y) == ERR)
                {
                    //objpos.y = objpos.y + 1;
                    printf("\n Crashed! at position X= %d , Y= %d\n",objpos.x,objpos.y);
                    return ERR;
                }
//                updatetrack();
                remaintime = remaintime - speed;

                printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
            }
            break;
        case 'l':
            printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
            while(remaintime > 0)
            {
                sleep(speed);

                objpos.x = objpos.x - 1;
                if(isbadpos(objpos.x,objpos.y) == ERR)
                {
//                    objpos.x = objpos.x + 1;
                    printf("\n Crashed! at position X= %d , Y= %d\n",objpos.x,objpos.y);
                    return ERR;
                }
//                updatetrack();
                remaintime = remaintime - speed;
                printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
            }
            break;
        case 'r': // Move right
            printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
            while(remaintime > 0)
            {
                sleep(speed);

                objpos.x = objpos.x + 1;
                if(isbadpos(objpos.x,objpos.y) == ERR)
                {
//                    objpos.x = objpos.x - 1;
                    printf("\n Crashed! at position X= %d , Y= %d\n",objpos.x,objpos.y);

                    return ERR;
                }
                remaintime = remaintime - speed;
                printf("\n X = %d\t Y = %d \n",objpos.x,objpos.y);
//                updatetrack();
            }
            break;
    }
    return OK;
}

int rotate(char dir)
{
    if(dir == 'l')
        objpos.angle =objpos.angle + 90;
    else if(dir == 'r')
        objpos.angle =objpos.angle - 90;

    if(objpos.angle == 360)
        objpos.angle =0;
    if(objpos.angle == -90)
        objpos.angle = 270;

    return  0;
}