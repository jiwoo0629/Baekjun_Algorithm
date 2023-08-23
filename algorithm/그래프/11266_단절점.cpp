#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e, a, b, cnt = 0;
vector<int> graph[10005];
int order[10005], ans[10005];

int dfs(int k, int parent) { 
	order[k] = ++cnt; //호출된 순서 저장
	int ret = order[k], child_cnt = 0;
	for (int i = 0; i < graph[k].size(); i++) {
		int num = graph[k][i]; //연결된 노드 중
		if (num == parent) continue; //방금 방문했으면 확인 x
		if (order[num] == -1) { // 아직 방문 안했으면 dfs 재귀호출
			int low = dfs(num, k); //나를 거치지 않았을 때 갈 수 있는 가장 작은 order를 리턴
			if (parent != -1 && order[k] <= low) //low가 order보다 큭나 같으면 단절점
				ans[k] = 1;
			ret = min(ret, low);
			child_cnt++;
		}
		else
			ret = min(ret, order[num]);
	}
	if (parent == -1 && child_cnt > 1) ans[k] = 1; //루트이면서 자식이 2개 이상이면 단절점
	return ret;
}

int main(void)
{
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	fill(order + 1, order + v + 1, -1);
	for (int i = 1; i <= v; i++) {
		if (order[i] == -1)
			dfs(i, -1);
	}
	int answer = 0;
	for (int i = 1; i <= v; i++) {
		if (ans[i] == 1)
			answer++;
	}
	cout << answer << "\n";
	for (int i = 1; i <= v; i++) {
		if (ans[i] == 1)
			cout << i << " ";
	}

	return 0;
}
