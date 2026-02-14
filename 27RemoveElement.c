#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int k = numsSize - 1;
    // printf("k is %d",k);
    // printf("k is %d",k);
    for (int i = 0; i <= k; i++)
    {
        if (nums[k] == val)
        {
            k--;
            i--;
            // printf("k is inside if %d",k);
        }
        else if (nums[i] == val)
        {
            nums[i] = nums[i] + nums[k];
            nums[k] = nums[i] - nums[k];
            nums[i] = nums[i] - nums[k];
            k--;
            // printf("k is inside ielse %d",k);
        }
        // printf("k is %d",k);
    }
    k++;
    return k;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int val = 3;
    int output = removeElement(arr, len, val);
    printf("%d", output);
    return 0;
}
