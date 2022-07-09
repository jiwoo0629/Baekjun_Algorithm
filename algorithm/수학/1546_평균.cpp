#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;

	double* score = new double[num];
	for (int i = 0; i < num; i++)
		cin >> score[i];
	
	double max = 0;
	for (int i = 0; i < num; i++) {
		if (max < score[i])
			max = score[i];
	}

	double avg = 0;
	for (int i = 0; i < num; i++) {
		score[i] = score[i] / max * 100;
		avg += score[i];
	}
	avg /= num;

	cout << avg << endl;

	return 0;
}