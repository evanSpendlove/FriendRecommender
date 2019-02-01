/*
   C file for library I/O functions.
   Written by: Evan Spendlove (18492656)
*/

#include "userIO.h"
#include <stdio.h>
#include <string.h>
#include "userStructure.h"

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
        printf("(%d) ",i+1); /* Prints the user number from 1 to total_users */
        printf("%s", user_List[i].username);
    }

    printf("Please select a user by inputting the number beside your chosen user: "); /* Prompts user to select a user */
    scanf("%d", &selection); /* Takes user input and stores it in selection */
    strcpy(userSelect,user_List[selection-1].username); /* Stores username of selected user in userSelect variable in main, using pointers*/
}