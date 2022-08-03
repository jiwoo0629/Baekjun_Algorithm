#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main(void) 
{
	vector<pair<int, int>> v;
	int avg = 0;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		avg += num;
		if (v.empty()) {
			v.push_back(make_pair(num, 1));
			continue;
		}
		int exist = 0;
		for (auto it = v.begin(); it != v.end(); it++) {
			if (it->first == num) {
				it->second++;
				exist = 1;
				break;
			}				
		}
		if (exist == 0) 
			v.push_back(make_pair(num, 1));
	}
	avg /= 10;
	sort(v.begin(), v.end(), desc);

	cout << avg << endl;
	cout << v[0].first << endl;

	return 0;
}