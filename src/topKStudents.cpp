/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	student **top;
	int in1, in2, i = 0, p, k = 0;
	if (students && len > 0 && K>0)
	{
		if (K > len)
			K = len;
		top =  (struct student **)malloc(K*sizeof(struct student *));
		for (in1 = 0; in1 < K; in1++)
			top[i] = (struct student*)malloc(sizeof(struct student));
			for (in1 = i; in1 < K; in1++)
			  top[in1] = &students[in1];
		if (K == len)
			return top;
		while (i<len){
			      i = i+K;
			for (in1 = i, in2 = 0; in1 < (i+K) && in1 < len; in1++)
			{
				p = top[0]->score; k = 0;
				for (in2 = 1; in2 < K; in2++)
				{
					if (top[in2]->score < p)
					{
						p = top[in2]->score;
						k = in2;
					}
				}
				if (students[in1].score > p)
					top[k] = &students[in1];
			}
		}
		return top;
	}
	return NULL;
}