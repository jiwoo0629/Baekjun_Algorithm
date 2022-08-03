#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*dfs 백트래킹
vector<pair<int, int>> result;
vector<pair<int, int>> v;
bool* visit;
void dfs(int idx) {
	if (result.size() == 2) {
		for (pair<int, int> i : result) {
			
		}
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			result.push_back(v[i]);
			dfs(i + 1);
			result.pop_back();
			visit[i] = false;
		}
	}
}*/

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
