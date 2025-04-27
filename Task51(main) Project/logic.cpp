#include "logic.h"

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