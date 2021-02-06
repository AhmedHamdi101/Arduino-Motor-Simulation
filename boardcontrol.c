#include "project.h"
int intializeboard()
{
    int i ;
    currpin = 0;

    for (i = 0; i < PNUMBER; i++) {
        mainboard.pin[i] = LOW;
        mainboard.pinmode[i] = OUTPUT;
    }
    for (i = 0; i < SEQNUM ; i++) {
        pinsequence[i] = -1;
    }
    time = 0;
    return OK;
}
int digitalWrite(int pin, int value)
{
    if(mainboard.pinmode[pin] == INPUT)
        return ERR;

    mainboard.pin[pin] = value;
    editmotortoseq(pin);
    return OK;
}
int digitalRead(int pin)
{
    if(mainboard.pinmode[pin] == OUTPUT)
        return ERR;
    int value = mainboard.pin[pin];
    pinsequence[currpin] = pin;
    currpin = currpin +1;
    return value;
}
int pinmode(int pin, int mode)
{
    mainboard.pinmode[pin] = mode;

    return OK;
}
void delay(int value)
{

    int ret = updatemotors(value);
    if(ret == ERR)
        exit(0);
    else if( ret != 101) {
        sleep(value);
    }
    restoremotorseq();

}
