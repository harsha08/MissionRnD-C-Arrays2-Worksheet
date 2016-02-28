/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int toNum1(char *date, int start, int end)
{
	int num = 0;
	for (; start <= end; start++)
	{
		num = (num * 10) + date[start] - '0';
	}
	return num;
}

int isOlder1(char *dob1, char *dob2) {

	int day1 = 0, month1 = 0, year1 = 0, day2 = 0, month2 = 0, year2 = 0;
	day1 = toNum1(dob1, 0, 1);
	month1 = toNum1(dob1, 3, 4);
	year1 = toNum1(dob1, 6, 9);
	day2 = toNum1(dob2, 0, 1);
	month2 = toNum1(dob2, 3, 4);
	year2 = toNum1(dob2, 6, 9);
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


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
	{
		return NULL;
	}
	struct transaction *result= new struct transaction[ALen+BLen]; 
	while (i < ALen && j < BLen)
	{
		if (isOlder1(A[i].date, B[j].date) == 1)
		{
			result[k++] = A[i];
			i++;
		}
		else if (isOlder1(A[i].date, B[j].date) == 2)
		{
			result[k++] = B[j];
			j++;
		}
		else
		{
			result[k++] = A[i];
			result[k++] = B[j];
			i++;
			j++;
		}
	}
	if (i == ALen)
	{
		while (j<BLen)
		result[k++] = B[j++];
	}
	else if (j == BLen)
	{
		while (i<ALen)
			result[k++] =A[i++];
	}
	return result;
}