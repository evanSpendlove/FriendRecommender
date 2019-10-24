#include "sortingNetwork.h"

void SWAP(fb_user *a, fb_user *b, char sort[3])
{
    /*
        alp = alphabetic sorting
        int = integer (friend_count) sorting
    */

    if(strcmp(sort,"alp") == 0) /* Checks if the SWAP() call is for alphabetical sorting */
    {
        if(strcasecmp(a->username,b->username) > 0 && a->friend_count == b->friend_count) /* If the friend count is the same and a and b are out of alphabetical order */
        {
            fb_user temp = *a; /* Stores *a in a temp variable */
            *a = *b; /* Stores b in a */
            *b = temp; /* Stores temp (i.e. what was in a) in b */
            /* Swap is now complete - what was in a is now in b, and vice versa. */
        }
    }
    else if (strcmp(sort,"int") == 0) /* Checks if the SWAP() call is for integer sorting */
    {
        if(a->friend_count < b->friend_count) /* If the a has less friends than b (so the person with least friends is last) */
        {
            fb_user temp = *a; /* Stores *a in a temp variable */
            *a = *b; /* Stores b in a */
            *b = temp; /* Stores temp (i.e. what was in a) in b */
            /* Swap is now complete - what was in a is now in b, and vice versa. */
        }
    }
    else /* If the function call did not include either of these clarifications, then an error ocurred */
    {
        printf("Error: Invalid Sort Request"); /* Print an error to the user */
    }
}

void sortNetwork(fb_user *d, char sort[3], int total_users)
{
    switch(total_users) /* Uses different sorting networks based on the number of users */
    {
        case 2: /* Sorting Network for 2 inputs */
            SWAP(&d[0], &d[1], sort); /* Only one comparator needed when two inputs */
            break; /* Exit switch */
        case 3: /* Sorting Network for 3 inputs */
            SWAP(&d[1], &d[2], sort);
            SWAP(&d[0], &d[2], sort);
            SWAP(&d[0], &d[1], sort);
            break; /* Exit switch */
        case 4: /* Sorting Network for 4 inputs */
            SWAP(&d[0], &d[1], sort);
            SWAP(&d[2], &d[3], sort);
            SWAP(&d[0], &d[2], sort);
            SWAP(&d[1], &d[3], sort);
            SWAP(&d[1], &d[2], sort);
            break; /* Exit switch */
        case 5: /* Sorting Network for 5 inputs */
            SWAP(&d[0], &d[1], sort);
            SWAP(&d[3], &d[4], sort);
            SWAP(&d[2], &d[4], sort);
            SWAP(&d[2], &d[3], sort);
            SWAP(&d[0], &d[3], sort);
            SWAP(&d[0], &d[2], sort);
            SWAP(&d[1], &d[4], sort);
            SWAP(&d[1], &d[3], sort);
            SWAP(&d[1], &d[2], sort);
            break; /* Exit switch */
        case 6: /* Sorting Network for 6 inputs */
            SWAP(&d[1], &d[2], sort);
            SWAP(&d[0], &d[2], sort);
            SWAP(&d[0], &d[1], sort);
            SWAP(&d[4], &d[5], sort);
            SWAP(&d[3], &d[5], sort);
            SWAP(&d[3], &d[4], sort);
            SWAP(&d[0], &d[3], sort);
            SWAP(&d[1], &d[4], sort);
            SWAP(&d[2], &d[5], sort);
            SWAP(&d[2], &d[4], sort);
            SWAP(&d[1], &d[3], sort);
            SWAP(&d[2], &d[3], sort);
            break; /* Exit switch */
        default:
            printf("Error: invalid number of users."); /* If the number of users is <2 or >6, then there's a problem */
    }
}

int friendSelection2(fb_user user_List[], char user_select[], char friend_suggest[][MAX_CHAR_COUNT], int total_users)
{
    int i, j; /* Counters used for looping through arrays */
    int suggestion_count = 0; /* Used for storing the number of suggestions added to friend_suggest[] */
    int user_index = -1; /* Used for storing index of user selected in user_List array, default is -1 for clarity */
    int friendMatch = 0; /* Boolean used for checking if a match was found on the user selected's friend list, or the friend_suggest list */

    sortNetwork(user_List,"int",total_users); /* Utilises sorting networks to sort users based on number of friends */
    sortNetwork(user_List,"alp",total_users); /* Utilises sorting networks to sort users, with equal friend counts, alphabetically */

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

    return suggestion_count;
}