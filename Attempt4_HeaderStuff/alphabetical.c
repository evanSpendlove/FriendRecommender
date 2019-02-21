#include <stdio.h>
#include <string.h>
#define MAX_FRIEND_COUNT 4;

typedef struct fb_user
{
    char username[100];
    char friend[4][100];
    int friend_count;
} fb_user;


void SWAP(fb_user *a, fb_user *b, char sort[3])
{
    if(strcmp(sort,"alp") == 0)
    {
        if(strcasecmp(a->username,b->username) > 0)
        {
            printf("TRUE CHAR!\n");
            fb_user temp = *a; 
            *a = *b; 
            *b = temp; 
        }
    }
    else if(strcmp(sort,"int") == 0)
    {
        if(a->friend_count > b->friend_count)
        {
            printf("TRUE INT!\n");
            fb_user temp = *a; 
            *a = *b; 
            *b = temp; 
        }
    }
    else if(strcmp(sort,"reg") == 0)
    {
        fb_user temp = *a; 
        *a = *b; 
        *b = temp; 
    }
    else
    {
        printf("Error: Invalid Sort Request");
    }
    
}

void stringNetwork(fb_user *d, char sort[3])
{
    SWAP(&d[1], &d[2], sort);
    SWAP(&d[0], &d[2], sort);
    SWAP(&d[0], &d[1], sort);
    SWAP(&d[4], &d[5], sort);
    SWAP(&d[3], &d[5], sort);
    SWAP(&d[3], &d[4], sort);
    SWAP(&d[0], &d[3], sort);
    SWAP(&d[1], &d[4], sort);
    SWAP(&d[2], &d[5], sort);
    SWAP(&d[2], &d[4], sort);
    SWAP(&d[1], &d[3], sort);
    SWAP(&d[2], &d[3], sort);
}

void conditioncheck(fb_user *userList, char userSelect, int n)
{
    int i;
    int found = 0;
    char sortType[3] = "reg";

    for(i=0;i<n && found != 1;i++) /*Loops through sorted user_List[] to find the index of the user selected */
    {
        if(strcmp(userList[i].username, userSelect) == 0) /* Compares against user selected */
        {
            SWAP(&userList[i],&userList[n-1],sortType);
            n--;
        }
    }
}

int main(void)
{
    fb_user userList[6];
    char sortType[3];

    int n = 6;
    char userSelect[4] = "Mary";

    int i;

        /*
        scanf("%9[^\n]", word1);
        scanf(" %9[^\n]", word2);
        */
    
    printf("What type of sort do you want?\n");
    scanf("%5[^\n]", sortType);

    printf("%s\n", sortType);

    if(strcmp(sortType,"alp") == 0)
    {
        for(i=0;i<6;i++)
        {
            printf("Please enter a name:\n");
            scanf(" %99[^\n]",userList[i].username);
        }

        for(i=0;i<6;i++)
        {
            printf("U: %s\n", userList[i].username);
        }

        stringNetwork(userList, sortType);

        for(i=0;i<6;i++)
        {
            printf("U: %s\n", userList[i].username);
        }
    }

    else if(strcmp(sortType,"int") == 0)
    {
        for(i=0;i<6;i++)
        {
            userList[i].friend_count = 8-i;
        }

        stringNetwork(userList, sortType);

        for(i=0;i<6;i++)
        {
            printf("U: %d, FC: %d.\n", i, userList[i].friend_count);
        }
    }

    else if(strcmp(sortType,"reg") == 0)
    {

    }

}