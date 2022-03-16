/*
Filename: intToEnglish.c
Filetype: C file
Author: Michael Salton
Course: CS2211
Created on: February 8. 2022
Description: this program takes a numerical input from the user and converts it into english characters
*/
#include <stdio.h>
#include <string.h>

int main(){

	char *single_digits[] //array of single digit characters
		= { "zero", "one", "two", "three", "four",
			"five", "six", "seven", "eight", "nine" };

	char *two_digits[] //array of double digit teen characters
		= { "",	"ten",	"eleven", "twelve",
			"thirteen", "fourteen", "fifteen", "sixteen",
			"seventeen", "eighteen", "nineteen" };

	char *tens_multiple[] = { "", "", "twenty", //array of double digit tens multiple characters
							"thirty", "forty", "fifty",
							"sixty", "seventy", "eighty",
							"ninety" };

	char *hundred[] = { "hundred"}; //hunred, created as an array to allow for expansion into thousands later

    //loops until the user enters 0
    for(;;){

        char num[20]; //initialize the input variable
        int index = 0;
	    
        printf("\nPlease enter a value (1-999, 0 to quit): "); //ask user for input
        scanf("%s", &num);

        int len = strlen(num); //get length of the inputted number

        //exits if user enters 0
        if (num[0] == 48){
            break;
        }

        //output for single digit numbers less then 10
        if (len == 1){
            index = num[0] - 48;
            printf("%s ",single_digits[index]);
        }

        //output for double digit numbers less then 20
        else if(len == 2 && num[0] == 49){
            index = (num[0] - 48) + (num[1]-48);
            printf("%s ",two_digits[index]);
        }

        //output for double digit tens multiple numbers
        else if(len == 2 && num[1] == 48){
            index = (num[0] - 48) + (num[1]-48);
            printf("%s ",tens_multiple[index]);
        }

        //output for double digit numbers above 19 ending with not 0
        else if(len == 2 && 48 < num[0] < 58 && 48 < num[1] < 58){
            index = (num[0] - 48);
            printf("%s-",tens_multiple[index]);
            index = num[1] - 48;
            printf("%s ",single_digits[index]);
        }

        //output for triple digit hunreds multiple numbers
        else if(len == 3 && num[1] == 48 && num[2] == 48){
            index = num[0] - 48;
            printf("%s ",single_digits[index]);
            printf("hunred");
        }

        //output for triple digit numbers ending in 0 not multiples of 100
        else if(len == 3 && num[1] == 49 && num[2] == 48){
            index = num[0] - 48;
            printf("%s ",single_digits[index]);
            printf("hunred and ");
            index = (num[1] - 48) + (num[2]-48);
            printf("%s ",two_digits[index]);
        }

        //ouput for triple digit numbers with a 0 in the middle and a not 0 at the end
        else if(len == 3 && num[1] == 48){ //304
            index = num[0] - 48;
            printf("%s ",single_digits[index]);
            printf("hunred and ");
            index = num[2] - 48;
            printf("%s ",single_digits[index]);
        }

        //output for triple digit numbers with no 0s
        else if(len == 3 && 48 < num[1] < 58 && 48 < num[2] < 58){ //699
            index = num[0] - 48;
            printf("%s ",single_digits[index]);
            printf("hunred and ");
            index = (num[1] - 48);
            printf("%s-",tens_multiple[index]);
            index = num[2] - 48;
            printf("%s ",single_digits[index]);
        }
    }
    return 0;
}