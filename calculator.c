/*
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 09/07/2016
 */

# include "calculator.h"
# include "roman_decimal.h"
# include "decimal_roman.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

char* calculate_roman_numbers(char first_roman_number[50],char second_roman_number[50], char Add_Subtract[10],char* buffer)
{
	int first_number = roman_string_to_decimal_value(first_roman_number); // calling roman_decimal function to convert first roman number to decimal
	int second_number = roman_string_to_decimal_value(second_roman_number); // calling roman_decimal function to convert second roman number to decimal
	char * final_answer; // to store the final result
	
	if(strcmp(Add_Subtract,"ADD") == 0) // check for the addition operation
	{
		if((first_number + second_number) > 3999)
		{
			final_answer = "0";
		}
		else
			final_answer = decimal_number_to_roman_string((first_number + second_number),buffer);
	} /* END of addition operation*/
	else if(strcmp(Add_Subtract,"SUBTRACT") == 0) // check for the subtraction operation
	{
		if((first_number - second_number) > 3999)
		{
			//printf("Number exceeds the maximum limit \n");
			final_answer = "0";
		}
		else
			final_answer = decimal_number_to_roman_string(abs(first_number - second_number),buffer);
		/*Note: As there are no negative numbers in roman
		  considering the absolute value of the negative number*/
	}
	//else if((strcmp(Add_Subtract,"ADD") != 0) && (strcmp(Add_Subtract,"SUBTRACT") != 0))
	else 
	{
		printf("Invalid option \n");
		final_answer = "0";
	}
	return final_answer;
}/* End of calculate function*/

