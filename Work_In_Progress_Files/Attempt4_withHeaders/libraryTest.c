#include <stdio.h>
#include "userStructure.h"
#include <string.h>
#include "userIO.h"

int main(void)
{
    fb_user john;
    fb_user userList[4];
    int *totalusers;

    strcpy(john.username,"John");

    printf("Username: %s\n", john.username);

    input(userList,totalusers,4);

    return 0;
}