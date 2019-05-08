
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

int choose_tune(int x);
int random(int ra, int rb);
int hour=0,minute=0,second=0,milli=0,flag3=0;

void delay(int ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock());
}
int counter()
{
    while(!kbhit() && flag3 ==0)
   {
                if(minute > 59)
        {
                  minute = 0;
                  ++hour;
        }
                if(second > 59)
        {
                     second = 0;
                    ++minute;
        }
        if (milli>100)
        {
            milli = 0;
            ++second;
        }
                     printtime();
                    delay(10);
                    milli += 5;
    }
        option();
}

int printtime()
{
system("cls");
printf("1.Start  2.Stop  3.Reset  4. End\n");
printf("***\n");
printf("            %2d:%2d:%2d:%2d\n",hour,minute,second,milli);
printf("***\n");
}

int option(void)
{
    switch(getch())
    {
    case 49: flag3 =0; break;
    case 50: flag3 =1; break;
    case 51:
        hour = minute = second = milli = 0;flag3 = 1;
        printtime();
        break;
    case 52: exit(0);;break;
    }
}


int main ()

 {
     printf("CLOCK\n");
     system("COLOR f9");
     printf("1. Alarm \t\t 2. Timer \t\t  3. Stopwatch");
     system("COLOR f8");
     system("COLOR f8");
     option1:

     printf("\n\nPlease choose from one of the above options");
     int option;
     scanf("%d",&option);

     if (option<1 || option>3)
     {
         printf("\nInvalid");
         system("COLOR 4f");
         goto option1;
     }

     else
     {
              system("COLOR f6");

switch(option)
{


case 1: ///////////////////////////////////////////////////////////////////////////////////////////// ALARM
{
    printf("Select one of tunes:\n");
    printf("1.TUNE 1\n2.SHAPE OF YOU\n3.PIRATES\n");
    int tunechoice;
    scanf("%d",&tunechoice);
    time_t currentTime;
    time(&currentTime);

struct tm * myTime = localtime(&currentTime);
printf("%i : %i : %i",myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
int h,m,s,hu,mu,dh,dm,i,j,k;

h=myTime->tm_hour;
m=myTime->tm_min;
s=myTime->tm_sec;

wake:

printf("\n Enter time you wanna wake 24 hour format \t");

printf("\nEnter Hour\t");
scanf("%d",&hu);

if(hu>24||hu<0)
{
    printf("INVALID");
    goto wake;
}

printf("Enter Minutes\t");
scanf("%d",&mu);


if(mu>60 || mu<0)
{
    printf("INVALID");
    goto wake;

}

if (mu<m)
{
    dm = 60+mu-m;
}
else if (mu>m)
{
    dm=mu-m;
}

if (mu<m)
{
    dh = hu-h-1;
}
else if (mu>m)
{
    dh=hu-h;
}

if (dh <0)
{
    dh=dh+24;
}

else if (dh>0)
{
    dh=dh;
}

printf("\t \n TIme difference is\t  %d : %d",dh,dm);

printf("\t \n This is the remaining time\t  %d : %d",dh,dm);


i=dh;
j=dm-1;
k=59;

for (i=dh;i>=0; i--)
{
    for(j=dm-1; j>=0; j--)
    {

        for(k=59; k>=0; k--)
        {
            system("cls");
            printf("Remaining time is \t %d : %d : %d ",i,j,k);
            Sleep(1000);
        }
        k=59;
    }
    j=59;
}
i=i-1;

//TIMER WILL STOP AND ALARM WILL RING

choose_tune(tunechoice);

system("COLOR f9");
printf("Time is up");
system("COLOR 9f");
Sleep(1000);
system("COLOR 8f");
Sleep(1000);
system("COLOR 7f");
Sleep(1000);
system("COLOR f6");
Sleep(1000);
system("COLOR f5");
Sleep(1000);
system("COLOR 4f");

//MATHS GAME WILL STRAT HERE///////////////////////////////////////////////////////////////////////
int x,y,a1,s1,p1,q1,flag=0;
again :
        printf("\nEnter any two numbers (these would be for a surprise) \n");
        scanf("%d %d",&x,&y);/* x and y are numbers that would act as our array index to extract from the array of random numbers*/

    int response1 = random(x,y);

       if (response1==0)
       {
           choose_tune(tunechoice);
           goto again;

       }

       else
       {
           exit (0);
       }


//maths game ends

            }
//////////////////////////////////////////////////////////////////////////////////////TIMER
         case 2:
            {
    int i,j,k,hu,mu,su;
    printf("Select one of tunes:\n");
    printf("1.TUNE 1\n2.SHAPE OF YOU\n3.PIRATES\n");
    int tunechoice;
    scanf("%d",&tunechoice);

    printf("\nEnter the time");
    printf("\nEnter hours\t");
    scanf("%d",&hu);
    printf("\nEnter minutes\t");
    scanf("%d",&mu);
    printf("\nEnter seconds\t");
    scanf("%d",&su);

i=hu;
 j=mu;
 k=su;
int timer;
timer= hu*3600+mu*60+su;
while(timer>0)
{

for (i=hu;i>=0; i--)
{
    for(j=mu; j>=0; j--)
    {
        for(k=su; k>=0; k--,timer--)
        {
            system("cls");
            printf("Remaining time is \t %d : %d : %d ",i,j,k);
            Sleep(1000);
        }
        k=59;
    }
    j=59;
}
i=i-1;



}
//TIMER WILL END AND ALARM WILL RING

choose_tune(tunechoice);

printf("\nThe Timer Has Expired");
system("COLOR f9");
system("COLOR 9f");
Sleep(1000);
system("COLOR 8f");
Sleep(1000);
system("COLOR 7f");
Sleep(1000);
system("COLOR f6");
Sleep(1000);
system("COLOR f5");
Sleep(1000);
system("COLOR 4f");
int b[10000],a,p,q,x,y,flag=0;
//again2:


    /*    printf("\nEnter any two numbers (these would be for a surprise) \n");
        scanf("%d %d",&x,&y);/* x and y are numbers that would act as our array index to extract from the array of random numbers
       int response2 = random(x,y);
       if (response2==0)
       {
           choose_tune(tunechoice);
           goto again2;
       }
       else
       {
           exit (0);
       }
       */
exit (0);

            }
//////////////////////////////////////////////////////////////////////////STOP WATCH
         case 3:
            {
                  while(1)
    {
                counter();
    }

            }

         }
     }

 }


//THIS FUNCTION WILL PLAY THE SELECTED TUNE
int choose_tune(int x)
{
    int k=1000,i=300,j=400;
    float c2 = (k), c2s = (k*1.059), d2= (k*1.1224), d2s= (k*1.1892), e2=(k*1.2599), f2=(k*1.3348), f2s= (k*1.4142), g2= (k* 1.4983), g2s= (k*1.5874), a2= (k* 1.6817), a2s = (k*1.7817), b2=(k*1.8874);
    float c3= (2*k), c3s = (k*1.059*2), d3= (k*1.1224*2), d3s= (k*1.1892*2), e3=(k*1.2599*2), f3=(k*1.3348*2), f3s= (k*1.4142*2), g3= (k* 1.4983*2), g3s= (k*1.5874*2), a3= (k* 1.6817*2), a3s = (k*1.7817*2), b3=(k*1.8874*2);

     int r=800,s=1000;

    switch(x)
    {

    case 1:
while(!kbhit())
{


printf("1st");
    Beep(c3,i);
    Beep(c3,i);
    Beep(d3,j);
    Beep(e3,j);
    Beep(c3,j);
    Beep(e3,j);
    Beep(d3,j);
    Beep(g2,j);
system("cls");
printf("2nd");
    system("COLOR 9f");

    Beep(c3,i);
    Beep(c3,i);
    Beep(d3,j);
    Beep(e3,j);
    Beep(c3,j);
    Beep(b2,j);
    Beep(g2,j);

    system("cls");
printf("3rd");
        system("COLOR f9");


    Beep(c3,i);
    Beep(c3,i);
    Beep(d3,j);
    Beep(e3,j);
    Beep(f3,j);
    Beep(e3,j);
    Beep(d3,j);
    Beep(c3,j);
    system("cls");
printf("4th");

        system("COLOR 4f");


    Beep(b2,j);

    Beep(g2,j);
    Beep(a2,j);
    Beep(b2,j);
    Beep(c3,i);
    Beep(c3,i);

 system("cls");
printf("5th");
            system("COLOR 6f");
}
            break;


 //Song 2 Shape of you

 case 2:
while(!kbhit())
{


    Beep(c3s,i);
    Beep(e3,j);
    Beep(c3s,i);

     system("cls");
printf("6th");

    Beep(c3s,i);
    Beep(e3,j);
    Beep(c3s,i);

     system("cls");
printf("7th");

    Beep(c3s,i);
    Beep(e3,j);
    Beep(c3s,i);

     system("cls");
printf("8th");

    Beep(d3s,j);
    Beep(c3s,i);
    Beep(b2,i);
}
    break;

/* Song 3*/

 case 3:

while(!kbhit())

{


 Beep(a2,r);
 Beep(c3,r);
 Beep(d3,r);
 Beep(d3,r);
 Beep(d3,r);
 Beep(e3,r);
 Beep(f3,r);
 Beep(f3,r);
 Beep(f3,r);
 Beep(g3,r);
 Beep(e3,r);
 Beep(e3,r);
 Beep(d3,r);
 Beep(c3,r);
 Beep(d3,r);

 Beep(a2,r);
 Beep(c3,r);
 Beep(d3,r);
 Beep(d3,r);
 Beep(d3,r);
 Beep(e3,r);
 Beep(f3,r);
 Beep(f3,r);
 Beep(f3,r);
 Beep(g3,r);
 Beep(e3,r);
 Beep(e3,r);
 Beep(d3,r);
 Beep(c3,r);
 Beep(d3,r);
}
break;
    }






    return 0;
}

//THIS FUNCTION WILL GENERATE RANDOM NUMBERS FOR MATHS GAME

int random(int ra, int rb)
{


int b[10000],a,p,q,x,y,a1,s1,p1,q1,flag,i,s;


        for (i=0; i<10000; i++)
        {
            b[i]= rand()%10000;
        }

printf("%d and %d are your random numbers \t",b[ra],b[rb]);

printf("Enter the Answer after performing operations in order \n 1. Add\n 2. Sub\n 3. Multiply\n 4. Quotient\n");
scanf("%d%d%d%d",&a,&s,&p,&q);

a1=(b[ra]+b[rb]);
s1=(b[ra]-b[rb]);
p1=(b[ra]*b[rb]);
q1=(b[ra]/b[rb]);

if (a==a1&&s==s1&&p==p1&&q==q1)
{
    printf("\n \t \n\tPERFECT");
    exit(0);
 /* Alarm will stop*/


}
else
{
    printf("SORRY");
    flag=0;
}

return flag;
}
