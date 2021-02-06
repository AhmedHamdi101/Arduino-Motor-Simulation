#ifndef CPROJECT1_MOTOR_H
#define CPROJECT1_MOTOR_H

#include "project.h"

#define MOTONUMB 4

struct motor{
    int motornumber;
    int motorpin;
    char motortype;
};

struct motor motors[MOTONUMB];
int intializemotors();
int setpintomotor(int pin,int motornumber);
int setmotortype(int motornumber,char type);
int editmotortoseq(int pin);
int updatemotors(int sleepvalue);
int checkforcrash();
int restoremotorseq();

#endif //CPROJECT1_MOTOR_H
