/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
			decimal_roman.c, decimal_roman.h, roman_decimal.c, roman_decimal.h, error.c, error.h
Date		: 09/13/2016

 */

# include "calculator.h"
# include "errors.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>


// storing the pre_roman_digit_characters for example: 40 has to be stored as XL
char* pre_roman_digit_characters(char character1,char character2,char* buffer)
{
	/*this function stores the previous digits of the roman character in temproary memory buffer*/
	*buffer = character1;
	buffer++;
	*buffer = character2;
	buffer++;
	return buffer;
}

//storing the post digits
char* post_roman_digit_characters(char character,int count,char* buffer)
{
	/*this function stores the post digits of the roman character in temproary memory buffer*/
	int character_count;
	for(character_count=0;character_count<count;character_count++){
		*buffer = character;
		buffer++;
	}
	return buffer;
}
/*function to return the roman string*/

char* decimal_number_to_roman_string(int decimal_number,char* buffer)
{
	char *final_roman_string = buffer;
	/*while loop to return the roman string of the passed decimal number. Inside the loop it calls either post_roman_digit_characters 
or pre_roman_digit_characters depending on the input */
	while(decimal_number !=0)
	{
		if(decimal_number >= 1000){ // converstion for 1000
			buffer = post_roman_digit_characters('M',decimal_number/1000,buffer);
			decimal_number = decimal_number - (decimal_number/1000) * 1000;
		}
		else if(decimal_number >=500){ // conversion for 500
			if(decimal_number <(500 + 4*100 )){
				buffer = post_roman_digit_characters('D',decimal_number/500,buffer);
				decimal_number = decimal_number - (decimal_number/500) * 500;
			}
			else{
				buffer = pre_roman_digit_characters('C','M',buffer);
				decimal_number = decimal_number - (1000-100);
			}
		} /*end of if(decimal_number >=500)*/
		else if(decimal_number >=100){ // conversion for 100
			if(decimal_number < (100 + 3 * 100)){
				buffer = post_roman_digit_characters('C',decimal_number/100,buffer);
				decimal_number = decimal_number - (decimal_number/100) * 100;
			}
			else{
				buffer = pre_roman_digit_characters('L','D',buffer);
				decimal_number = decimal_number - (500-100);
			}
		}/* end of if(decimal_number >=100) */
		else if(decimal_number >=50){ // conversion for 50
			if(decimal_number < (50 + 4 * 10)){
				buffer = post_roman_digit_characters('L',decimal_number/50,buffer);
				decimal_number = decimal_number - (decimal_number/50) * 50;
			}
			else{
				buffer = pre_roman_digit_characters('X','C',buffer);
				decimal_number = decimal_number - (100-10);
			}
		} /*end of if(decimal_number >=50) */
		else if(decimal_number >=10){ //conversion for 10
			if(decimal_number < (10 + 3 * 10)){
				buffer = post_roman_digit_characters('X',decimal_number/10,buffer);
				decimal_number = decimal_number - (decimal_number/10) * 10;
			}
			else{
				buffer = pre_roman_digit_characters('X','L',buffer);
				decimal_number = decimal_number - (50-10);
			}
		}/*end of if(decimal_number >=10) */
		else if(decimal_number >=5){ //conversion for 5
			if(decimal_number < (5 + 4 * 1)){
				buffer = post_roman_digit_characters('V',decimal_number/5,buffer);
				decimal_number = decimal_number - (decimal_number/5) * 5;
			}
			else{
				buffer = pre_roman_digit_characters('I','X',buffer);
				decimal_number = decimal_number - (10-1);
			}
		}/*end of if(decimal_number >=5) */
		else if(decimal_number >=1){ // conversion for 1
			if(decimal_number < 4)
			{
				buffer = post_roman_digit_characters('I',decimal_number/1,buffer);
				decimal_number = decimal_number - (decimal_number/1) * 1;
			}
			else{
				buffer = pre_roman_digit_characters('I','V',buffer);
				decimal_number = decimal_number - (5-1);
			}
		}/*end of if(decimal_number >=1) */

	}/*end of while loop*/
	*buffer = '\0';
	return final_roman_string;
}
