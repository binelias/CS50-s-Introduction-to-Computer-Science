#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Ask for credit card number
    long long cardNumber;
    do
    {
        cardNumber = get_long_long("Credit Card Number: ");
    }
    while (cardNumber < 0);

    //Count the number of digits of credit card number
    int count = 0;
    long long a = cardNumber;
    while (a > 0)
    {
        a = a / 10;
        count++;
    }

    //Multiply every other digit of credit card number by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
    long long b = cardNumber;
    int sum1 = 0;
    int remainder1;
    int remainder2;
    while (b != 0)
    {
        remainder2 = 2 * ((b % 100) / 10);
        remainder1 = (remainder2 % 10) + (remainder2 / 10);
        sum1 += remainder1;
        b /= 100;
    }

    //Add the sum to the sum of the digits that weren’t multiplied by 2.
    long long c = cardNumber;
    int sum2 = 0;
    int remainder3;
    while (c != 0)
    {
        remainder3 = c % 10;
        sum2 += remainder3;
        c /= 100;
    }

    //Get the Luhn's Algorithm sum
    int checkSum = sum1 + sum2;

    // Get the first two digit of credit card number
    int firstDigit = cardNumber / pow(10, (count - 2));

    //Identify the credit card number if it is valid(last digit of checkSum is 0), otherwise invalid credit card number
    if (checkSum % 10 == 0 && count == 15 && (firstDigit == 37 || firstDigit == 34))
    {
        printf("AMEX\n");
    }
    else if (checkSum % 10 == 0 && count == 16 && (firstDigit >= 51 && firstDigit <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (checkSum % 10 == 0 && (count == 13 || count == 16) && ((firstDigit / 10) == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}