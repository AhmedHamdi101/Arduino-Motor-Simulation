#include "project.h"
int main()
{
    /* THESE 3 FUNCTIONS TO INITIALIZE THE ENVIRONMENT */
    intializemap();
    intializeboard();
    intializemotors();
    initializequeue();


    pinmode(0,OUTPUT);
    pinmode(1,OUTPUT);

    digitalWrite(0,HIGH);
    delay(2);
    digitalWrite(0,HIGH);
    digitalWrite(0,HIGH);
    delay(3);

    return 0;
}