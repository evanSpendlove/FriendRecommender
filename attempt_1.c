/* 24/1/19: Attempt 1 */

#include <stdio.h>

/* 
    Defines a new structure, fb_user, in which I store 
    each user and up to (inclusive) 4 of their friends.
    It also includes the total number of their friends.
*/
typedef struct fb_user
{
    char username[100];
    char friend[4][100];
    int friend_count;
} fb_user;

int main(void)
{
    
    return 0;
}