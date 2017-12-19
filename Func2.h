#ifndef _FUNC2_H_
#define _FUNC2_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void Load1(info *arr, int *pnum)
{
    FILE *fp = fopen("sign.txt","rb");
    if(fp == NULL)
    {
        return;
    }
    
    while(1)
    {
        fread(arr[*pnum].name,sizeof(arr[*pnum].name),1,fp);
        fread(arr[*pnum].id,sizeof(arr[*pnum].id),1,fp);
        fread(arr[*pnum].psw,sizeof(arr[*pnum].psw),1,fp);
        fread(arr[*pnum].sch,sizeof(arr[*pnum].sch),1,fp);
        fread(arr[*pnum].city,sizeof(arr[*pnum].city),1,fp);
        fread(arr[*pnum].age,sizeof(arr[*pnum].age),1,fp);

        if(feof(fp) != 0)
            break;

        (*pnum)++;
    }
    
    fclose(fp);
}

void Load2(int *tnum)
{
    FILE *fp = fopen("tnum.txt","rb");
    if(fp == NULL)
    {
        return;
    }

    fread(tnum,sizeof(tnum),10,fp);
    
    fclose(fp);
}

void Load3(info *arr, int *pnum,int *tnum)
{
    int j;
    FILE *fp = fopen("memo.txt","rb");
    if(fp == NULL)
    {
        return;
    }
    
    for(j=0;j<(*pnum);j++)
    {
        fread(arr[j].title,sizeof(arr[j].title),tnum[j],fp);
        fread(arr[j].memo,sizeof(arr[j].memo),tnum[j],fp);
        fread(arr[j].stime,sizeof(arr[j].stime),tnum[j],fp);
    }
    
    fclose(fp);
}

void Save1(info *arr, int *pnum)
{
    int j;
    FILE *fp = fopen("sign.txt","wb");
    
    if(fp == NULL)
    {
        return;
    }
    
    for(j=0;j<(*pnum);j++)
    {
        fwrite(arr[j].name,sizeof(arr[j].name),1,fp);
        fwrite(arr[j].id,sizeof(arr[j].id),1,fp);
        fwrite(arr[j].psw,sizeof(arr[j].psw),1,fp);
        fwrite(arr[j].sch,sizeof(arr[j].sch),1,fp);
        fwrite(arr[j].city,sizeof(arr[j].city),1,fp);
        fwrite(arr[j].age,sizeof(arr[j].age),1,fp);
    }
    
    fclose(fp);
}

void Save2(int *tnum)
{
    FILE *fp = fopen("tnum.txt","wb");
    if(fp == NULL)
    {
        return;
    }

    fwrite(tnum,sizeof(tnum),10,fp);
    
    fclose(fp);
}

void Save3(info *arr, int *pnum,int *tnum)
{
    int j;
    FILE *fp = fopen("memo.txt","wb");
    if(fp == NULL)
    {
        return;
    }
    
    for(j=0;j<(*pnum);j++)
    {
        fwrite(arr[j].title,sizeof(arr[j].title),tnum[j],fp);
        fwrite(arr[j].memo,sizeof(arr[j].memo),tnum[j],fp);
        fwrite(arr[j].stime,sizeof(arr[j].stime),tnum[j],fp);\
    }

    fclose(fp);
}

char getch()
{
    char str[10];
    char ch;
    
    fgets(str,3,stdin);
    str[strlen(str)-1] = '\0';

    ch = str[0];

    return ch;
}

void Sign_up(info *arr, int *pnum)
{
    int j,t;
    char *psw;
    if((*pnum) < Max_P)
    {
        printf("-----------------------------\n");
        printf("Name : ");
        fgets(arr[*pnum].name,sizeof(arr[*pnum].name),stdin);
        arr[*pnum].name[strlen(arr[*pnum].name)-1] = '\0';
    
        if((*pnum) > 0)
        {
            while(1)
            {
                t = 0;
                printf("ID : ");
                fgets(arr[*pnum].id,sizeof(arr[*pnum].id),stdin);
                arr[*pnum].id[strlen(arr[*pnum].id)-1] = '\0';

                for(j=0;j<(*pnum);j++)
                {
                    if(strncmp(arr[j].id,arr[*pnum].id,strlen(arr[*pnum].id)) != 0)
                        t++;
                }

                if(t == (*pnum))
                    break;
                else
                    printf("User if already exits\n");
            }
        }
        
        else if((*pnum) == 0)
        {
            printf("ID : ");
            fgets(arr[*pnum].id,sizeof(arr[*pnum].id),stdin);
            arr[*pnum].id[strlen(arr[*pnum].id)-1] = '\0';
        }
        
        psw = getpass("Password : ");
        strncpy(arr[*pnum].psw,psw,strlen(psw));

        printf("age : ");
        fgets(arr[*pnum].age,sizeof(arr[*pnum].age),stdin);
        arr[*pnum].age[strlen(arr[*pnum].age)-1] = '\0';

        printf("City : ");
        fgets(arr[*pnum].city,sizeof(arr[*pnum].city),stdin);
        arr[*pnum].city[strlen(arr[*pnum].city)-1] = '\0';
    
        printf("School : ");
        fgets(arr[*pnum].sch,sizeof(arr[*pnum].sch),stdin);
        arr[*pnum].sch[strlen(arr[*pnum].sch)-1] = '\0'; 
        printf("-----------------------------\n");
        (*pnum)++;
    }

    else
        printf("User is Full\n");
}

void Sign_in(info *arr,int *pnum, int *osnum)
{
    int i,pn,flag;
    char id[20];
    char *psw;
    
    while(flag != 2)
    {
        flag = 0;
        printf("-----------------------------\n");
        printf("ID : ");
        fgets(id,sizeof(id),stdin);
        id[strlen(id)-1] = '\0';

        for(i=0;i<(*pnum);i++)
        {
            if(strncmp(arr[i].id,id,strlen(id)) == 0)
            {
                pn = i;
                flag++;
                break;
            }
        }

        psw = getpass("Password : ");
        if(strncmp(arr[pn].psw,psw,strlen(psw)) == 0)
        {
            flag++;
        }
        else
        {
            printf("Access Denied\n");
        }

    }
    printf("-----------------------------\n");
    (*osnum) = pn;
}

void List_ofuser(info *arr, int *pnum)
{
    int j;

    for(j=0;j<(*pnum);j++)
    {
        printf("-----------------------------\n");
        printf("Name : %s\n",arr[j].name);
        printf("ID : %s\n",arr[j].id);
        printf("Age : %s\n",arr[j].age);
        printf("School : %s\n",arr[j].sch);
        printf("City : %s\n",arr[j].city);
    }
    printf("-----------------------------\n");
}

void savetime(info *arr, int *osnum, int *tnum)
{
    time_t now;
    struct tm t;
    time(&now);
    t = *localtime(&now);

    arr[*osnum].stime[tnum[*osnum]][0] = t.tm_year+1900;
    arr[*osnum].stime[tnum[*osnum]][1] = t.tm_mon+1;
    arr[*osnum].stime[tnum[*osnum]][2] = t.tm_mday;
    arr[*osnum].stime[tnum[*osnum]][3] = t.tm_hour;
    arr[*osnum].stime[tnum[*osnum]][4] = t.tm_min;
    arr[*osnum].stime[tnum[*osnum]][5] = t.tm_sec;

    printf("Present Time : %4d.%d.%d %d:%d:%d\n",t.tm_year+1900,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);
}

void To_writenote(info *arr, int *osnum, int *tnum)
{
    char tmp[200];
    char ch;
    int i = 0;
    int flag = 0;
    
    printf("--------------------------\n");

    while(flag != 2)
    {
        ch = getchar();
        tmp[i] = ch;

        if(ch == '\n')
            flag++;
        else
            flag = 0;

        i++;
    }
    
    strncpy(arr[*osnum].memo[tnum[*osnum]],tmp,strlen(tmp));

    flag = 0;

    for(i=0;i<19;i++)
    {
        if(tmp[i] == ' ')
            flag++;
        else if(tmp[i] == '\n')
        {
            flag++;
            tmp[i] = ' ';
        }

        if(flag == 3)
        {
            strncpy(arr[*osnum].title[tnum[*osnum]],tmp,i);
            break;
        }
    }
    printf("-----------------------------\n");
    (tnum[*osnum])++;
}

void To_viewnote(info *arr,int *pnum,int *tnum)
{
    int i,j;
    for(i=0;i<(*pnum);i++)
    {
        if(tnum[i] > 0)
        {
            for(j=0;j<tnum[i];j++)
            {
                printf("-----------------------------\n");
                printf("Time : %4d.%d.%d %d:%d:%d\n",arr[i].stime[j][0],arr[i].stime[j][1],arr[i].stime[j][2],arr[i].stime[j][3],arr[i].stime[j][4],arr[i].stime[j][5]);
                printf("User : %s\n",arr[i].id);
                printf("Title : %s\n",arr[i].title[j]);
                printf("Memo : %s\n",arr[i].memo[j]);
            }
        }
    }
    printf("-----------------------------\n");
}

#endif
