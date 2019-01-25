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

void input(fb_user *user_input, int *userCount)
{
    int i, j, k;
    for(i=1;i<7;i++)
    {
        printf("Please enter a user:\n");
        fgets(user_input[i].username,100,stdin);
        {
            if(user_input[i].username[0] != '\n')
            {
                for(j=1;j<5;j++)
                {
                    printf("Please enter friend %d for ",j);
                    for(k=0;k<100 && user_input[i].username[k] != '\n';k++)
                    {
                        printf("%c",user_input[i].username[k]);
                    }
                    printf("\n");
                    fgets(user_input[i].friend[j],100,stdin);
                    if(user_input[i].friend[j][0] != '\n')
                    {
                        user_input[i].friend_count++;
                    }
                    else
                    {
                        break;
                    }
                }
                *userCount = *userCount + 1;
            }
            else
            {
                break;
            }
            
        }
    }
}

void userSelection(fb_user *user_List, int *userSelect)
{
    int i, j;

    /* Outputs a list of users */
    for(i=1;i<7 && user_List[i].username[0] != '\n';i++)
    {
        printf("(%d) ",i);
        for(j=0;j<100 && user_List[i].username[j] != '\n';j++)
        {
            printf("%c", user_List[i].username[j]);
        }
        printf("\n");
    }

    scanf("%d",userSelect);
}

int main(void)
{
    fb_user userList[6];
    int totalUsers;
    int userSelect;

    input(userList, &totalUsers);

    userSelection(userList, &userSelect);
    


    return 0;
}