#include <stdio.h>
#include <stdlib.h>
int inputyear(void);
int determinedaycode(int year);
void determineleapyear(int year,int *days);
void calendar(int year,int daycode,int *days);
int main()
{
    while(1){
        printf("enter the year:");
        int year=inputyear();
        int *daysinmonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
        determineleapyear(year,daysinmonth);
        determinedaycode(year);
        calendar(year,determinedaycode(year),daysinmonth);
        printf("\n");
    }


    return 0;
}
int inputyear(void){
    int x;
    scanf("%d",&x);
    return x;
}
int determinedaycode(int year){
    int a;
    a=(((year-1)*365)+((year-1)/4)-((year-1)/100)+(year/400))%7;
    return a;
}
void determineleapyear(int year,int *days){
    if(year%4==0) *(days+1)=29;
    else *(days+1)=28;
}
void calendar(int year,int daycode,int *days){
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int weekday=0;
    for(int i=0;i<12;i++){
       printf("\n\n-----------------%s-----------------\n",months[i]);
       printf("\n  Mon  Tue  Wed  Thur  Fri  Sat  Sun\n");
       for(weekday=0;weekday<daycode;weekday++) printf("     ");
       for(int j=1;j<=(*(days+i));j++){
           printf("%5d",j);
           if(++weekday>6)  {
                printf("\n");
                weekday=0;
           }
           daycode=weekday;
       }

    }
}
