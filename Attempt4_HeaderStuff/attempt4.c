/* 
    COMP10050: Assignment 1
    Written by: Evan Spendlove (18492656)
*/

#include <stdio.h>
#include <string.h>
#include "userStructure.h"
#include "userIO.h"
#include "sorting.h"
#include "sorting.c"
#include "userIO.c"
#include "sortingNetwork.c"

#include "sortingNetwork.h"

/*
    Note on naming convention:
        I use camelCase for naming variables used in my 'main' function.
        I use an underscore (_) to separate words in variable names in my other functions.

        If a variable from main is being updated in a function using pointers, it will retain
        the name used in main when declared in a function.

        I hope this naming convention helps to clairfy which variables are being affected in each step.

        Exception: fb_user is used for defining my struct, because fb_user is clearer than fbUser in my opinion.
                    Similarly, friend_count is used in fb_user, as I think it is easier to read.
*/

int main(void)
{
    fb_user userList[MAX_USERS]; /* Initialises an array of MAX_USERS (set to 6) users in userList */
    int i; /* Counter for outputting friends found */
    int totalUsers = 0; /* Used for storing count of totalUsers */
    int friendsFound; /* Used for keeping track of friend suggestions found */
    char userSelect[MAX_CHAR_COUNT]; /* Used for storing the username of the user selected for friend suggestion */
    char friendSuggest[MAX_FRIEND_SUGGEST][MAX_CHAR_COUNT]; /* 2d Array used for storing friend suggestions by username */

    input(userList, &totalUsers); /* Calls the input() function to get input from user */
    userSelection(userList, userSelect, totalUsers); /* Calls the userSelection() function to allow user to pick a user */

    printf("User Selected: %s", userSelect); /* Prints the user selected */
    
    friendsFound = friendSelection(userList, userSelect, friendSuggest, totalUsers); /* Calls friendSelection() and assigns return value to friendsFound */
    
    printf("Friend Founds: %d.\n", friendsFound); /* Prints the number of friends found */

    printf("There were %d friend suggestions found:\n", friendsFound);
    for(i=0;i<friendsFound;i++)
    {
        printf("\t %d: %s", i+1, friendSuggest[i]);
    }

    return 0;
}