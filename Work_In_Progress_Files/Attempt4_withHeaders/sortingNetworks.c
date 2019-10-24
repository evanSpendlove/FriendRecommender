#include <stdio.h>

typedef struct fb_user
{
    char username[100];
    char friend[4][100]; /* Initialises a 2D array of 4 friends with each friend being represented as an array of 100 char */
    int friend_count;
} fb_user;

void SWAP(fb_user *a, fb_user *b)
{
    fb_user c = *a;
    fb_user d = *b;

    int x = c.friend_count;
    int y = d.friend_count;

    /* For pointers to a structure, use x->property or (*x).property */

    if(a->friend_count > b->friend_count)
    {
        printf("INT WORKS!");
    }

    printf("FC: %d\n", c.friend_count);

    if (x > y)
    {
        printf("TRUE!\n");
        fb_user temp = *a; /* Stores *a in a temp variable */
        *a = *b; /* Stores b in a */
        *b = temp; /* Stores temp (i.e. what was in a) in b */
        /* Swap is now complete - what was in a is now in b, and vice versa. */
    }
}

void sortUsersNetwork(fb_user *d)
{
    SWAP(&d[1], &d[2]);
    SWAP(&d[0], &d[2]);
    SWAP(&d[0], &d[1]);
    SWAP(&d[4], &d[5]);
    SWAP(&d[3], &d[5]);
    SWAP(&d[3], &d[4]);
    SWAP(&d[0], &d[3]);
    SWAP(&d[1], &d[4]);
    SWAP(&d[2], &d[5]);
    SWAP(&d[2], &d[4]);
    SWAP(&d[1], &d[3]);
    SWAP(&d[2], &d[3]);

    /*
        #define SWAP(x,y) if (d[y].friend_count < d[x].friend_count) {fb_user tmp = d[x]; d[x] = d[y]; d[y] = tmp;}
            SWAP(1, 2);
            SWAP(0, 2);
            SWAP(0, 1);
            SWAP(4, 5);
            SWAP(3, 5);
            SWAP(3, 4);
            SWAP(0, 3);
            SWAP(1, 4);
            SWAP(2, 5);
            SWAP(2, 4);
            SWAP(1, 3);
            SWAP(2, 3);
        #undef SWAP
    */
}
/*
static inline void sort6_sorting_network_v1(int * d){
#define SWAP(x,y) if (d[y] < d[x]) { int tmp = d[x]; d[x] = d[y]; d[y] = tmp; }
    SWAP(1, 2);
    SWAP(0, 2);
    SWAP(0, 1);
    SWAP(4, 5);
    SWAP(3, 5);
    SWAP(3, 4);
    SWAP(0, 3);
    SWAP(1, 4);
    SWAP(2, 5);
    SWAP(2, 4);
    SWAP(1, 3);
    SWAP(2, 3);
#undef SWAP
}

void sort6v2(int *d)
{
   #define SWAP(x,y) if (d[y] < d[x]) { int tmp = d[x]; d[x] = d[y]; d[y] = tmp; }
        SWAP(1,2);
        SWAP(4,5);
        SWAP(0,2);
        SWAP(3,5);
        SWAP(0,1);
        SWAP(3,4);
        SWAP(2,5);
        SWAP(0,3);
        SWAP(1,4);
        SWAP(2,4);
        SWAP(1,3);
        SWAP(2,3);
   #undef SWAP 
}
*/
int main(void)
{
    fb_user userList[6];
    int i;

    for(i=0;i<6;i++)
    {
        userList[i].friend_count = 8-i;
    }

/*
    sort6_sorting_network_v1(numbers);

    for(i=0;i<6;i++)
    {
        printf("%d, ", numbers[i]);
    }

    printf("\n");
*/
    sortUsersNetwork(userList);

    for(i=0;i<6;i++)
    {
        printf("U: %d, FC: %d.\n", i, userList[i].friend_count);
    }

    return 0;
}