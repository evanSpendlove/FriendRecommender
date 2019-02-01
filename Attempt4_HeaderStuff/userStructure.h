/* 
    Defines a new structure, fb_user, in which I store 
    each username and up to (inclusive) 4 of their friends.
    It also includes the total number of their friends.
*/

#ifndef userStructure_h
#define userStructure_h

typedef struct fb_user
{
    char username[100];
    char friend[4][100]; /* Initialises a 2D array of 4 friends with each friend being represented as an array of 100 char */
    int friend_count;
} fb_user;

#endif

typedef struct fb_user fb_user;