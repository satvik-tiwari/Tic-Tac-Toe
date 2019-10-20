#include<stdio.h>
#include<stdlib.h>

void search(char *,char,char);
void Print(char [][5]);
int check(char [][5],char);

int main()
{
    int i,j,W,flag=0;
    char p1,p2,temp,pos;
    char *p;
    char G[5][5]={{'1','|','2','|','3'},{'_',' ','_',' ','_'},{'4','|','5','|','6'},{'_',' ','_',' ','_'},{'7','|','8','|','9'}};

    for(i=0;i<5;i++)
    {
    for(j=0;j<5;j++)
    printf("%c",G[i][j]);
    printf("\n");
    }
    p=&G[0][0];

    printf("Player 1 Enter X or O:\n");
    scanf("%c",&p1);
    if(p1=='X')
    p2='O';
    else
    p2='X';

    for(i=1;i<=9;i++)
    {
     if(i%2!=0)
     {
        printf("Player 1 enter the pos:\n");
        scanf("%c",&temp);
        scanf("%c",&pos);
        search(&G[0][0],pos,p1);
        system("clear");
        Print(G);
        if(i>4)
        {
           W=check(G,p1);
           if(W==1)
           {
            flag=1;
            printf("Player 1 Wins\n");
            break;
           }
        }
     }

     else
     {
        printf("Player 2 enter the pos:\n");
        scanf("%c",&temp);
        scanf("%c",&pos);
        search(&G[0][0],pos,p2);
        system("clear");
        Print(G);
        if(i>4)
        {
           W=check(G,p2);
           if(W==1)
           {
              flag=1;
              printf("Player 2 Wins\n");
              break;
           }
        }
     }
    }

    if(flag==0)
    printf("TIE\n");
    return(0);
}

void search(char *g,char P,char value)
{
  int i,j;

  for(i=0;i<5;i+=2)
 
    for(j=0;j<5;j+=2)
    {
      if(*(g+5*i+j)==P)
      *(g+5*i+j)=value;
    }
  }
}

void Print(char GG[][5])
{
  int i,j;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    printf("%c",GG[i][j]);
    printf("\n");
  }
}

int check(char gg[][5],char C)
{
  int i,j,c1,c2;

  for(i=0;i<=5;i+=2)
  {
    c1=0;
    c2=0;
    for(j=0;j<5;j+=2)
    {
      if(gg[i][j]==C)
      c1++;
      if(gg[j][i]==C)
      c2++;
    }
    if(c1==3||c2==3)
    goto CHECK;
  }

  c1=0;
  c2=0;

  for(i=0;i<=5;i+=2)
  {
    if(gg[i][i]==C)
    c1++;
    if(gg[i][4-i]==C)
    c2++;
  }
  goto CHECK;

  CHECK:
  if(c1==3||c2==3)
  return(1);
  else
  return (0);
}
