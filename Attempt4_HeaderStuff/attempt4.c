/* 24/1/19: Attempt 4 - Using C libraries */

#include <stdio.h>
#include <string.h>
#include "userIO.h"
#include "userStructure.h"
#include "userIO.c"
#include "sorting.h"
#include "sorting.c"

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
    fb_user userList[30]; /* Initialises an array of thirty (4*6 + 6) users in userList */
    int n = 6; /* Initialises n, the number of users in the array userList */
    int totalUsers; /* Used for storing count of totalUsers */
    int friendsFound; /* Used for keeping track of friend suggestions found */
    char userSelect[100]; /* Used for storing the username of the user selected for friend suggestion */
    char friendSuggest[2][100]; /* 2d Array used for storing friend suggestions by username */

    input(userList, &totalUsers, n);
    userSelection(userList, userSelect, totalUsers);

    printf("User Selected: %s\n", userSelect);

    friendsFound = friendSelection(userList, userSelect, friendSuggest, totalUsers);
    
    printf("Friend Founds: %d.\n", friendsFound);

    switch(friendsFound)
    {
        case 0 :
            printf("There were no friend suggestions found for the user you have selected.\n");
            break;
        case 1 :
            printf("There was one friend suggestion found for the user you have selected.\n");
            printf("\t %s", friendSuggest[0]);
            break;
        case 2 :
            printf("There were two friend suggestions found for the user you have selected.\n");
            printf("\t 1: %s", friendSuggest[0]);
            printf("\t 2: %s", friendSuggest[1]);
            break;
        default:
            printf("Error: friendSuggestion() reported an error message.\n");
            break;
    }


    return 0;
}