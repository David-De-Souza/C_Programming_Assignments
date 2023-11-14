#include <stdio.h>
#include "Binary.h"

int BitToInt(char bit)
{
    if (bit == '1')
        return 1;
    return 0;
}

void PrintBinaries(char bin1[BIT_COUNT], char bin2[BIT_COUNT], char result[BIT_COUNT], char operator)
{
    printf("  ");
    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%c", bin1[i]);
    }
    printf("\n%c ", operator);

    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%c", bin2[i]);
    }
    printf("\n----------\n  ");

    for (int i = 0; i < BIT_COUNT; ++i)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}

int CheckBinary(char bin[BIT_COUNT])
{
    for (int i = 0; i < BIT_COUNT; ++i)
    {
        if (bin[i] != '0' && bin[i] != '1')
        {
            printf("%s is not a valid binary number\n", bin);
            return 0;
        }
    }
    return 1;
}

void AddBinary(char bin1[BIT_COUNT], char bin2[BIT_COUNT])
{
    if (!CheckBinary(bin1) || !CheckBinary(bin2))
        return;

    char result[BIT_COUNT + 1] = "00000000";
    int carry = 0;
    for (int i = BIT_COUNT - 1; i >= 0; --i)
    {
        int bit1 = BitToInt(bin1[i]);
        int bit2 = BitToInt(bin2[i]);
        int resultBit = bit1 + bit2 + carry;

        if (resultBit == 0)
        {
            result[i] = '0';
            carry = 0;
        }
        else if (resultBit == 1)
        {
            result[i] = '1';
            carry = 0;
        }
        else if (resultBit == 2)
        {
            result[i] = '0';
            carry = 1;
        }
        else if (resultBit == 3)
        {
            result[i] = '1';
            carry = 1;
        }
    }

    PrintBinaries(bin1, bin2, result, '+');
}

void SubtractBinary(char bin1[BIT_COUNT], char bin2[BIT_COUNT])
{
    if (!CheckBinary(bin1) || !CheckBinary(bin2))
        return;

    char result[BIT_COUNT + 1] = "00000000";
    int carry = 0;
    for (int i = BIT_COUNT - 1; i >= 0; --i)
    {
        int bit1 = BitToInt(bin1[i]);
        int bit2 = BitToInt(bin2[i]);

        int resultBit = bit1 - bit2 - carry;

        if (resultBit < 0) {
            resultBit += 2;
            carry = 1;
        } else {
            carry = 0;
        }

        result[i] = (char)resultBit + '0';
    }

    PrintBinaries(bin1, bin2, result, '-');
}