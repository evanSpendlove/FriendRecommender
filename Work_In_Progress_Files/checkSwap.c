#include <stdio.h>

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

int main(void)
{
    fb_user test1;
    fb_user test2;

    test1.username[0] = 'A';
    test1.friend[0][0] = 'X';
    test1.friend_count = 1;

    test2.username[0] = 'B';
    test2.friend[0][0] = 'Y';
    test2.friend_count = 2;

    printf("Username 1: %c\n", test1.username[0]);
    printf("Username 2: %c\n", test2.username[0]);

    printf("U1 Friend 1: %c\n", test1.friend[0][0]);
    printf("U2 Friend 1: %c\n", test2.friend[0][0]);
    printf("\n\n");

    swap(&test1, &test2);

    printf("Username 1: %c\n", test1.username[0]);
    printf("Username 2: %c\n", test2.username[0]);

    printf("U1 Friend 1: %c\n", test1.friend[0][0]);
    printf("U2 Friend 1: %c\n", test2.friend[0][0]);
    printf("U1 Friends: %d\n", test1.friend_count);
    printf("U2 Friends: %d\n", test2.friend_count);
    

    return 0;
}