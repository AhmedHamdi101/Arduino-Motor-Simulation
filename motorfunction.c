#include "project.h"
int intializemotors()
{
    int i;
    for ( i = 0; i <MOTONUMB ; i++) {
        motors[i].motornumber = i;
    }
    setpintomotor(0,0);
    setpintomotor(1,1);
    setpintomotor(2,2);
    setpintomotor(3,3);

    setmotortype(0,'f');
    setmotortype(1,'r');

    setmotortype(2,'b');
    setmotortype(3,'l');




}
int setmotortype(int motornumber,char type){
    // To turn left send    'l'
    // To turn right send   'r'
    // To turn down send    'b'
    // To turn up send      'f'
    motors[motornumber].motortype = type;
    return OK;
}
int setpintomotor(int pin,int motornumber)
{
    motors[motornumber].motorpin = pin;
    return OK;
}
int updatemotors(int sleepvalue)
{
    int i = 0;
    int  motorcount;
    int flag = 0;
    int pin;
    for(i = 0; i <SEQNUM;i++)
    {
        if(pinsequence[i] != -1)
        {
            pin = pinsequence[i];
//            printf("\npin #= %d-%d", i, pin);
            for (motorcount = 0; motorcount < MOTONUMB; motorcount++) {
                if (motors[motorcount].motorpin == pin) {
                    if (mainboard.pin[pin] == HIGH) {
//                        printf("\nmotor = %d , pin = %d----motor count = %d", motors[motorcount].motorpin, pin,
//                               motorcount);
                        if (motors[motorcount].motortype == 'f' || motors[motorcount].motortype == 'b') {
                            flag = 1;
                            if (move(1, sleepvalue, motors[motorcount].motortype) == ERR)
                                return ERR;
                        } else if (motors[motorcount].motortype == 'r' || motors[motorcount].motortype == 'l') {
                            rotate(motors[motorcount].motortype);
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < SEQNUM ; i++) {
        if(pinsequence[i] != -1)
        {
            insert(pinsequence[i]);
        }
        pinsequence[i] = -1;
    }
    currpin = 0;
    if(flag ==1)
        return 101;
    else
        return OK;
}
int editmotortoseq(int pin){
    if (mainboard.pin[pin] == HIGH) {
        int i;
        int flag    =   0;
        for(i = 0 ; i < SEQNUM ; i++)
        {
            if(pinsequence[i] == pin){
                //DO NOTHING ITS ALREADY ON
                flag = 1;
            }
        }
        if(flag == 0)
        {
            pinsequence[currpin] = pin;
            currpin = currpin + 1;
        }

    }
    else if(mainboard.pin[pin] == LOW)
    {
        int i;
        for ( i = 0; i < SEQNUM; i++) {
            if(pinsequence[i] == pin){
                pinsequence[i] = -1;
            }

        }
    }
    checkforcrash();
}
int checkforcrash(){
    int flag1   =   -1;
    int flag2   =   -1;
    int i;
    int j;
    int pin;
    for(i = 0; i < SEQNUM ; i++){
        if(pinsequence[i] != -1)
        {
            pin = pinsequence[i];
            for(j = 0; j < MOTONUMB ; j++)
            {
                if(motors[j].motorpin == pin)
                {
                    if(flag1 == -1)
                        flag1 = pin;
                    else if(flag2 == -1)
                    {
                        flag2 = pin;
                        if(flag2 != flag1)
                        {
                            printf("\nERROR:You have more than one motor running at the same time\n!");
                            exit(0);
                        }
                        else
                            flag2 = -1;
                    }
                }
            }
        }
    }


}
int restoremotorseq()
{
    while(!isEmpty())
    {
        pinsequence[currpin] = removeData();
        currpin++;
    }
    return  OK;
}

