#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int width=20,height=20,gameover;
int x,y,fruitx,fruity,score,flag;
int tailx[100],taily[100];
int counttail=0;
void setup()
{
    gameover=0;
  x=height/2;
  y=width/2;
  label1:
  fruitx=rand()%20;
  if(fruitx==0)
    goto label1;
    label2:
  fruity=rand()%20;
  if(fruity==0)
    goto label2;
  score=0;

}
void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<=height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(i==0||i==height||j==0||j==width)
            printf("#");
            else
            {
                if(i==x&&j==y)
                    printf(">");
                else if(i==fruitx&&j==fruity)
                    printf("0");
                else
                {
                    int ch=0;
                   for(k=0;k<counttail;k++)
                   {
                       if(i==tailx[k]&&j==taily[k])
                       {
                           printf("@");
                           ch=1;
                       }
                   }
                   if(ch==0)
              printf(" ");
              }

                        }
    }
    printf("\n");
    }
    printf("SCORE=%d",score);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
    case 'a':
        flag=1;
        break;
        case 's':
        flag=2;
        break;
        case 'w':
        flag=3;
        break;
        case 'z':
        flag=4;
        break;
        case 'x':
        gameover=1;
        break;
        }
    }
}
void logic()
{
    int i;
    int prevx=tailx[0],prevy=taily[0];
    int prev2x,prev2y;

    tailx[0]=x;
    taily[0]=y;
  for(i=1;i<counttail;i++)
  {
    prev2x=tailx[i];
    prev2y=taily[i];
    tailx[i]=prevx;
    taily[i]=prevy;
    prevx=prev2x;
    prevy=prev2y;
  }

switch(flag)
{
case 1:
    y--;
    break;
case 2:
    y++;
    break;
case 3:
    x--;
    break;
case 4:
    x++;
    break;
default:
    break;
}
if(x<=0||x>=width||y<=0||y>=height)
    gameover=1;
    for(i=0;i<counttail;i++)
    {
        if(x==tailx[i]&&y==taily[i])
            gameover=1;
    }
    if(x==fruitx&&y==fruity)
    {
        label3:
  fruitx=rand()%20;
  if(fruitx==0)
    goto label3;
    label4:
  fruity=rand()%20;
  if(fruity==0)
    goto label4;
    score+=10;
    counttail++;
    }

}
int main()
{

    int m,n;
    char c;
    label7:
    setup();
    while(1)
    {
    draw();
    input();
    logic();
if(gameover==1)
{break;}
    }
    printf("\nPRESS Y TO CONTINUE AGAIN:");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
        goto label7;
return 0;
}
