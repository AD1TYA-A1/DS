#include <stdio.h>
#include <string.h>
char *longestCommonPrefix(char **strs, int strsSize)
{
    char *returnStr = (char *)malloc(200 * sizeof(char));
    returnStr[0] = '\0'; // Initialize as empty string
    int index = 0;
    for (int j = 0; strs[0][j] != '/0'; j++)
    {
        char temp = strs[0][j];
        int allMatch = 1; // Flag to check if all strings match
        for (int i = 0; i < strsSize; i++)
        {
            if (temp != strs[i][j] || strs[i][j] == '/0')
            {
                allMatch = 0;
                break;
            }
        }
        if (allMatch)
        {
            returnStr[index++] = temp;
            returnStr[index] = '\0';
        }
        else{
            break;
        }
    }

    return returnStr;
}
int main(int argc, char const *argv[])
{
    char *strs[] = {"flower", "flow", "flight"};
    int len = sizeof(strs) / sizeof(strs[0]);
    longestCommonPrefix(strs, len);
    return 0;
}
