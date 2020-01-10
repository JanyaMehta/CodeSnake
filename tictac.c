#include<stdio.h>
#include<conio.h>
char a[9]={'1', '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };// globally declare as it is 2 be used in many functions
void gamename()
{
    printf("\n\t\t\tTIC TAE TOE GAME\n");
}
void show()
{
    printf("\n\n\t\t\t---|---|---\n");//making layout
    printf("\t\t\t%c  |%c  |%c  \n",a[0],a[1],a[2]);//printing characters
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t%c  |%c  |%c  \n",a[3],a[4],a[5]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t%c  |%c  |%c  \n",a[6],a[7],a[8]);
    printf("\t\t\t---|---|---\n");
}
void symbol()
{
    printf("\nplayer 1 symbol:x:\n");
    printf("\nplayer 2 symbol:0:\n");
}
void start()
{
    char m;
    printf("\nenter player staring game\n");
    scanf("%c",&m);
}
int count=0;    //to count no. of inputs as in 9th input match will be draw
void play()
{
    char p,s;
    printf("\nenter position and symbol for player\n");
    fflush(stdin);
        scanf("%c",&p);
    fflush(stdin);
        scanf("%c",&s);
count++;
    check(p,s);
}
void check(char P,char S)
{
    int i;
    for(i=0;i<=8;i++)
    {
        if(a[i]==P)
        {
            a[i]=S;      //now array stores symbol in that place not number
        }
    }

}
int end()
{
    if((a[0]=='x'&&a[1]=='x'&&a[2]=='x')||(a[0]=='x'&&a[3]=='x'&&a[6]=='x')||(a[0]=='x'&&a[4]=='x'&&a[8]=='x')    )//for ist position
       return(100) ;
      else  if((a[0]=='0'&&a[1]=='0'&&a[2]=='0')||(a[0]=='0'&&a[3]=='0'&&a[6]=='0')||(a[0]=='0'&&a[4]=='0'&&a[8]=='0')    )
        return(200);
  else  if(a[1]=='x'&&a[4]=='x'&&a[7]=='x')
        return(100);
    else  if(a[1]=='0'&&a[4]=='0'&&a[7]=='0')
        return(200);
      else  if(a[2]=='x'&&a[5]=='x'&&a[8]=='x')
        return(100);
          else  if(a[2]=='0'&&a[5]=='0'&&a[8]=='0')
        return(200);
    else  if(a[3]=='x'&&a[4]=='x'&&a[5]=='x')
        return(100);
    else  if(a[3]=='0'&&a[4]=='0'&&a[5]=='0')
        return(200);
          else  if(a[2]=='x'&&a[4]=='x'&&a[6]=='x')
        return(100);
    else  if(a[2]=='0'&&a[4]=='0'&&a[6]=='0')
        return(200);
          else  if(a[6]=='x'&&a[7]=='x'&&a[8]=='x')
        return(100);
    else  if(a[6]=='0'&&a[7]=='0'&&a[8]=='0')
        return(200);
        return(300);// if none of above  condition play

}
void main()
        {
            int k;
            char ch;

            label1:
            gamename();
            show();
        symbol();
        start();
        play();



        label:
        system("cls");
        show();
        play();
       k= end();



       system("cls");
       show();// to view new layout as if not call we will see previous layout
       if(count<9)
       {
       if(k==100)
       {

        printf("\nplayer 1 WON");
        count=0;// if any one won that count must have some value but 4 again starting me must give its value zero
       }
       else if(k==200)
       {


printf("\nplayer 2 WON");
count=0;
       }
else    // none of player won then we have 2 repeat above steps till any one won
goto label;
       }
       else
       {
           printf("game DRAW");
           count=0;
       }
printf("\n do u want to continue");
fflush(stdin);     // bcoz we r taking input
scanf("%c",&ch);
if(ch=='y'||ch=='Y')//repeat the main fuction
{
a[0]='1';
a[1]='2';
a[2]='3';     //bcoz we made changes in array so 4 again starting we need 2 again initialize a array
a[3]='4';
a[4]='5';
a[5]='6';
a[6]='7';
a[7]='8';
a[8]='9';
goto label1;
}


         getch();
         }
