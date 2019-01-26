#include <stdio.h>

typedef struct fb_user
{
    char username[100];
    char friend[4][100];
    int friend_count;
} fb_user;

/* Swap function - swaps the values in two elements */
void swap(fb_user *a, fb_user *b)
{
    fb_user temp = *a;
    *a = *b;
    *b = temp;
}

int partition(fb_user users[], int min, int max)
{
    int pivot = users[max].friend_count;
    int small = (min - 1);
    int j;

    for(j = min; j <= max - 1; j++)
    {
        if(users[j].friend_count <= pivot)
        {
            small++;
            swap(&users[small], &users[j]);
        }
    }
    swap(&users[small+1], &users[max]);
    return (small + 1);
}

void quickSort(fb_user users[], int min, int max)
{
    if(min < max)
    {
        int pi = partition(users, min, max);
        quickSort(users, min, pi - 1);
        quickSort(users, pi + 1, max);
    }
}

int main() 
{ 
    fb_user users[6];

    users[0].username[0] = 'A';
    users[1].username[0] = 'B';
    users[2].username[0] = 'C';
    users[3].username[0] = 'D';
    users[4].username[0] = 'E';
    users[5].username[0] = 'F';

    users[0].friend_count = 6;
    users[1].friend_count = 5;
    users[2].friend_count = 4;
    users[3].friend_count = 3;
    users[4].friend_count = 2;
    users[5].friend_count = 1;

    printf("User 1: %c\n", users[0].username[0]);
    printf("User 2: %c\n", users[1].username[0]);
    printf("User 3: %c\n", users[2].username[0]);
    printf("User 4: %c\n", users[3].username[0]);
    printf("User 5: %c\n", users[4].username[0]);
    printf("User 6: %c\n", users[5].username[0]);

    printf("User 1 FC: %d\n", users[0].friend_count);
    printf("User 1 FC: %d\n", users[1].friend_count);
    printf("User 1 FC: %d\n", users[2].friend_count);
    printf("User 1 FC: %d\n", users[3].friend_count);
    printf("User 1 FC: %d\n", users[4].friend_count);
    printf("User 1 FC: %d\n", users[5].friend_count);
    

    quickSort(users, 0, 5);

    printf("QuickSort complete: \n \n");

    printf("User 1: %c\n", users[0].username[0]);
    printf("User 2: %c\n", users[1].username[0]);
    printf("User 3: %c\n", users[2].username[0]);
    printf("User 4: %c\n", users[3].username[0]);
    printf("User 5: %c\n", users[4].username[0]);
    printf("User 6: %c\n", users[5].username[0]);

    printf("User 1 FC: %d\n", users[0].friend_count);
    printf("User 1 FC: %d\n", users[1].friend_count);
    printf("User 1 FC: %d\n", users[2].friend_count);
    printf("User 1 FC: %d\n", users[3].friend_count);
    printf("User 1 FC: %d\n", users[4].friend_count);
    printf("User 1 FC: %d\n", users[5].friend_count);
    return 0; 
} 