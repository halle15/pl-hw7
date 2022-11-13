#include <stdio.h>
#include <math.h>
#include "htoi.h"

/*  equiv
    Description: takes in relevant hexadecimal character and converts it to integer without using external headers.
    @param c: The relevant hexadecimal character to be converted.
    @return int: The integer equivalent of param c.

*/
 int equiv(char c){
    switch(c){
        //Attempted this function with || operator, but it would not work unless i split them and repeated code unfortunately.
        case '0' :
            return 0;
        case '1' :
            return 1;
        case '2' :
            return 2;
        case '3' :
            return 3;
        case '4' :
            return 4;
        case '5' :
            return 5;
        case '6' :
            return 6;
        case '7' :
            return 7;
        case '8' :
            return 8;
        case '9' :
            return 9;
        case 'a' :
            return 10;
        case 'A' :
            return 10;
        case 'b' :
            return 11;
        case 'B' :
            return 11;
        case 'c' :
            return 12;
        case 'C' :
            return 12;
        case 'd' :
            return 13;
        case 'D' :
            return 13;
        case 'e' :
            return 14;
        case 'E' :
            return 14;
        case 'f' :
            return 15;
        case 'F':
            return 15;
        //if a non relevant character is entered, this is returned to ensure that a future check will see this as a bad char.
        default :
            return -1;
    }

 }

/*
    @param *st: the string array to calculate from
    @return int: the length of st.    
    Description:

    The purpose of this function is to quickly and easily retrieve an integer value for the length of a character array, without using external headers.

*/
const int len(char *st){
    int x = 0;
    while(st[x] != '\0')x+=1; //count up, return x as length.
    return x;
}

/*
    @param *st: the string array to calculate from
    @return char: the stripped string array.
    Description:

    The purpose of this function is to check if there is a OX, or Ox before the input string, and if there is it cuts it off and returns the rest of the hexadecimal
    using no external header files.
*/
const char *convString(char *st){

    char first = st[0];
    char second = st[1];

    char total[3] = {first, second}; // easy access to the first two characters to check if there is a OX or Ox. It takes up 3 because there needs to be space for the null char.

    if(first != 'O') goto el; //no reason for design choice, practiced for a new concept, I find this cleaner than repeating code.


    if(second == 'x' || second == 'X') {

    int x = 2;
    char nextChar = st[x];
    static char retStr[100]; //ensure enough space is available for string, should not occupy this much, but my compiler will not dynamically assign.
    
    while(nextChar != '\0'){

        retStr[x-2] = nextChar; // this must account for x being two characters ahead, otherwise the beginning of the string will have unexpected properties.
        x += 1; // increment
        nextChar = st[x]; // add this to the str array.
        
    }
    retStr[x-2] = '\0'; //ensure null terminator is added to the string or unexpected effects will occur.
    return retStr;
    

    }
    else{
        el: 
        if(first == 'O') return '\0'; //returns null string to be checked later to throw error.
        return st;
        
        
    }

}

/*
    @param *st: the formatted hex string to calculate the integer from.
    @return int: the calculated integer converted from hex.
    Description:

    This is the final function that takes the previously formatted input and finally turns it into an integer, using only the math external header file.
*/
int htoi(char *st){
    
    int length = len(st);
    int e, total;
    
    for(int x = length - 1; x > -1; x--){
        e = equiv(st[x]);
        if(e == -1){printf("bad char!"); break;}

        total += e * pow(16, x);
    }

    return total;
}


int main(){
    char userString[100];
    scanf("%s", userString);
    char* testStr = convString(userString);
    if(*testStr == '\0'){printf("bad char!"); return -1;}
    int length = len(testStr);
    printf("RESULT: %i", htoi(testStr));

    return 1;
}

