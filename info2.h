#ifndef _INFO2_H_
#define _INFO2_H_
#define Max_P 10
#define Max_M 80

typedef struct information
{
    char name[20];
    char id[20];
    char psw[20];
    char sch[20];
    char city[20];
    char age[4];
    char title[80][200];
    char memo[80][200];
    int stime[80][6];
}info;

info arr[10];

int pnum = 0;
int osnum = 0;
int tnum[10] = {0};
#endif
