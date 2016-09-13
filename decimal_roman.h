#ifndef decimal_roman_H
#define decimal_roman_H

char* decimal_number_to_roman_string(int decimal_number,char* buffer);
char* pre_digit_characters(char character1,char character2,char* buffer);
char* post_digit_characters(char character,int count,char* buffer);


#endif
