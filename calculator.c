/* 
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 09/06/2016
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
