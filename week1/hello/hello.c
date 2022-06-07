#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get your name
    string name = get_string("What's your name?\n");
    //Print Hello "your name"
    printf("Hello, %s\n", name);
}
