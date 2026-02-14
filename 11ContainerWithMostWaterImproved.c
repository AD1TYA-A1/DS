// This has complexity of O(n)

#include <stdio.h>
// https://leetcode.com/problems/container-with-most-water/?envType=problem-list-v2&envId=array
int maxArea(int *height, int heightSize)
{
    int maxWater = 0;
    int left = 0;
    int right = heightSize - 1;
    while (left < right)
    {
        int width = right - left;
        int minHeight = (height[left] < height[right]) ? height[left] : height[right];
        int area = width * minHeight;

        if (area > maxWater)
        {
            maxWater = area;
        }

        // Move the pointer with the smaller height
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxWater;
}
int main(int argc, char const *argv[])
{
    int height[] = {2, 3, 10, 5, 7, 8, 9}; // Output = 36
    // int height[] = {5,5,5,5}; // Output = 15
    // int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Output = 49
    int len = sizeof(height) / sizeof(height[0]);
    maxArea(height, len);
    return 0;
}
