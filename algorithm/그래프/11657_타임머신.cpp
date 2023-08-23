#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MAX 1000000001
int n, m, a, b, c;
vector<tuple<int, int, int>> v; //간선리스트
long long bmf[501], tmp[501]; //벨만-포드
bool minus_cycle = false;
//최단거리에 포함되는 최대 간선 개수는 n-1개

int main(void) {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}
	fill(bmf + 1, bmf + n + 1, MAX);
	bmf[1] = 0;
	for (int i = 1; i <= n - 1; i++) { //500 * 6000
		for (int j = 0; j < v.size(); j++) {
			int x, y, z;
			tie(x, y, z) = v[j];
			if (bmf[x] == MAX) continue;
			if (bmf[y] > bmf[x] + z) bmf[y] = bmf[x] + z;
		}
	}
	for (int i = 1; i <= n; i++) tmp[i] = bmf[i];
	for (int j = 0; j < v.size(); j++) {
		int x, y, z;
		tie(x, y, z) = v[j];
		if (bmf[x] == MAX) continue;
		if (bmf[y] > bmf[x] + z) bmf[y] = bmf[x] + z;
	}
	for (int i = 1; i <= n; i++) {
		if (tmp[i] != bmf[i])
			minus_cycle = true;
	}
	if (minus_cycle) cout << -1 << "\n";
	else {
		for (int i = 2; i <= n; i++) 
			cout << (bmf[i] == MAX ? -1 : bmf[i]) << "\n";
	}
	

	return 0;
}
