/*
    C Library Header file
    --> Defines functions used for sorting, using sorting networks, in main.c
    Written by: Evan Spendlove (18492656)
*/

#include "userStructure.h"

/*
    SWAP() function:
    Goal: to swap two elements (structures) using a temp variable.
        --> Takes an extra argument (sort[]), which decides which conditional it will use for permitting swaps.
        --> This function works for both alphabetic sorting and ordered sorting, because of the multiple conditionals and extra argument.
*/
void SWAP(fb_user *a, fb_user *b, char sort[3]);

/*
    sortNetwork() function:
    Goal: To sort an array according to the condition (alphabetic/friend count) requested when called
        --> Uses the Bose-Nelson sorting network algorithm (http://pages.ripco.net/~jgamble/nw.html)
        --> This is an alternative to the quicksort() algorithm implemented in sorting.c
        --> It is a faster sorting algorithm, and it uses less memory, but in this case it only works for a max of 6 users
*/

void sortNetwork(fb_user *d, char sort[5], int total_users);

/*
    friendSelection2() function:
    Goal: To provide MAX_FRIEND_SUGGEST friend suggestinons for the user selected according to the following criteria:
        --> Friend suggestion is not already friends with the user selected
        --> A friend suggestion may only be suggested once
        --> Friend suggestions should be ordered by friend_count, and cases of equal friend_count are resolved by sorting alphabetically
*/
int friendSelection2(fb_user user_List[], char user_select[], char friend_suggest[][MAX_CHAR_COUNT], int total_users);