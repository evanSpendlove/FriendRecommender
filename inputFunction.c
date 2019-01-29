#include <stdio.h>
#include <string.h>

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

int main(void)
{
    fb_user userList[30]; /* Initialises an array of thirty (4*6 + 6) users in userList */
    int n = 6; /* Initialises n, the number of users in the array userList */
    int i;
    int totalUsers; /* Used for storing count of totalUsers */
    int friendsFound; /* Used for keeping track of friend suggestions found */
    char userSelect[100]; /* Used for storing the username of the user selected for friend suggestion */
    char friendSuggest[2][100]; /* 2d Array used for storing friend suggestions by username */

    input(userList, &totalUsers, n);

    printf("Printing begins...\n");

    for(i=0;i<totalUsers;i++)
    {
        printf("Username %d: %s", i, userList[i].username);
    }


    return 0;
}