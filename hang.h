#define MAX 20
char str1[MAX];
char str2[MAX];
int tries=5;
int array[26];
void initialize()
{
    int i;
    for(i=0;i<26;i++)
        array[i]=0;
}
void lower();
int isupper(char a)
{
   if((a>=65)&&(a<=90))
       return 1;
   else return 0;
}
void input()
{
    printf("\nUSER 1: Enter the string: ");
    scanf("%s",str1);
    printf("\nInput Successful");
    printf("\033[H\033[J");
    lower();
}
void change()
{
    strcpy(str2,str1);
    int flag=0;
    while(str2[flag]!='\0')
    {
        char symbol;
        symbol=str2[flag];
        switch(symbol)
        {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
            case 'U': break;
            default: str2[flag]='_';
        }
        flag++;
    }
}
void lower()
{
    int i=0;
    while(str1[i]!='\0')
    {
        if(isupper(str1[i]))
        {
            str1[i]=str1[i]+32;
        }
        i++;
    }
}
void lower2()
{
    int i=0;
    while(str2[i]!='\0')
    {
        if(isupper(str2[i]))
        {
            str2[i]=str2[i]+32;
        }
        i++;
    }
}
void display()
{
    printf("\n%s\n",str2);
}
void ch(char a)
{
    {
        char s,t;
        s=65;
        t=92;
        while(s!=90)
        {
            if(a==s)
            {
                array[a-65]=1;
                break;
            }
            else if(a==t)
            {
                array[a-97]=1;
                break;
            }
            s++;
            t++;
        }
    }

}
void try()
{
    char a;
    int flag=0;
ent:printf("\nEnter a character: ");
    scanf(" %c",&a);
    if(isupper(a))
    {
        if((array[a-65])==1)
        { printf("\nCharacter already tried...Enter Another character...\n");
            goto ent;
        }
    }
    else
    {
        if((array[a-97])==1)
        { printf("\nCharacter already tried...Enter Another character...\n");
            goto ent;
        }
    }
    ch(a);
    int i=0;
    while(str2[i]!='\0')
    {
        if(str2[i]=='_')
        {
            if(a==str1[i]||(a+32)==str1[i]||(a-32)==str1[i])
            {
                str2[i]=a;
                flag=1;
            }
            
        }
        i++;
    }
    if(flag==0)
    {
        printf("\nSorry Wrong try");
        tries--;
        printf("\n%d tries left..",tries);
    }
    else if(flag==1) printf("\nSuccessful attempt");
        display();
}
