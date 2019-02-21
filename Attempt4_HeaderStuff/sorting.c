#include "sorting.h"

void swap(fb_user *a, fb_user *b)
{
    fb_user temp = *a; /* Stores *a in a temp variable */
    *a = *b; /* Stores b in a */
    *b = temp; /* Stores temp (i.e. what was in a) in b */
    /* Swap is now complete - what was in a is now in b, and vice versa. */
}

int partition(fb_user user_List[], int min, int max)
{
    int pivot = user_List[max].friend_count; /* Initialises the pivot and assigns it the final index in user_List[] array */
    int index = (min - 1); /* Initialises index and assigns it the value of (min -1) */
    int i; /* initialises i, a counter used for looping over the array */

    /* Moves every element greater than the pivot to the left of it, so all on right are less than it */

    for(i = min; i <= max - 1; i++)
    {
        if(user_List[i].friend_count >= pivot) /* Sorts so that user with most friends first */
        {
            index++; /* increment the index of the bigger element */
            swap(&user_List[index], &user_List[i]); /* Swaps user_List[i] and user_List[index] */
        }
    }
    swap(&user_List[index+1], &user_List[max]); /* Swaps the elements at indices [small + 1] and [max] */
    return (index + 1); /* Returns the element at the location that [max] previously was */
}

void friendSort(fb_user user_List[], int min, int max)
{
    if(min < max) /* Provided the min is less than the max, i.e. we loop from a lower index to a higher */
    {
        int partition_index; /* Initialises partition index */
        partition_index = partition(user_List, min, max); /* Calls the partition() function on user-List[] and assigns the result to partition_index */
        friendSort(user_List, min, partition_index - 1); /* Calls quickSort() to sort the part of the array less than partition_index */
        friendSort(user_List, partition_index + 1, max); /* Calls quickSort() to sort the part of the array greater than partition_index */
    }
}

void alphabetise(fb_user *user_List, int total_users)
{
    int i, j; /* Counters used for looping over the user_List[] array */

    for(i=0;i<total_users;i++) /* Loop for alphabetising names, now that the capitalisation is standardised */
    {
        for(j=0;j<total_users;j++) /* For each user's username... */
        {
            if(strcasecmp(user_List[i].username, user_List[j].username) < 0 && user_List[i].friend_count == user_List[j].friend_count) /* If they have the same number of friends, alphabetise them */
            {
                swap(&user_List[i], &user_List[j]); /* Swap to alphabetise */
            }
        }
    }
}

int friendSelection(fb_user user_List[], char user_select[], char friend_suggest[][MAX_CHAR_COUNT], int total_users)
{
    int i, j; /* Counters used for looping through arrays */
    int suggestion_count = 0; /* Used for storing the number of suggestions added to friend_suggest[] */
    int user_index = -1; /* Used for storing index of user selected in user_List array, default is -1 for clarity */
    int friendMatch = 0; /* Boolean (integer) used for checking if a match was found on the user selected's friend list, or the friend_suggest list */

    friendSort(user_List, 0, total_users - 1); /* Quick-sort based algorithm for sorting users based on number of friends */
    alphabetise(user_List, total_users - 1);
    
    for(i=0;i<total_users && user_index == -1;i++) /*Loops through sorted user_List[] to find the index of the user selected */
    {
        if(strcmp(user_List[i].username, user_select) == 0) /* Compares against user selected */
        {
            user_index = i; /* Stores index of the user selected in sorted array */
        }
    }

    for(i=0;i<total_users && suggestion_count != MAX_FRIEND_SUGGEST; i++) /* Loops through the users to find suggestions who meeet criteria below*/
    {
        if(i != user_index) /* If the user in user_List is not the user selected... */
        {
            for(j=0;j<user_List[user_index].friend_count;j++) /* Loops through the friends of the user_selected */
            {
                if(strcmp(user_List[i].username, user_List[user_index].friend[j]) == 0) /* Checks if the suggestion is already a friend of the user selected */
                {
                    friendMatch = 1; /* If they are already a friend of the user selected, update friendMatch */
                }
                if(strcmp(user_List[i].username, friend_suggest[j]) == 0) /* Checks if the suggestion is already a friend suggestion */
                {
                    friendMatch = 1; /* If they are already on the friend_suggest list, update friendMatch */
                }
            }

            if(friendMatch != 1) /* If the user we are looking at is not already a friend or on the friend_suggest[] list... */
            {
                strcpy(friend_suggest[suggestion_count], user_List[i].username); /* Copies the username of the selected user to the friend_suggest array */
                suggestion_count++; /* Increments count of suggestions found */
            }
        }
        friendMatch = 0; /* Resets friendMatch for the next iteration */
    }
    return suggestion_count; /* Returns the number of friend suggestions found */
}