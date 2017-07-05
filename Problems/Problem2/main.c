/*
You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output : 7 -> 0 -> 8

* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *result;
	struct ListNode *nextResult;
	int addc = 0;
	int val1, val2;
	result = NULL;
	struct ListNode *startNode = result;

	while ((l1 != NULL) || (l2 != NULL))
	{
		nextResult = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (l1 == NULL)
			val1 = 0;
		else
			val1 = l1->val;
		if (l2 == NULL)
			val2 = 0;
		else
			val2 = l2->val;
		nextResult->val = (val1 + val2 + addc) % 10;
		addc = (val1 + val2 + addc) / 10;
		nextResult->next = NULL;

		if (result == NULL)
		{
			result = nextResult;
			startNode = result;
		}
		else
		{
			result->next = nextResult;
			result = nextResult;
		}
		if (l1 != NULL)
			l1 = l1->next;
		if (l2 != NULL)
			l2 = l2->next;
	}
	if (addc != 0)
	{
		nextResult = (struct ListNode *)malloc(sizeof(struct ListNode));
		nextResult->val = addc;
		nextResult->next = NULL;

		if (result != NULL)
			result->next = nextResult;
		result = nextResult;
	}

	return startNode;
}

int main()
{
	struct ListNode *l1, *nextl1;
	struct ListNode *l2, *nextl2;

	l1 = NULL;
	l2 = NULL;

	struct ListNode *l1start = l1;
	struct ListNode *l2start = l2;

	for (int i = 0; i < 1; i++)
	{
		nextl1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		nextl1->val = i;
		nextl1->next = NULL;
		if (l1 == NULL)
		{
			l1 = nextl1;
			l1start = l1;
		}
		else
		{
			l1->next = nextl1;
			l1 = nextl1;
		}
	}

	for (int i = 6; i < 9; i++)
	{
		nextl2 = (struct ListNode *)malloc(sizeof(struct ListNode));
		nextl2->val = i;
		nextl2->next = NULL;
		if (l2 == NULL)
		{
			l2 = nextl2;
			l2start = l2;
		}
		else
		{
			l2->next = nextl2;
			l2 = nextl2;
		}
	}

	struct ListNode* result = addTwoNumbers(l1start, l2start);

	return 0;
}