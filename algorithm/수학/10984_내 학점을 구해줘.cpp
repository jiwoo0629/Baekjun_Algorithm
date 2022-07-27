#include <iostream>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	int* toc = new int[t];
	double* gpa = new double[t];
	for (int i = 0; i < t; i++) {
		toc[i] = 0;
		gpa[i] = 0;
	}
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int c;
			double g;
			cin >> c >> g;
			toc[i] += c;
			gpa[i] += (c * g);
		}
		gpa[i] /= toc[i];
	}
	cout.precision(2);
	for (int i = 0; i < t; i++) 
		cout << toc[i] << " " << gpa[i] << endl;

	return 0;
}