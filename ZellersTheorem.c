//purpose: to conert the inputed day/month/year to zeller's theorem
#include <stdio.h>
#include <math.h>

void inputDate(int *day, int *month, int *year)
{
    printf("Please enter a date: ");
    scanf("%d/%d/%d", day, month, year);
    printf("The day %d/%d/%d is a ", *day, *month, *year);
    
}

//to convert the inputed date to zellers theorem and output the day of the week
//zellers theorem calculates the day of the week by convertin
void calculateDay(int day, int month, int year) 
{
    int const Century = 100;
    int A = 0, B = 0, C = 0, D = 0;

    if(month >=3 && month <= 12) { //if month > 0 when subtracting 2
        A = month - 2;
    } else { //if month <= 0 when subtracting 2
        A = month + 10;
        year -= 1; //year is changed by -1 for january and february 
    }
    
    B = day; //day of month is unchanged after months are changed
    
    D = year / Century; //defines the century
    
    C = year - (D * Century); //defines the year of the century
    //zellers theorem ends
    
    int W = 0, X = 0, Y = 0, Z  = 0, R = 0;
    
    W = ((13 * A) - 1) / 5;
    X = C / 4;
    Y = D / 4;
    Z = W + X + Y + B + C - (2 * D);
    R = Z % 7;
    
    if(R < 0) {
        R += 7;
    }
	
    if (R == 0) {
        printf("Sunday.\n");
    } else if(R == 1) {
        printf("Monday.\n");
    } else if(R == 2) {
        printf("Tuesday.\n");
    } else if(R == 3) {
        printf("Wednesday.\n");
    } else if(R == 4) {
        printf("Thursday.\n");
    } else if(R == 5) {
        printf("Friday.\n");
    } else {
        printf("Saturday.\n");
    }

}


