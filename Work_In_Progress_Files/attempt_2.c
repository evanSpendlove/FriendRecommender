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
    Input function takes input from the user.
    It stores the input in the userList array using pointers.
    It also keeps a count of the total number of users
    and stores it in the totalUsers variable using pointers.
*/
void input(fb_user *userList, int *totalUsers, int n)
{
    int i, j; /* Two counters for looping through the user_input (stored in userList) array and for storing input */
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
    userSelection Function
    Goal: To output a list of users with appropriate keys to the user as a prompt for selection.
        - Outputs a list of users as a prompt.
        - Takes user selection.
        - Stores it in an array of char in the main, using pointers.
    
    Note: As userSelect, from main, is being modified using pointers, it will retain the name used in main.
*/
void userSelection(fb_user user_List[], char *userSelect, int total_users)
{
    int i;
    int selection;

    /* Outputs a list of users */
    for(i=0;i<total_users && user_List[i].username[0] != '\n';i++)
    {
        printf("(%d) ",i+1);
        printf("%s", user_List[i].username);
    }

    printf("Please select a user by inputting the number beside your chosen user: "); /* Prompts user to select a user */
    scanf("%d", &selection); /* Takes user input and stores it in selection */
    strcpy(userSelect,user_List[selection].username); /* Stores username of selected user in userSelect variable in main, using pointers*/
}

void alphabetise(fb_user *user_List, int min, int max)
{

}

int friendSelection(fb_user user_List[], char user_select[], char friend_suggest[][100], int total_users)
{
    int i, j; /* Counters used for looping through arrays */
    int suggestion_count=0; /* Used for storing the number of suggestions added to friend_suggest[] */
    int user_index = -1; /* Used for storing index of user selected in user_List array, default is -1 for clarity */

    /* quickSort(user_List, 0, n-1); */
    /* Need to write alphabetise algorithm */
   /*  alphabetise(user_List, 0, n-1); */

    for(i=0;i<total_users && user_index == -1;i++) /*Loops through sorted user_List[] to find the index of the user selected */
    {
        if(strcmp(user_List[i].username, user_select) == 0) /* Compares against user selected */
        {
            user_index = i; /* Stores index of the user selected in sorted array */
        }
    }

    for(i=0;i<total_users && suggestion_count != 2; i++) /* Loops through the users to find suggestions who meeet criteria below*/
    {
        if(i != user_index) /* If the user in user_List is not the user selected... */
        {
            for(j=0;j<user_List[user_index].friend_count;j++) /* Loops through the friends of the user_selected */
            {
                if(strcmp(user_List[i].username, user_List[user_index].friend[j]) != 0) /* Checks if the suggestion is already a friend of the user selected */
                {
                    strcpy(friend_suggest[suggestion_count], user_List[i].username); /* Copies the username of the selected user to the friend_suggest array */
                    suggestion_count++; /* Increments count of suggestions found */
                }
            }
        }
    }
    switch(suggestion_count) /* Returns a message based on how many suggestions found */
    {
        case 0 : /* No user suggestions found */
            return 0;
        case 1 : /* One user suggestion found */
            return 1;
        case 2: /* Two user suggestions found */
            return 2;
        default: /* Error message */
            return -1;
    }
}

int main(void)
{
    fb_user userList[6]; /* Initialises an array of six users in userList */
    /* Duplicates??? */
        int n = (sizeof(userList)/sizeof(userList[0])); /* Initialises n, the number of users in the array userList */
        int totalUsers; /* Used for storing count of totalUsers */
    /* ^^^ Duplicates??? */
    int friendsFound; /* Used for keeping track of friend suggestions found */
    char userSelect[100]; /* Used for storing the username of the user selected for friend suggestion */
    char friendSuggest[2][100]; /* 2d Array used for storing friend suggestions by username */

    input(userList, &totalUsers, n);

    userSelection(userList, userSelect, totalUsers);
    
    /* friendsFound = friendSelection(userList, userSelect, friendSuggest); */


    return 0;
}