#include <stdio.h>
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