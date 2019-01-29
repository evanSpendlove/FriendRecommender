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

void userSelection(fb_user user_List[], char *userSelect, int total_users)
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

    printf("User Selected: %s", userSelect);

    return 0;
}