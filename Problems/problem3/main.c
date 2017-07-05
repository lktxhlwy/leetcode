/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/


#include<stdio.h>
#include<stdlib.h>
int lengthOfLongestSubstring2(char* s) {
	if (*s == '\0')
		return 0;

	int size = sizeof(s);

	char * a = malloc(size);
	for (int i = 0; i < size - 1; i++)
		a[i] = '\0';

	int acur = 0, scur = 0, next = 0;
	int result = 0, tempResult = 0;
	int sameFlag = 0;
	while (s[scur] != '\0')
	{
		a[0] = s[scur];
		sameFlag = 0;
		acur = 0;
		next = scur + 1;
		while (s[next] != '\0')
		{
			for (int i = 0; i <= acur; i++)
			{
				if (a[i] == s[next])
				{
					sameFlag = 1;
					break;
				}
			}

			if (sameFlag == 1)
				break;

			acur++;
			a[acur] = s[next];
			next++;
		}

		if (acur > result)
			result = acur;

		scur++;
		for (int i = 0; i < size - 1; i++)
			a[i] = '\0';
	}

	return result + 1;
}

int lengthOfLongestSubstring(char* s) {
	if (*s == '\0')
		return 0;

	int size = sizeof(s);

	char * a = malloc(size);
	memset(a, 0, size);
	//for (int i = 0; i < size - 1; i++)
	//	a[i] = '\0';

	char * acur = a;
	char * scur = s;
	char * next;
	int result = 0;
	int sameFlag = 0;
	while (*scur != '\0')
	{
		acur = a;
		*a = *scur;

		sameFlag = 0;
		next = scur + 1;
		while (*next != '\0')
		{
			for (char * b = a; b <= acur; b++)
			{
				if (*b == *next)
				{
					sameFlag = 1;
					break;
				}
			}

			if (sameFlag == 1)
				break;

			acur++;
			*acur = *next;
			next++;
		}

		if (acur - a > result)
			result = acur - a;

		scur++;
		memset(a, 0, size);
		//for (int i = 0; i < size - 1; i++)
		//	a[i] = '\0';
	}

	return result + 1;
}
int main(void)
{
	char *s = "abcabc";
	int a = lengthOfLongestSubstring(s);

	return 0;
}