#include <cs50.h>
#include <stdio.h>

//Create Super Mario Brothers customize adjacent pyramids of blocks
int main(void)
{
    // Get number of rows of blocks between 1 and 8 inclusive
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Create number of n rows
    for (int i = 0; i < n; i++)
    {
        // Do space bar (n rows - 1) times
        for (int a = n - 1; a > i; a--)
        {
            printf(" ");
        }
        // Create bricks on left side as # (i+1) times
        for (int b = -1; b < i; b++)
        {
            printf("#");
        }
        // Two space bar in the middle before right half of pyramid
        printf("  ");
        // Create bricks on right side as # (i+1) times
        for (int b = -1; b < i; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}