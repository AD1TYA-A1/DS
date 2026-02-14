// This has complexity O(n**2) beacuse of use of two loops
// 57 / 65 testcases passed In LeetCode
// The improved version is FileName ---> "11ContainerWithMostWaterImproved"
#include <stdio.h>
// https://leetcode.com/problems/container-with-most-water/?envType=problem-list-v2&envId=array
int maxArea(int *height, int heightSize)
{

    int maxSpace = 0;
    for (int j = heightSize - 1; j >= 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            int tempSpace = 0;
            if (height[i] <= height[j])
            {
                tempSpace = height[i] * (j - i);
            }
            else
            {
                tempSpace = height[j] * (j - i);
            }
            if (tempSpace > maxSpace)
            {
                maxSpace = tempSpace;
            }
        }
    }
    printf("MAX SPACE IS : %d ", maxSpace);
    return maxSpace;
}
int main(int argc, char const *argv[])
{
    // int height[] = {2, 3, 10, 5, 7, 8, 9}; // Output = 36
    // int height[] = {5,5,5,5}; // Output = 15
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Output = 49
    int len = sizeof(height) / sizeof(height[0]);
    maxArea(height, len);
    return 0;
}
