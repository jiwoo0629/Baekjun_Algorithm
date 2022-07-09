#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	int* doll = new int[n];
	for (int i = 0; i < n; i++)
		cin >> doll[i];

	double minvar = 1000000.0;
	for (; k <= n; k++) {
		for (int i = 0; i < n - k + 1; i++) {
			double m = 0;
			for (int j = i; j < i + k; j++)
				m += doll[j];
			m /= (double)k;
			double variant = 0;
			for (int j = i; j < i + k; j++)
				variant += pow((double)(doll[j] - m), 2.0);
			variant /= (double)k;

			if (minvar > sqrt(variant))
				minvar = sqrt(variant);
		}
	}	
	cout << fixed << setprecision(10);
	cout << minvar << endl;

	return 0;
}