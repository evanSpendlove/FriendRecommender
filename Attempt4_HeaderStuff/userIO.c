/*
   C file for library I/O functions.
   Written by: Evan Spendlove (18492656)
*/

#include "userIO.h"
#include "userStructure.h"
#include <stdlib.h>

void input(fb_user userList[], int *totalUsers)
{
    int i, j; /* Two counters for looping through the user_input (stored in userList) array and for storing input */

    for(i=0;i<MAX_USERS;i++)
    {
        printf("Please enter a user:\n"); /* Prompts the user to enter a user */
        fgets(userList[i].username,100,stdin); /* Stores the username in that property of the user_input[i] variable */
         {
            if(userList[i].username[0] != '\n') /* if the user does not enter a newline, continue to friend input */
            {
                for(j=0;j<MAX_FRIEND_COUNT;j++) /* Loops through up to four friends */
                {
                    printf("Please enter friend %d for ",j+1); /* Prompts user to input a friend */
                    printf("%s", userList[i].username); /* Prints the appropriate username */
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

void userSelection(fb_user user_List[], char userSelect[], int total_users)
{
    int i; /* Counter for looping through users when printing them to console */
    int selection; /* Used for storing index of selected user in user_List[] */

    char input[100]; /* Array for storing user input */
    char* end; /* End array for storing non-integer part of user input */
    int validIn = 0; /* Integer for tracking status of valid input */

    /* Outputs a list of users */
    for(i=0;i<total_users && user_List[i].username[0] != '\n';i++)
    {
        printf("(%d) ",i+1); /* Prints the user number from 1 to total_users */
        printf("%s", user_List[i].username); /* Prints the appropriate username */
    }

    printf("Please select a user by inputting the number beside your chosen user: "); /* Prompts user to select a user */
    
    while(validIn == 0) /* While the user has not inputted a valid integer between 1 and the current max user count */
    {
        fgets(input, 100, stdin); /* Stores user input in input[] */
        selection = strtol(input, &end, 10); /* Store the integer part of this input at the address pointed to by *choice and the remainder of input in end[] */
        
        if(*end == '\n') /* If the only remaining input is the newline character */
        {
            if(selection >= 1 && selection <= total_users) /* Check if the integer lies within the range 1 to total_users */
            {
                validIn = 1; /* If it does, update validIn to 1 (i.e. true), which breaks the loop */
            }
            else /* Otherwise, print an error message requesting valid input and print the invalid input */
            {
                printf("Please input an integer between 1 and %d to select an option above, invalid input: %s", total_users, end);
            }
            
        }
        else /* Otherwise, print an error message requesting valid input and print the invalid input */ 
        {
            printf("Please input an integer between 1 and %d to select an option above, invalid input: %s", total_users, end);
        }
    }
    strcpy(userSelect,user_List[selection-1].username); /* Stores username of selected user in userSelect variable in main, using pointers */
}