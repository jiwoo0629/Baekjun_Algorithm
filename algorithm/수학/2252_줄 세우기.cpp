#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int highnum = 0;
	vector<int> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (highnum < a) highnum = a;
		if (highnum < b) highnum = b;
		auto n1 = find(v.begin(), v.end(), a);
		if (n1 == v.end())
			v.push_back(a);
		auto n2 = find(v.begin(), v.end(), b);
		if (n2 == v.end())
			v.push_back(b);
		auto at1 = find(v.begin(), v.end(), a) - v.begin();
		auto at2 = find(v.begin(), v.end(), b) - v.begin();
		if (at1 > at2) {
			int temp = v[at1];
			v[at1] = v[at2];
			v[at2] = temp;
		}
	}
	if (highnum < n) {
		for (int i = highnum + 1; i <= n; i++)
			v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}