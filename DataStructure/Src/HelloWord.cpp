//
// Created by Aphcity on 2021/08/14.
//

#include <stdio.h>

int main()
{
    printf("Hello, DataStructure!\n");
    // for (int i = 0; i < 200; i++)
    // {
    //     printf("%c\t", i);
    // }
    int a = 22;
    int *p1 = &a;
    int **p2 = &p1;
    //int *p3 = &p1;
    printf("%d", **p2);
}