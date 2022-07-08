#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int sum = 0, count = 0;
	while (sum < n) {
		int i = 1;
		while (pow(i+1, 2) + sum <= n) {
			i++;
		}
		sum += pow(i, 2);
		count++;
		if (sum == n)
			break;
	}
	cout << count << endl;

	return 0;
}
