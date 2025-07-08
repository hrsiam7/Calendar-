#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"   //because its for windows
#else
    #define CLEAR_COMMAND "clear"  //its for ios and linux
#endif

int firstdayoftheyear(int year){
     int day = (year * 365 + (year - 1)/4 - (year - 1)/100 + (year - 1)/400) % 7;
     return day;

}

int main()
{
    char *month[]={"January","February","March","April","May","June","July","August","september","October","November","December"};
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int weekday=0,spacecounter,year;

    printf("Enter the year To get the calender:");
    scanf("%d",&year);

     system(CLEAR_COMMAND);

        printf("       -------Welcome to %d-----    \n",year);
        weekday=firstdayoftheyear(year);

        if(year%4==0 && year%100 !=0 || year%400==0){
            days[1]=29;
        }

    for(int i=0 ; i<12 ;i++){
        printf("\n\n--------------  %s  -------------- \n\n",month[i]);
        printf("  sun  mon  tue  wed  thu  fri  sat \n");

        for(spacecounter=0;spacecounter<weekday ; spacecounter++){
            printf("     ");
        }
        for(int j=1;j<days[i]+1 ;j++ ){
            printf("%5d",j);

            weekday++;
            if(weekday>6){
                weekday=0;
                printf("\n");
            }
        }
        printf("\n\n");

    }
    return 0;
}
