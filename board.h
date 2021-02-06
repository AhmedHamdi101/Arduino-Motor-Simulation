
#ifndef CPROJECT1_BOARD_H
#define CPROJECT1_BOARD_H
#include "project.h"

#ifndef PNUMBER
#define PNUMBER 6 /* Number of pins */
#endif

#define SEQNUM 50 /* Number of possible function without dealy*/

int currpin;

#define HIGH    1 /* High voltage   */
#define LOW     0 /* Low voltage    */

#define OUTPUT  1
#define INPUT   0

#define FREE    0
#define USED    1

struct board
{
   int pin[PNUMBER];    /*  array of pins values */
   int pinmode[PNUMBER];/*  array of pins modes  */
};

struct board mainboard;
int pinsequence[SEQNUM]; /* Array used to save the sequence of pins used */
int intializeboard();
int digitalWrite(int pin, int value); /* set pin Voltage*/
int digitalRead(int pin);             /* Read pin       */
int pinmode(int pin,int mode);        /* Set pin mode   */
void delay(int value);                /* SLEEP..        */

#endif //CPROJECT1_BOARD_H
