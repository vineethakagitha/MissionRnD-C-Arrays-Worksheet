/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	int in1, in2, p, k=0;
	student temp;
	if (students && len > 0){
		for (in1 = 0; in1 < (len - 1); in1++)
		{
			p = students[in1].score; k = in1;
			for (in2 = in1 + 1; in2 < len; in2++)
			{
				if ((students[in2].score)>p)
				{
					p = students[in2].score;
					k = in2;
				}
			}
			temp = students[in1];
			students[in1] = students[k];
			students[k] = temp;
		}
	}
	return NULL;
}