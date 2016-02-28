/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int toNum2(char *date, int start, int end)
{
	int num = 0;
	for (; start <= end; start++)
	{
		num = (num * 10) + date[start] - '0';
	}
	return num;
}

int isOlder2(char *dob1, char *dob2) {

	int day1 = 0, month1 = 0, year1 = 0, day2 = 0, month2 = 0, year2 = 0;
	day1 = toNum2(dob1, 0, 1);
	month1 = toNum2(dob1, 3, 4);
	year1 = toNum2(dob1, 6, 9);
	day2 = toNum2(dob2, 0, 1);
	month2 = toNum2(dob2, 3, 4);
	year2 = toNum2(dob2, 6, 9);
	if (year1 > year2)
	{
		return 2;
	}
	else if (year1 < year2)
	{
		return 1;
	}
	else if (year1 == year2)
	{
		if (month1 > month2)
		{
			return 2;
		}
		else if (month1 < month2)
		{
			return 1;
		}
		else if (month1 == month2)
		{
			if (day1 > day2)
			{
				return 2;
			}
			else if (day1 < day2)
			{
				return 1;
			}
			else if (day1 == day2)
			{
				return 0;
			}
		}
	}
	return -1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
	{
		return NULL;
	}
	struct transaction *result = new struct transaction[ALen + BLen];
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (isOlder2(A[i].date, B[j].date) == 0)
			{
				result[k++] = A[i];
			}
		}
	}
	if (k>0)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}