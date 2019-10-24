/* 
    COMP10050: Assignment 1
    Written by: Evan Spendlove (18492656)

    Program Specifications:
        Input: Allow user to input up to 6 facebook users, with up to 4 friends each.
               Next, allow user to select one of the facebook users, for whom the program should suggest friends.
               If the user is finished entering users, or friends for a user, they should press enter to move on.

        Friend Suggestion: The program should suggest up to 2 friends for the selected user, based on the below criteria:
                            --> Friend suggestion is not already friends with the user selected
                            --> A friend suggestion may only be suggested once
                            --> Friend suggestions should be ordered by friend_count, and cases of equal friend_count are resolved by sorting alphabetically.
                            The program should output the 2 friends for the user.

        Sorting: The program should utilise (somewhat) efficient sorting algorithms, which discounts algorithms such as bubblesort.

    Code Design Specifications:
        - Comment where necessary
        - Use functions where possible
        - Separate your code into independent modules
    
    Notes on this program:
        - I provided two sorting libraries for this program, one which utilises quicksort, another which uses sorting networks
            - Both libraries work for the project specification
            - However for user counts above 6, you need to use sorting.h/c, which uses quicksort(), as it works for larger numbers of users

        - This project was created and written in Netbeans, and as such, I believe it is best suited to being compiled and run in Netbeans
        - If you wish to use alternative IDEs (such as Visual Studio, etc.), I think you need to #include .c files as well 
*/

#include <stdio.h>
#include <string.h>
#include "userStructure.h"
#include "userIO.h"
#include "sorting.h"

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

    printf("There were %d friend suggestions found for %.*s:\n", friendsFound,(int)(strlen(userSelect)-1),userSelect); /* Prints the number of friend suggestions found for the user selected (extra code to not include the last character in the username (\n)) */

    for(i=0;i<friendsFound;i++) /* Loops through the friendsFound array */
    {
        printf("\t %d: %s", i+1, friendSuggest[i]); /* Prints the friend found and their location (+1) in the array */
    }

    return 0;
}