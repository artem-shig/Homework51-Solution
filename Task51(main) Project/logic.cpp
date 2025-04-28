#include "logic.h"

int get_max_value_all_sorted_row(int** matrix, int n, int m) {

	int maxValueRow = INT_MIN;
	int maxValueMatrix = INT_MIN;

	bool begin_ascending;
	bool current_ascending;

	for (int i = 0; i < n; i++)
	{
		

		if (matrix[i][0] < matrix[i][1]) {
			begin_ascending = true;
			maxValueRow = matrix[i][1];
		}
		else if (matrix[i][0] > matrix[i][1]) {
			begin_ascending = false;
			maxValueRow = matrix[i][0];
		}
		else {
			continue;
		}
		
		for (int j = 1; j < m - 1; j++)
		{
	
			if (maxValueRow < *(matrix + i)[j + 1]) {
				current_ascending = true;
				maxValueRow = matrix[i][j + 1];
			}
			else if (maxValueRow > matrix[i][j + 1]) {
				current_ascending = false;
				maxValueRow = matrix[i][j];
			}
			else {
				current_ascending = !begin_ascending;
			}
			if (current_ascending != begin_ascending) {
				maxValueRow = INT_MIN;
				break;
			}
			
		}

		if (maxValueRow != INT_MIN && maxValueMatrix < maxValueRow) {
			maxValueMatrix = maxValueRow;
		}

	}

	return maxValueMatrix;
}

int get_sum_between_first_and_second_positive_elements_all_row(int** matrix, int n, int m) {
	int sumMatrix = 0;
	int sumRow;
	int count;

	for (int i = 0; i < n; i++)
	{
		count = 0;
		sumRow = 0;
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] > 0) {
				count++;
				if (count == 2) {
					break;
				}
			}
			else if (count == 1) {
				sumRow += matrix[i][j];
			}
		}
		if (count == 2) {
			sumMatrix += sumRow;
		}
	}
	return sumMatrix;
}