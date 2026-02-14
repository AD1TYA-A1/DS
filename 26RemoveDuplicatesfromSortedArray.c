#include <stdio.h>
int removeDuplicates(int *nums, int numsSize)
{
    int arr[numsSize];
    arr[0] = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (arr[count] == nums[i])
        {
            continue;
        }
        count++;
        arr[count] = nums[i];
    }
    // printf("COUNT IS %d \n",count);
    for (int i = 0; i <= count; i++)
    {
        nums[i] = arr[i];
    }
    for (int i = 0; i <= count; i++)
    {
        printf("num[] %d",nums[i]);
    }
    
    return count+1;
}
int main(int argc, char const *argv[])
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int len = sizeof(nums) / sizeof(nums[0]);
    printf("%d \n", len);
    removeDuplicates(nums, len);
    return 0;
}
