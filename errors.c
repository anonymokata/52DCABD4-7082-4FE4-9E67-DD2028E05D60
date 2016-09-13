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
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

/*function to print if the sum of the two numbers is greater than the limit*/
void addition_number_greater_than_limit(int exceeded_sum_number)
{
printf("sum of two values is greater than the maximum limit (3999) := %d \n",exceeded_sum_number);
exit(0);
}
/*function to print if the subtraction of the two numbers is greater than the limit*/
void subtraction_number_greater_than_limit(int exceeded_subtracted_number)
{
printf("subtraction of two values is greater than the maximum limit (3999) := %d \n",exceeded_subtracted_number);
exit(0);
}
/*function to print if the invalid operation is passed*/
void invalid_addition_subtraction_operation(char invalid_operation[])
{
printf("passed otherthan addition or subtraction operation := %s \n",invalid_operation);
exit(0);
}
/*function to print if the invalid roman string is passed*/
void invalid_format_roman_string(char roman_string[])
{
printf("format of the roman string is invalid := %s \n",roman_string);
exit(0);
}

