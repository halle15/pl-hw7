#include <stdio.h>
#include "htoi.h"

int htoi(char *st){
    printf("%s", st);
    char c = st[0];
    printf("\nCharacter at 0: %c\n", c);
    return 1;
}

/*
    The purpose of this function is to quickly and easily retrieve an integer value for the length of a character array, without using external headers.
*/
const int len(char *st){
    
    int x = 0;
    while(st[x] != '\0')x+=1; //count up, return x as length.
    return x;
}

const char *testString(char *st){

    char first = st[0];
    char second = st[1];

    char total[3] = {first, second};

    if(first != 'O') goto el; //no reason for design choice, practiced for a new concept, I find this cleaner than repeating code.


    if(second == 'x' || second == 'X') {

    int x = 2;
    int length;
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

int main(){


    char userString[100];
    scanf("%s", userString);


    char* testStr = testString(userString);
    int length = len(testStr);

    printf("Length: %i", length);
    
    
    


    return 0;
}

