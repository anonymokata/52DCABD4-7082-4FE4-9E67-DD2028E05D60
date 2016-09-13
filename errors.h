/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
			decimal_roman.c, decimal_roman.h, roman_decimal.c, roman_decimal.h, error.c, error.h
Date		: 09/13/2016

*/
#ifndef errors_H
#define errors_H
void addition_number_greater_than_limit(int exceeded_sum_number);
void subtraction_number_greater_than_limit(int exceeded_subtracted_number);
void invalid_addition_subtraction_operation(char invalid_operation[]);
void invalid_format_roman_string(char roman_string[]);

#endif
