#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int* edge = new int[n + 1]; //node별 edge 개수
	for (int i = 0; i <= n; i++)
		edge[i] = 0;
	vector<int>* Nodes = new vector<int>[n+1]; //모든 node의 edge 정보
	
	for (int i = 0; i < m; i++) {
		int count;
		cin >> count;
		int prev;
		for (int j = 0; j < count; j++) {
			int n;
			cin >> n;
			if (j != 0) {
				Nodes[prev].push_back(n);
				edge[n]++;
			}
			prev = n;
		}
	}

	int* sortedNode = new int[n + 1]; //위상정렬이 완료된 node 순서
	queue<int> q;
	for (int i = 1; i <= n; i++) { //edge 개수가 0인 node를 queue에 모두 추가
		if (edge[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		//모든 노드를 방문하기 전에 queue가 empty면 cycle이 존재하기 때문에 순서 정하기 불가능
		if (q.empty()) {
			cout << "0";
			return 0;
		}

		int x = q.front();
		q.pop();
		sortedNode[i] = x;

		for (int j = 0; j < Nodes[x].size(); j++) {
			int y = Nodes[x][j];
			edge[y]--;
			if (edge[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << sortedNode[i] << endl;
		Nodes[i].clear();
	}

	return 0;
}
