# include "calculator.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

/*function to return decimal value of the roman digit*/
int roman_to_decimal_digit_value(char roman_character)
{
	int decimal_value=0;
/*switch case to return the decimal value based on the character passed to it*/
	switch(roman_character){
	case 'I': decimal_value = 1;
	break;
	case 'V': decimal_value = 5;
	break;
	case 'X': decimal_value = 10;
	break;
	case 'L': decimal_value = 50;
	break;
	case 'C': decimal_value = 100;
	break;
	case 'D': decimal_value = 500;
	break;
	case 'M': decimal_value = 1000;
	break;
	case '\0': decimal_value = 0;
	break;
	default: decimal_value = -1;
	}
	return decimal_value;
}

/*function to return the decimal value based on the input roman string*/
int roman_string_to_decimal_value(char roman_string[])
{
	int roman_string_index = 0;
	int decimal_number = 0; // value to store the decimal value
/*while loop to process the each roman character individually */
	while(roman_string[roman_string_index] == 'I' || roman_string[roman_string_index] == 'V' || roman_string[roman_string_index] == 'X' || roman_string[roman_string_index] == 'L'|| roman_string[roman_string_index] == 'C' || roman_string[roman_string_index] == 'D' || roman_string[roman_string_index] == 'M')
	{
		/*if condition check the order of the string. If first digit is greater than the second digit it add the value else 
			it subtracts the value  */
		if(roman_to_decimal_digit_value(roman_string[roman_string_index]) >= roman_to_decimal_digit_value(roman_string[roman_string_index+1])) 
			decimal_number = decimal_number + roman_to_decimal_digit_value(roman_string[roman_string_index]);
		else{
			decimal_number = decimal_number+ (roman_to_decimal_digit_value(roman_string[roman_string_index+1]) - roman_to_decimal_digit_value(roman_string[roman_string_index]));
			roman_string_index++;
			
		}
		roman_string_index++;
	}
	return decimal_number;
}

