#include <iostream>
#include <vector>
using namespace std;

int gcd(int, int);

int main(void)
{
	int r, g;
	cin >> r >> g;

	int n = gcd(r, g);
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if ((r % i == 0) && (g % i == 0))
			v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " " << r / v[i] << " " << g / v[i] << endl;

	return 0;
}

int gcd(int a, int b)
{
	int num;
	if (a > b)
		num = a % b;
	else
		num = b % a;
	while (num != 0) {
		a = b;
		b = num;
		num = a % b;
	}
	return b;
}