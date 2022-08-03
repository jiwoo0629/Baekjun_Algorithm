#include <iostream>
using namespace std;

int main(void)
{
	int arr[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}

	int max = -1;
	int row, col;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
				row = i + 1;
				col = j + 1;
			}
		}
	}

	cout << max << endl;
	cout << row << " " << col << endl;

	return 0;
}
