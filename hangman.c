#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hang.h"
int main()
{
    input();
    change();
    display();
    initialize();
    while(tries!=0)
    {
        
        lower2();
        if(strcmp(str2,str1)==0)
        {
            printf("\nSUCCESS..YOU HAVE WON\n");
            exit(0);
        }
        try();
    }
    if(tries==0)
        printf("\nSORRY...YOU HAVE LOST THE GAME\n");
    return 0;
}
