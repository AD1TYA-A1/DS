#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x)
{
    if (x<0)
    {
        return false;
    }
    
    int y = x;
    int reverse = 0;
    int n = 0;
    while (y != 0)
    {
        if (reverse>(INT_MAX-n)/10)
        {
            return false;
        }
        
        reverse = reverse * 10;
        n = y % 10;
        y = y / 10;
        reverse = reverse+n;
    }
    if (reverse == x)
    {
        return true;
    }
    return false;
    
}
int main(int argc, char const *argv[])
{
    bool a = isPalindrome(1);
    printf("%d",a);
    return 0;
}
