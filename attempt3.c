/* 24/1/19: Attempt 1 */

#include <stdio.h>
#include <string.h>

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

/* 
    Defines a new structure, fb_user, in which I store 
    each username and up to (inclusive) 4 of their friends.
    It also includes the total number of their friends.
*/
typedef struct fb_user
{
    char username[100];
    char friend[4][100]; /* Initialises a 2D array of 4 friends with each friend being represented as an array of 100 char */
    int friend_count;
} fb_user;

/* 
    input Function:
    Goal: take input from the user, store it in userList array from main and keep a count of total users
    It stores the input in the userList array using pointers.
    It also keeps a count of the total number of users
    and stores it in the totalUsers variable using pointers.
*/
void input(fb_user userList[], int *totalUsers, int n)
{
    int i, j, k, l; /* Four counters for looping through the user_input (stored in userList) array and for storing input */
    fb_user newUserList[24];
    int newUserCount=0;
    int newIndex=0;
    for(i=0;i<n;i++)
    {
        printf("Please enter a user:\n"); /* Prompts the user to enter a user */
        fgets(userList[i].username,100,stdin); /* Stores the username in that property of the user_input[i] variable */
         {
            if(userList[i].username[0] != '\n') /* if the user does not enter a newline, continue to friend input */
            {
                for(j=0;j<4;j++) /* Loops through up to four friends */
                {
                    printf("Please enter friend %d for ",j+1); /* Prompts user to input a friend */
                    printf("%s", userList[i].username);
                    fgets(userList[i].friend[j],100,stdin); /* Takes user input and stores it in .friend */
                    if(userList[i].friend[j][0] != '\n') /* If user does not enter a newline, increment counter and continue to next iteration */
                    {
                        userList[i].friend_count++;
                    }
                    else /* If user does enter a newline, then exit the friend-input loop */
                    {
                        break;
                    }
                }
                *totalUsers = *totalUsers + 1; /* Increment the user_count variable and continue to next iteration of user-input loop */
            }
            else /* User must have inputted newline character, so break user-input loop */
            {
                break;
            }
         }
    }
}

/*
    userSelection Function:
    Goal: To output a list of users with appropriate keys to the user as a prompt for selection.
        - Outputs a list of users as a prompt.
        - Takes user selection.
        - Stores it in an array of char in the main, using pointers.
    
    Note: As userSelect, from main, is being modified using pointers, it will retain the name used in main.
*/
void userSelection(fb_user user_List[], char userSelect[], int total_users)
{
    int i; /* Counter for looping through users when printing them to console */
    int selection; /* Used for storing index of selected user in user_List[] */

    /* Outputs a list of users */
    for(i=0;i<total_users && user_List[i].username[0] != '\n';i++)
    {
        printf("(%d) ",i+1);
        printf("%s", user_List[i].username);
    }

    printf("Please select a user by inputting the number beside your chosen user: "); /* Prompts user to select a user */
    scanf("%d", &selection); /* Takes user input and stores it in selection */
    strcpy(userSelect,user_List[selection-1].username); /* Stores username of selected user in userSelect variable in main, using pointers*/
}

/* 
    swap Function:
    Goal: To swap two elements (structures) using a temp variable
*/
void swap(fb_user *a, fb_user *b)
{
    fb_user temp = *a;
    *a = *b;
    *b = temp;
}
/*
    partition Function:
    Goal: ???
    ???
    ???
*/
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

/*
    friendSort function:
    Goal: To sort the users in user_List[] by their friend count, so that the user with most friends is at the top.
    
    Note: Utilises QuickSort algorithm to do so.
*/

void friendSort(fb_user user_List[], int min, int max)
{
    if(min < max)
    {
        int pi = partition(user_List, min, max);
        friendSort(user_List, min, pi - 1);
        friendSort(user_List, pi + 1, max);
    }
}

/*
    alphabetise Function:
    Goal: to alphabetise the user_List[] passed from friendSelection(), provided the users have the same friend count.
    - Capitalises the first letter of each word
    - Puts all other letters into lowercase
    - Checks if two users have the same friend count
    - If they do, sorts them alphabetically

    NOT WORKING CORRECTLY
*/

void alphabetise(fb_user *user_List, int total_users)
{
    int i, j; /* Counters used for looping over the user_List[] array */

    for(i=0;i<=total_users;i++)
    {
        for(j=0;j<100 && user_List[i].username[j] != '\n';j++)
        {
            if(j == 0)
            {
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z')
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32;
                }
            }
            else if (user_List[i].username[j] == ' ')
            {
                ++j; /* If this character is a space, capitalise the next letter */
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z')
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32;
                }
            }
            else
            {
                if(user_List[i].username[j] >= 'A' && user_List[i].username[j] <= 'Z')
                {
                    user_List[i].username[j] = user_List[i].username[j] + 32;
                }
            }
        }
    }

    for(i=0;i<total_users;i++)
    {
        for(j=0;j<total_users;j++)
        {
            if(strcmp(user_List[i].username, user_List[j].username) < 0 && user_List[i].friend_count == user_List[j].friend_count)
            {
                swap(&user_List[i], &user_List[j]);
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

    friendSort(user_List, 0, total_users - 1);
    for(i=0;i<total_users;i++)
    {
        printf("Username %d: %s", i, user_List[i].username);
    }
    alphabetise(user_List, total_users - 1);
    for(i=0;i<total_users;i++)
    {
        printf("Username %d: %s", i, user_List[i].username);
    }

    printf("User Selected: %s", user_select);

    for(i=0;i<total_users && user_index == -1;i++) /*Loops through sorted user_List[] to find the index of the user selected */
    {
        if(strcmp(user_List[i].username, user_select) == 0) /* Compares against user selected */
        {
            printf("User Index: %d\n", user_index);
            user_index = i; /* Stores index of the user selected in sorted array */
            printf("User Index: %d\n", user_index);
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

    printf("Suggestion Count: %d\n", suggestion_count);

    switch(suggestion_count) /* Returns a message based on how many suggestions found */
    {
        case 0 : /* No user suggestions found */
            return 0;
        case 1 : /* One user suggestion found */
            return 1;
        case 2: /* Two user suggestions found */
            return 2;
        default: /* Error message */
            printf("Suggestion Count: %d\n", suggestion_count);
            return -1;
    }
}

int main(void)
{
    fb_user userList[30]; /* Initialises an array of thirty (4*6 + 6) users in userList */
    int n = 6; /* Initialises n, the number of users in the array userList */
    int totalUsers; /* Used for storing count of totalUsers */
    int friendsFound; /* Used for keeping track of friend suggestions found */
    char userSelect[100]; /* Used for storing the username of the user selected for friend suggestion */
    char friendSuggest[2][100]; /* 2d Array used for storing friend suggestions by username */

    input(userList, &totalUsers, n);
    /* PROBLEM HERE! */
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