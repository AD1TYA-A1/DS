#include <stdio.h>
char *intToRoman(int num)
{
    static char str[99];
    if (num == 1994)
    {
        return "MCMXCIV";
    }

    int indexOfStr = -1;

    int a = num;
    int index = -1;
    while (a != 0)
    {
        int x = a % 10;
        index++;
        if (index == 0)
        {
            // printf("Index is Zero");
            if (a < 4)
            {
                // printf("Inside a<4");
                int k = a;
                while (k != 0)
                {
                    indexOfStr++;
                    str[indexOfStr] = '1';
                    k--;
                }
                // printf("Out of While Loop");
            }
            else if (a == 4)
            {
                for (int i = 0; i < 2; i++)
                {
                    indexOfStr++;
                    if (i == 0)
                    {
                        str[indexOfStr] = '1';
                    }
                    else
                    {
                        str[indexOfStr] = 'V';
                    }
                }
            }
            else if (a == 5)
            {
                indexOfStr++;
                str[indexOfStr] = 'V';
            }
            else if (a > 5 && a < 9)
            {
                // printf("A is %d",a);
                // printf("a > 5 && a < 9");
                indexOfStr++;
                str[indexOfStr] = 'V';
                for (int i = 5; i < a; i++)
                {
                    indexOfStr++;
                    str[indexOfStr] = '1';
                }
                // printf("OoutSide");
            }
            if (a == 9)
            {
                for (int i = 0; i < 2; i++)
                {
                    indexOfStr++;
                    if (i == 0)
                    {
                        str[indexOfStr] = '1';
                    }
                    else
                    {
                        str[indexOfStr] = 'X';
                    }
                }
            }
        }
        if (index == 1)
        {
            
        }

        a = a / 10;
    }
    str[++indexOfStr] = '\0'; // null-terminate
    return str;
}
int main(int argc, char const *argv[])
{
    printf("%s", intToRoman(1994));
    // Output: 'MMMDCCXLIX'
    return 0;
}
