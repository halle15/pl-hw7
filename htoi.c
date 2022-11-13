#include <stdio.h>
#include <math.h>
#include "htoi.h"

/*  TODO:
    1. Fix bug after O------, stackdumps.
    2. Document literally everything.
    3. Test edge cases.


*/



 int equiv(char c){
    switch(c){
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
        default :
            return -1;
    }

 }

/*
    Author: Evann Hall
    Description:

    The purpose of this function is to quickly and easily retrieve an integer value for the length of a character array, without using external headers.

*/
const int len(char *st){
    int x = 0;
    while(st[x] != '\0')x+=1; //count up, return x as length.
    return x;
}

const char *convString(char *st){

    char first = st[0];
    char second = st[1];

    char total[3] = {first, second};

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
        if(first == 'O') return '\0';
        return st;
        
        
    }

}

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
    int length = len(testStr);
    printf("RESULT: %i", htoi(testStr));

    return 0;
}

