/*
    C Library Header file
    --> Defines functions used for User Input / Output in main.c
    Written by: Evan Spendlove (18492656)
*/

#include "userStructure.h"

/* 
    input() Function:
    Goal: take input from the user, store it in userList array from main and keep a count of total users
    It stores the input in the userList array using pointers.
    It also keeps a count of the total number of users
    and stores it in the totalUsers variable using pointers.
*/
void input(fb_user userList[], int *totalUsers);

/*
    userSelection() Function:
    Goal: To output a list of users with appropriate keys to the user as a prompt for selection.
        - Outputs a list of users as a prompt.
        - Takes user selection.
        - Stores it in an array of char in the main, using pointers.
    
    Note: As userSelect, from main, is being modified using pointers, it will retain the name used in main.
*/
void userSelection(fb_user user_List[], char userSelect[], int total_users);