#include <stdio.h>
#include <string.h>

typedef struct fb_user
{
    char username[100];
    char friend[4][100];
    int friend_count;
} fb_user;

void swap(fb_user *a, fb_user *b)
{
    fb_user temp = *a;
    *a = *b;
    *b = temp;
}

void alphabetise(fb_user *user_List, int n)
{
    int i, j;

    for(i=0;i<n;i++)
    {
        /* Change \0 to \n when putting into main program */
        for(j=0;j<100 && user_List[i].username[j] != '\0';j++)
        {
            if(j == 0)
            {
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z')
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32;
                }
            }
            else if (user_List[i].username[j] == ' ')
            {
                ++j; /* If this character is a space, capitalise the next letter */
                if(user_List[i].username[j] >= 'a' && user_List[i].username[j] <= 'z')
                {
                    user_List[i].username[j] = user_List[i].username[j] - 32;
                }
            }
            else
            {
                if(user_List[i].username[j] >= 'A' && user_List[i].username[j] <= 'Z')
                {
                    user_List[i].username[j] = user_List[i].username[j] + 32;
                }
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strcmp(user_List[i].username, user_List[j].username) < 0 && user_List[i].friend_count == user_List[j].friend_count)
            {
                swap(&user_List[i], &user_List[j]);
            }
        }
    }
}

int main(void)
{
    fb_user userList[6];

    strcpy(userList[0].username, "Ben");
    strcpy(userList[1].username, "Carrie");
    strcpy(userList[2].username, "Fred");
    strcpy(userList[3].username, "evan");
    strcpy(userList[4].username, "ADAM");
    strcpy(userList[5].username, "Donal");

    userList[0].friend_count = 6;
    userList[1].friend_count = 5;
    userList[2].friend_count = 3;
    userList[3].friend_count = 3;
    userList[4].friend_count = 3;
    userList[5].friend_count = 1;

    int n = (sizeof(userList)/sizeof(userList[0]));
    int i;

    for(i=0;i<n;i++)
    {
        printf("%s\n", userList[i].username);
    }

    alphabetise(userList, n);

    printf("\n Alphabetising complete!\n");

    for(i=0;i<n;i++)
    {
        printf("%s\n", userList[i].username);
    }
    
}