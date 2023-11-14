#include "binary.h"

int main(int argc, char *argv[])
{
    (void)argc;
    char* bin1 = argv[1];
    char* opp = argv[2];
    char* bin2 = argv[3];

    if (opp[0] == '+')
    {
        AddBinary(bin1, bin2);
    }
    else if (opp[0] == '-')
    {
        SubtractBinary(bin1, bin2);
    }

    return 0;
}