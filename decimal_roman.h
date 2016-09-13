/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
			decimal_roman.c, decimal_roman.h, roman_decimal.c, roman_decimal.h, error.c, error.h
Date		: 09/13/2016

*/

#ifndef decimal_roman_H
#define decimal_roman_H

char* decimal_number_to_roman_string(int decimal_number,char* buffer);
char* pre_roman_digit_characters(char character1,char character2,char* buffer);
char* post_roman_digit_characters(char character,int count,char* buffer);

#endif
