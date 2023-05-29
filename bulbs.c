#include "cs50.h"
#include "cs50.c"
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void char_to_binary(char c);

int main(void)
{
    string s = get_string(NULL, "Message: ");
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char_to_binary(s[i]);
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void char_to_binary(char c)
{
    int decimal = (int) c;
    int bit;
    for (int i = BITS_IN_BYTE; i >= 0; i--)
    {
        bit = (int) pow(2, i - 1);
        if (decimal - bit >= 0)
        {
            print_bulb(1);
            decimal -= bit;
        }
        else
        {
            print_bulb(0);
        }

    }
    printf("\n");
}

