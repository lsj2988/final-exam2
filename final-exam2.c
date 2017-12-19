#include <stdio.h>
#include <stdlib.h>

#include "info2.h"
#include "Func2.h"
#include "ArrFunc2.h"

int main(void)
{
    Load();
    char menu1,menu2;

    while(menu1 != 'Q')
    {
        menu2 = 'a';
        printf("1.Sing up\n2.Sign in\n3.List of User\n4.Exit\n");
        
        menu1 = getch();
        switch(menu1)
        {
            case '1':
            Signup();
            break;
        
            case '2':
            Signin();
            while(menu2 != 'Q')
            {
                printf("1.To write note\n2.To view note\n3.Back to menu\n");
            
                menu2 = getch();
                
                switch(menu2)
                {
                    case 'a':
                    break;

                    case '1':
                    Towritenote();
                    break;

                    case '2':
                    Toviewnote();
                    break;

                    case '3':
                    menu2 = 'Q';
                    break;

                    default:
                    printf("Wrong Press\n");
                    break;
                }
            }
            break;
        
            case '3':
            Listofuser();
            break;
        
            case '4':
            Save();
            menu1 = 'Q';
            break;
        
            default:
            printf("Wrong Press\n");
            break;
        }
    }

    return 0;
}
