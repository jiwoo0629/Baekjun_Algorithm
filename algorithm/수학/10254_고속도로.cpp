#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<pair<int, int>> v;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		pair<int, int> n1, n2;
		double max = 0;
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				double dis = sqrt(pow((v[j].first - v[k].first), 2) + pow((v[j].second - v[k].second), 2));
				if (max < dis) {
					max = dis; n1 = v[j]; n2 = v[k];
				}					
			}
		}
		cout << n1.first << " " << n1.second << " " << n2.first << " " << n2.second << endl;
	}

	return 0;
}