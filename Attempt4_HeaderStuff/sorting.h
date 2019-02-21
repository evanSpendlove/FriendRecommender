#include "userStructure.h"


/* 
    swap() Function:
    Goal: To swap two elements (structures) using a temp variable
*/
void swap(fb_user *a, fb_user *b);

/*
    partition() Function:
    Goal: to put the pivot at it's correct (sorted) location in the array
          and to sort every element greater than it to its right (higher index)
          and every element less than it to its left (lower index)
*/
int partition(fb_user user_List[], int min, int max);

/*
    friendSort() function:
    Goal: to sort an array using partition()
        --> Splits the array into two parts, those above the partition index and those below.
            Then, it sorts the pivot into it's correct location and splits the sub-array into two more parts.
            This process is repeated until all elements are sorted into their correct locations.

    Note: Utilises QuickSort algorithm to do so.
*/

void friendSort(fb_user user_List[], int min, int max);

/*
    alphabetise() Function:
    Goal: to alphabetise the user_List[] passed from friendSelection(), provided the users have the same friend count.
    - Capitalises the first letter of each word
    - Puts all other letters into lowercase
    - Checks if two users have the same friend count
    - If they do, sorts them alphabetically
*/

void alphabetise(fb_user *user_List, int total_users);

/*
    friendSelection() function:
    Goal: to return the number of friend suggestions and modify the friend_suggest[][] 2d array to contain appropriate suggestions.
    - Calls friendSort() and alphabetise() to modify the user_List[] array appropriately
    - Locates the index of the selected user and ensures they are not recommended as a friend
    - Checks if suggestion is already friends with the user, doesn't recommend it if it is
    - Also ensures the suggestion isn't already a suggestion
    - If the suggestion isn't friends with user selected, copies to friend_suggest and increments suggestion_count
*/

int friendSelection(fb_user user_List[], char user_select[], char friend_suggest[][100], int total_users);