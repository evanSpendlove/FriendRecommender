/* 24/1/19: Attempt 1 */

#include <stdio.h>
#include <string.h>

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

void input(fb_user *user_input[])
{

}

int main(void)
{
    fb_user userList[6];

    input(userList[]);


    return 0;
}