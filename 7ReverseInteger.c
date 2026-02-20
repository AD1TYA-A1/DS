#include <stdio.h>

int reverse(int x)
{
    int y = x;
    int xUnSigned = 0;
    if (y < 0)
    {
        while (y != 0)
        {
            y++;
            xUnSigned++;
        }
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
        if (n != 0)
        {
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
        int signRevNumber = 0;
        while (revNumber != 0)
        {
            revNumber--;
            signRevNumber--;
        }
        return signRevNumber;
    }
    return revNumber;
}

int main(int argc, char const *argv[])
{
    int rev = reverse(100);
    printf("%d",rev);

    return 0;
}
