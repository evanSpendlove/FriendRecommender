#include "userStructure.h"
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
    int pivot = user_List[max].friend_count;
    int small = (min - 1);
    int j;

    for(j = min; j <= max - 1; j++)
    {
        if(user_List[j].friend_count >= pivot) /* Sorts so that user with most friends first */
        {
            small++;
            swap(&user_List[small], &user_List[j]);
        }
    }
    swap(&user_List[small+1], &user_List[max]);
    return (small + 1);
}

void friendSort(fb_user user_List[], int min, int max)
{
    if(min < max)
    {
        int pi = partition(user_List, min, max);
        friendSort(user_List, min, pi - 1);
        friendSort(user_List, pi + 1, max);
    }
}

void alphabetise(fb_user *user_List, int total_users)
{
    int i, j; /* Counters used for looping over the user_List[] array */

    for(i=0;i<=total_users;i++) /* Looping through all users as we standardise their username capitalisation */
    {
        for(j=0;j<100 && user_List[i].username[j] != '\n';j++) /* Looping through all characters in each username */
        {
            if(j == 0) /* For the first character of each username...*/
            {
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z') /* If it is a lowercase letter */
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32; /* Make it uppercase */
                }
            }
            else if (user_List[i].username[j] == ' ') /* If the character is a space */
            {
                ++j; /* If this character is a space, capitalise the next letter */
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z')
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32;
                }
            }
            else
            {
                if(user_List[i].username[j] >= 'A' && user_List[i].username[j] <= 'Z') /* If it is a capital letter, make it lowercase */
                {
                    user_List[i].username[j] = user_List[i].username[j] + 32;
                }
            }
        }
    }

    for(i=0;i<total_users;i++) /* Loop for alphabetising names, now that the capitalisation is standardised */
    {
        for(j=0;j<total_users;j++) /* For each user's username... */
        {
            if(strcmp(user_List[i].username, user_List[j].username) < 0 && user_List[i].friend_count == user_List[j].friend_count) /* If they have the same number of friends, alphabetise them */
            {
                swap(&user_List[i], &user_List[j]); /* Swap to alphabetise */
            }
        }
    }
}

int friendSelection(fb_user user_List[], char user_select[], char friend_suggest[][100], int total_users)
{
    int i, j; /* Counters used for looping through arrays */
    int suggestion_count=0; /* Used for storing the number of suggestions added to friend_suggest[] */
    int user_index = -1; /* Used for storing index of user selected in user_List array, default is -1 for clarity */
    int friendMatch = 0; /* Boolean used for checking if a match was found on the user selected's friend list, or the friend_suggest list */

    friendSort(user_List, 0, total_users - 1); /* Quick-sort based algorithm for sorting users based on number of friends */
    /*
    for(i=0;i<total_users;i++)
    {
        printf("Username %d: %s", i, user_List[i].username);
    }
    */
    alphabetise(user_List, total_users - 1);
    /*
    for(i=0;i<total_users;i++)
    {
        printf("Username %d: %s", i, user_List[i].username);
    }

    printf("User Selected: %s", user_select);
    */

    for(i=0;i<total_users && user_index == -1;i++) /*Loops through sorted user_List[] to find the index of the user selected */
    {
        if(strcmp(user_List[i].username, user_select) == 0) /* Compares against user selected */
        {
            printf("User Index: %d\n", user_index); /* DELETE THIS */
            user_index = i; /* Stores index of the user selected in sorted array */
            printf("User Index: %d\n", user_index); /* DELETE THIS */
        }
    }

    for(i=0;i<total_users && suggestion_count != 2; i++) /* Loops through the users to find suggestions who meeet criteria below*/
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

    printf("Suggestion Count: %d\n", suggestion_count); /* DELETE THIS */

    switch(suggestion_count) /* Returns a message based on how many suggestions found */
    {
        case 0 : /* No user suggestions found */
            return 0;
        case 1 : /* One user suggestion found */
            return 1;
        case 2: /* Two user suggestions found */
            return 2;
        default: /* Error message */
            printf("Suggestion Count: %d\n", suggestion_count); /* DELETE THIS */
            return -1;
    }
}