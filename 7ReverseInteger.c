#include <stdio.h>
#include <limits.h> // Header File that contains limits like, gives you INT_MAX and INT_MIN automatically

int reverse(int x)
{
    int zeroAtEnd = 1;
    int y = x;
    int xUnSigned = 0;
    if (y < 0)
    {
        if (y == (INT_MIN)) // Fixing the Run Time Error
        {
            return 0; // Would overflow
        }
        xUnSigned = -y;
        printf("UnsignedX is %d \n", xUnSigned);
    }
    else
    {
        xUnSigned = y;
    }
    // printf("%d",xUnSigned);

    int n = 0;
    int x1 = xUnSigned;
    int revNumber = 0;
    while (x1 != 0)
    {
        // printf("revNumber at line 27 %d \n", revNumber);
        n = x1 % 10;
        // printf("N is %d \n", n);
        if (n == xUnSigned)
        {
            return x;
        }
        if (n != 0 || !zeroAtEnd)
        {
            zeroAtEnd = 0;
            /*
            When revNumber is large (like 964632435), multiplying it by 10 gives 9646324350 — which exceeds the maximum value of a 32-bit signed integer (INT_MAX = 2,147,483,647).
            Since int in C is 32-bit, it simply cannot hold that value, causing an overflow.
            */
            if (revNumber > (INT_MAX - n) / 10) // Fixing the Run Time Error
            {
                return 0; // Would overflow
            }
            revNumber = revNumber * 10;

            // printf("Not Zero \n");
            revNumber = revNumber + n;
            // printf(" revNumber : %d \n");
        }

        // else
        // {
        //     printf("It is Zero \n");
        // }
        x1 = x1 / 10;
    }
    // printf("%d \n", revNumber);

    if (x < 0)
    {
        return -revNumber;
    }
    return revNumber;
}

int main(int argc, char const *argv[])
{
    int rev = reverse(9900100);
    printf("%d", rev);

    return 0;
}
