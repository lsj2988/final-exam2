#ifndef _ARRFUNC2_H_
#define _ARRFUNC2_H_

#include <stdio.h>
#include <stdlib.h>

void Signup()
{
    system("clear");
    Sign_up(arr,&pnum);
}

void Signin()
{
    system("clear");
    Sign_in(arr,&pnum,&osnum);
}

void Listofuser()
{
    system("clear");
    List_ofuser(arr,&pnum);
}

void Towritenote()
{
    system("clear");
    savetime(arr,&osnum,tnum);
    To_writenote(arr,&osnum,tnum);
}

void Toviewnote()
{
    system("clear");
    To_viewnote(arr,&pnum,tnum);
}

void Load()
{
    system("clear");
    Load1(arr,&pnum);
    Load2(tnum);
    Load3(arr,&pnum,tnum);
}

void Save()
{
    system("clear");
    Save1(arr,&pnum);
    Save2(tnum);
    Save3(arr,&pnum,tnum);
}

#endif
