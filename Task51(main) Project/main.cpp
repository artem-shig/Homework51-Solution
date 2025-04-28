#include "logic.h"

int main() {
	cout << "Task51(main).\n";
	int n, m;

	do {
		cout << "Enter size of matrix(NxM): ";
		cin >> n >> m;
	} while (n <= 1 || m <= 1);

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	init(matrix, n, m, -20, 20);
	cout << "Matrix:\n" << convert(matrix, n, m) << endl;

	if (n <= 1 || m <= 1 || matrix == nullptr) {
		return -1;
	}

	int maxValue = get_max_value_all_sorted_row(matrix, n, m);
	string msg = (maxValue == INT_MIN ? "The matrix does not satisfy the condition"
		: "The maximum value of the matrix is " + to_string(maxValue));

	cout << msg;

	//cout << "Sum of the matrix elements between the first and second positive elements of each row is "
	//	<< get_sum_between_first_and_second_positive_elements_all_row(matrix, n, m) << endl;


	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}