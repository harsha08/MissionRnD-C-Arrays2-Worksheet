/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int toNum(char *date, int start, int end)
{
	int num = 0;
	for (; start <= end; start++)
	{
		num = (num * 10) + date[start] - '0';
	}
	return num;
}

int isOlder(char *dob1, char *dob2) {
	
	int day1 = 0, month1 = 0, year1 = 0, day2 = 0, month2 = 0, year2 = 0;
	day1 = toNum(dob1, 0, 1);
	month1 = toNum(dob1, 3, 4);
	year1 = toNum(dob1, 6, 9);
	day2 = toNum(dob2, 0, 1);
	month2 = toNum(dob2, 3, 4);
	year2 = toNum(dob2, 6, 9);
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

}



int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (isOlder(Arr[i].date, date) == 2)
		{
			return len - i;
		}
	}
	return 0;

}
