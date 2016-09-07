/*
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 09/07/2016
 */

# include "calculator.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

int romanValue(char r_Character)
{
	int value=0;
	switch(r_Character){
	case 'I': value = 1;
	break;
	case 'V': value = 5;
	break;
	case 'X': value = 10;
	break;
	case 'L': value = 50;
	break;
	case 'C': value = 100;
	break;
	case 'D': value = 500;
	break;
	case 'M': value = 1000;
	break;
	case '\0': value = 0;
	break;
	default: value = -1;
	}
	return value;
}

int roman_decimal(char number[])
{
	int index_value = 0;
	int decnum = 0; // value to store the dicimal value
	while(number[index_value] == 'I' || number[index_value] == 'V' || number[index_value] == 'X' || number[index_value] == 'L'|| number[index_value] == 'C' || number[index_value] == 'D' || number[index_value] == 'M')
	{
		if(romanValue(number[index_value]) < 0) // condition to check the invalid numbers
		{
			printf("%d",romanValue(number[index_value]));
			printf("Invalid roman digit : %c",number[index_value]);
			exit(0);
		}
		if((strlen(number) - index_value) > 2)
		{
			if(romanValue(number[index_value]) < romanValue(number[index_value+2])){
				printf("Invalid roman number");
			}
		}
		if(romanValue(number[index_value]) >= romanValue(number[index_value+1])) // reading each roman from the string
			decnum = decnum + romanValue(number[index_value]);
		else{
			decnum = decnum + (romanValue(number[index_value+1]) - romanValue(number[index_value]));
			index_value++;
			decnum = -1;
		}
		index_value++;
	}
	return decnum;
}
// storing the predigits for example: 40 has to be stored as XL
char* predigits(char character1,char character2,char* buffer)
{
	*buffer = character1;
	buffer++;
	*buffer = character2;
	buffer++;
	return buffer;
}

//storing the post digits
char* postdigits(char character,int count,char* buffer)
{
	int loop;
	for(loop=0;loop<count;loop++){
		*buffer = character;
		buffer++;
	}
	return buffer;
}

char* decimal_roman(int total,char* buffer)
{
	char *roman_num = buffer;
	while(total !=0)
	{
		if(total >= 1000){ // converstion for 1000
			buffer = postdigits('M',total/1000,buffer);
			total = total - (total/1000) * 1000;
		}
		else if(total >=500){ // conversion for 500
			if(total <(500 + 4*100 )){
				buffer = postdigits('D',total/500,buffer);
				total = total - (total/500) * 500;
			}
			else{
				buffer = predigits('C','M',buffer);
				total = total - (1000-100);
			}
		} /*end of if(total >=500)*/
		else if(total >=100){ // conversion for 100
			if(total < (100 + 3 * 100)){
				buffer = postdigits('C',total/100,buffer);
				total = total - (total/100) * 100;
			}
			else{
				buffer = predigits('L','D',buffer);
				total = total - (500-100);
			}
		}/* end of if(total >=100) */
		else if(total >=50){ // conversion for 50
			if(total < (50 + 4 * 10)){
				buffer = postdigits('L',total/50,buffer);
				total = total - (total/50) * 50;
			}
			else{
				buffer = predigits('X','C',buffer);
				total = total - (100-10);
			}
		} /*end of if(total >=50) */
		else if(total >=10){ //conversion for 10
			if(total < (10 + 3 * 10)){
				buffer = postdigits('X',total/10,buffer);
				total = total - (total/10) * 10;
			}
			else{
				buffer = predigits('X','L',buffer);
				total = total - (50-10);
			}
		}/*end of if(total >=10) */
		else if(total >=5){ //conversion for 5
			if(total < (5 + 4 * 1)){
				buffer = postdigits('V',total/5,buffer);
				total = total - (total/5) * 5;
			}
			else{
				buffer = predigits('I','X',buffer);
				total = total - (10-1);
			}
		}/*end of if(total >=5) */
		else if(total >=1){ // conversion for 1
			if(total < 4)
			{
				buffer = postdigits('I',total/1,buffer);
				total = total - (total/1) * 1;
			}
			else{
				buffer = predigits('I','V',buffer);
				total = total - (5-1);
			}
		}/*end of if(total >=1) */

	}/*end of while loop*/
	*buffer = '\0';
	return roman_num;
}

char* calculate(char roman_number1[50],char roman_number2[50], char option[10],char* buffer)
{
	int first_number, second_number; // to store roman values
	int sum = 0,sub = 0;
	first_number = roman_decimal(roman_number1); // calling roman_decimal function to convert first roman number to decimal
	second_number = roman_decimal(roman_number2); // calling roman_decimal function to convert second roman number to decimal
	char * answer; // to store the final result

	if(strcmp(option,"ADD") == 0) // check for the addition operation
	{
		sum =  first_number + second_number;
		if(sum > 3999)
		{
			printf("Number exceeds the maximum limit \n");
			answer = "-1";
		}
		else
			answer = decimal_roman(sum,buffer);
	} /* END of addition operation*/
	else if(strcmp(option,"SUBTRACT") == 0) // check for the subtraction operation
	{
		sub = first_number - second_number;
		if(sub > 3999)
		{
			printf("Number exceeds the maximum limit \n");
			answer = "-1";
		}
		else
			answer = decimal_roman(abs(sub),buffer);
		/*Note: As there are no negative numbers in roman
		  considering the absolute value of the negative number*/
	}
	else
	{
		printf("Invalid option \n");
		answer = "-1";
	}
	return answer;
}/* End of calculate function*/

