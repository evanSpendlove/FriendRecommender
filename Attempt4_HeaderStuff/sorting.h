#include "userStructure.h"


/* 
    swap Function:
    Goal: To swap two elements (structures) using a temp variable
*/
void swap(fb_user *a, fb_user *b);

/*
    partition Function:
    Goal: ???
    ???
    ???
*/
int partition(fb_user user_List[], int min, int max);

/*
    friendSort function:
    Goal: To sort the users in user_List[] by their friend count, so that the user with most friends is at the top.
    
    ???

    Note: Utilises QuickSort algorithm to do so.
*/

void friendSort(fb_user user_List[], int min, int max);

/*
    alphabetise Function:
    Goal: to alphabetise the user_List[] passed from friendSelection(), provided the users have the same friend count.
    - Capitalises the first letter of each word
    - Puts all other letters into lowercase
    - Checks if two users have the same friend count
    - If they do, sorts them alphabetically
*/

void alphabetise(fb_user *user_List, int total_users);

int friendSelection(fb_user user_List[], char user_select[], char friend_suggest[][100], int total_users);