/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int in1, in2,p,rsize;
	if (Arr && len > 0){
		for (in1 = 0; in1 < (len - 1); in1++)
		{
			p = Arr[in1];
			for (in2 = in1 + 1; in2 < len; in2++)
			{
				if (p == Arr[in2])
				{
					for (rsize = in2; rsize < (len - 1); rsize++)
					{
						Arr[rsize] = Arr[rsize + 1];
					}
					len--;
					in2--;
				}
			}
		}
	}
	return NULL;
}