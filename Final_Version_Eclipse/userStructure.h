/* 
    Defines a new structure, fb_user, in which I store 
    each username and up to (inclusive) 4 of their friends.
    It also includes the total number of their friends.
*/

#ifndef userStructure_h
#define userStructure_h

/* 
    Below, I initialise all of the constant values that I will be using throughout my program.

    I initialise them all here, in this header, as it is used by all of the other files in my project.

    They are also all grouped together, so they can be easily changed to adjust the project to different specifications.
*/

static const int MAX_USERS = 6; /* Max number of users */
static const int MAX_FRIEND_COUNT = 4; /* Max number of friends per user */
static const int MAX_CHAR_COUNT = 100; /* Max number of characters in a username */
static const int MAX_FRIEND_SUGGEST = 2; /* Max number of friend suggestions */

typedef struct fb_user
{
    char username[MAX_CHAR_COUNT]; /* Initialises an array of characters to store the username of the user */
    char friend[MAX_FRIEND_COUNT][MAX_CHAR_COUNT]; /* Initialises a 2D array of 4 friends with each friend being represented as an array of 100 char */
    int friend_count; /* Initialises an integer for storing the friend count of the user */
} fb_user;

#endif

typedef struct fb_user fb_user;
