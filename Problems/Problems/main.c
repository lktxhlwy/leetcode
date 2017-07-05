/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target);
int main(void)
{
	int * nums[] = { 2,3,4,5,6 };
	int * answer = twoSum(nums, 5, 6);
	printf("%d,%d\n", answer[0], answer[1]);

	return 0;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target)
{
	int i = 0;
	int j = 0;
	int * result = malloc(2 * sizeof(int));

	for (i = 0; i < numsSize - 1; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}

	return NULL;
}