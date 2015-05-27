/******************************************
 * Unit Test 1: Compare *******************
 ******************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
void compareCheck(int num);

int main (int argc, char** argv) {

    printf ("******************************************\n");
    printf ("* Unit Test 1: Compare START *************\n");
    printf ("******************************************\n\n");
    
    int a_val = 10;
    int b_val = 5;
    printf ("a = %d, b = %d \n", a_val, b_val);
    int* a = &a_val;
    int* b = &b_val;
    compareCheck(compare(a,b));

    a_val = 10;
    b_val = 20;
    printf ("a = %d, b = %d \n", a_val, b_val);
    compareCheck(compare(a,b));

    a_val = 20;
    b_val = 20;
    printf ("a = %d, b = %d \n", a_val, b_val);
    compareCheck(compare(a,b));

    char a_string[15] = "I am Khue";
    char b_string[15] = "This is wack!";
    printf ("a = %s, b = %s \n", a_string, b_string);
    compareCheck(compare(a_string,b_string));

    strcpy(a_string,"This is wack!");
    strcpy(b_string,"I am Khue");
    printf ("a = %s, b = %s \n", a_string, b_string);
    compareCheck(compare(a_string,b_string));

    strcpy(a_string,"I am Khue");
    strcpy(b_string,"I am Khue");
    printf ("a = %s, b = %s \n", a_string, b_string);
    compareCheck(compare(a_string,b_string));

    printf ("******************************************\n");
    printf ("* Unit Test 1: Compare PASSED ************\n");
    printf ("******************************************\n\n");

    return 0;
}

void compareCheck(int num){
    if(num == 1){
        printf ("a > b\n");
        printf ("compare = %d\n\n", num);
    }
    else if(num == -1){
        printf ("a < b\n");
        printf ("compare = %d\n\n", num);
    }
    else{
        printf ("a = b\n");
        printf ("compare = %d\n\n", num);
    }
}
