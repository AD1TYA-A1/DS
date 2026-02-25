#include <stdio.h>
char *intToRoman(int num)
{
    static char str[] = "";
    int indexOfStr = -1;
    char one[] = {'I', 'X', 'C', 'M'};
    char five[] = {'V', 'L', 'D', '!'};
    char ten[] = {'X', 'C', 'M', '?'};
    int n = num;
    int place = -1;
    while (n != 0)
    {
        int a = n % 10;
        place++;

        char one_symb = one[place];
        char five_symb = five[place];
        char ten_symb = ten[place];

        if (a >= 1 && a <= 3)
        {
            for (int i = 0; i < a; i++)
            {
                indexOfStr++;
                str[indexOfStr] = one_symb;
            }
        }
        else if (a == 4)
        {
            indexOfStr++;
            str[indexOfStr] = one_symb;
            indexOfStr++;
            str[indexOfStr] = five_symb;
        }
        else if (a == 5)
        {
            indexOfStr++;
            str[indexOfStr] = five_symb;
        }
        else if (a >= 6 && a <= 8)
        {
            indexOfStr++;
            str[indexOfStr] = five_symb;
            for (int i = 5; i <= a; i++)
            {
                indexOfStr++;
                str[indexOfStr] = one_symb;
            }
        }
        else if (a == 9)
        {
            indexOfStr++;
            str[indexOfStr] = ten_symb;
            indexOfStr++;
            str[indexOfStr] = one_symb;
        }

        n = n / 10;
    }
    return str;
}
int main(int argc, char const *argv[])
{
    printf("%s", intToRoman(94));
    // Output: 'MMMDCCXLIX'
    return 0;
}
