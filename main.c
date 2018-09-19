#include <stdio.h>

/*
Assignment:

Escreva um programa que recebe como entrada uma data, na forma de três inteiros d, m, a e
retorne o dia da semana.

Reference:

http://mathforum.org/dr.math/faq/faq.calendar.html
https://support.microsoft.com/en-us/help/214019/method-to-determine-whether-a-year-is-a-leap-year
*/


//Declaration
int weekday(int day, int month, int year, int century); 
int leap_year(int year, int century);


//Main function
int main() {

    int d, m, y, c, wd, lp;

    char *days[7];
    days[0] = "Sunday";
    days[1] = "Monday";
    days[2] = "Tuesday";
    days[3] = "Wednesday";
    days[4] = "Thursday";
    days[5] = "Friday";
    days[6] = "Saturday";

    printf("\nDay of the week finder. Enter a date.\n\n");
    
    printf("Day (1 to 31): \n");
    scanf("%d", &d);

    printf("\nMonth (1 to 12): \n");
    scanf("%d", &m);

    printf("\nYear (1 to 99): \n");
    scanf("%d", &y);

    printf("\nCentury (1 to 99): \n");
    scanf("%d", &c);

    printf(" \n");
    printf(" \n");

    lp = leap_year(y, c);

    //Checking whether the year is a leap year and if the date is valid
    if (lp == 1) {

        printf("This year is a leap year.\n");

        wd = weekday(d, m, y, c);

        //Date standard used in Brazil (d/m/y)
        printf("%d/%d/%d%d is %s.\n", d, m, c, y, days[wd]);
    }

    else {

        if (d == 31 && m == 2) {

            printf("The date is invalid because this isn't a leap year.\n");
        }

        else {

            printf("This year isn't a leap year.\n");

            wd = weekday(d, m, y, c);

            printf("%d/%d/%d%d is %s.\n", d, m, c, y, days[wd]);
        }
    }

    return 0;
}


//Definition
int weekday(int day, int month, int year, int century) {
//Returns a number between 1 and 7 where 1 stands for Sunday, 2 for Monday, 7 for Saturday and so on
//Format (1-31,1-12,1-99,1-99)
    
    int aux1;
    int aux2;
    int wd;

    //Normalizing the input to be suitable for the formula
    if (month == 1) {

        month = 11;
        if (year == 00) {

            year = 99;
            century --;
        }

        else {

            year --;
        }
    }

    else if (month == 2) {

        month = 12;
        if (year == 00) {

            year = 99;
            century --;
        }

        else {

            year --;
        }
    }

    else {

        month = month - 2;
    }

    //Aplying the formula
    aux1 = day + ((13*month - 1)/5) + year + (year/4) + (century/4) - 2*century;

    if (aux1 < 0) {

        aux2 = aux1;

        while (aux2%7 != 0) {

            aux2 --;
        }

        wd = aux2%aux1;
    }

    else {

        wd = aux1%7;
    }

    return wd;
}


int leap_year(int year, int century) {
//Returns 1 if a year is a leap year and 0 if it isn't
//Format (1-99,1-99)
    
    if (year%4 == 0) {

        if (year == 0) {

            if (century%4 == 0) {

                return 1;
            }

            else {

                return 0;
            }
        }

        else {

            return 1;
        }
    }

    else {

        return 0;
    }
}
