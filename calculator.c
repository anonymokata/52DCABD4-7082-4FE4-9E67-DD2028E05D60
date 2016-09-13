/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
			decimal_roman.c, decimal_roman.h, roman_decimal.c, roman_decimal.h, error.c, error.h
Date		: 09/13/2016

 */

# include "calculator.h"
# include "roman_decimal.h"
# include "decimal_roman.h"
# include "errors.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
/*function to perform roman addition and subtraction*/

char* calculate_roman_numbers(char first_roman_number[50],char second_roman_number[50], char Add_Subtract[10],char* buffer)
{
	/*calculate function reveives the input from test file first_roman number,
 second roman_number, addition/subtraction operation and temproary memory */

	int first_number = roman_string_to_decimal_value(first_roman_number); // calling roman_decimal function to convert first roman number to decimal
	int second_number = roman_string_to_decimal_value(second_roman_number); // calling roman_decimal function to convert second roman number to decimal
	char * final_answer; // to store the final result

	if((strcmp(Add_Subtract,"ADD") == 0)|| (strcmp(Add_Subtract,"add") == 0)) // check for the addition operation
	{
		if((first_number + second_number) > 3999)
		{
			addition_number_greater_than_limit(first_number + second_number); //this function to print the maximum limit of the given number
		}
		else
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			final_answer = decimal_number_to_roman_string((first_number + second_number),buffer);
	} /* END of addition operation*/
	else if((strcmp(Add_Subtract,"SUBTRACT") == 0) || (strcmp(Add_Subtract,"subtract") == 0)) // check for the subtraction operation
	{
		if((first_number - second_number) > 3999 || (first_number - second_number) < -3999)
		{
			subtraction_number_greater_than_limit(abs(first_number - second_number)); //this function to print the maximum limit of the given number
		}
		else
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			final_answer = decimal_number_to_roman_string(abs(first_number - second_number),buffer);
		/*Note: As there are no negative numbers in roman
		  considering the absolute value of the negative number*/
	}
	else 
	{
		invalid_addition_subtraction_operation(Add_Subtract);
	}
	return final_answer;
}/* End of calculate function*/
