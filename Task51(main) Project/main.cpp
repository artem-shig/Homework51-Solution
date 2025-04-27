#include "logic.h"

int main() {
	cout << "Task51(main): Task02.\n";
	int n, m;
	cout << "Enter size of matrix(NxM): ";
	cin >> n >> m;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	init(matrix, n, m, -20, 20);
	cout << "Matrix:\n" << convert(matrix, n, m) << endl;

	cout << "Sum of the matrix elements between the first and second positive elements of each row is "
		<< get_sum_between_first_and_second_positive_elements_all_row(matrix, n, m) << endl;


	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}