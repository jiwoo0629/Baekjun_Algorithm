#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1 << 17
#define IMPOSSIBLE 1000000000
int n, w[17][17], dp[17][MAX]; 

//현재 외판원이 cur 마을에 있고, 방문한 마을의 집합이 vis일때
//남은 마을을 모두 방문하고 0번 마을로 돌아갈 때 드는 최소비용
int TSP(int cur, int vis) {
	if (vis == (1 << n) - 1) //모든 마을을 방문한 경우,
		return w[cur][0] ? w[cur][0] : IMPOSSIBLE; //현 위치에서 시작점으로 돌아갈 수 있으면 비용 리턴, 불가능하면 IMPOSSIBLE
	//아직 모든 마을을 방문하지 않은 경우
	int &ret = dp[cur][vis];
	if (ret != -1) return ret; //이미 방문한 마을인 경우, 리턴
	ret = IMPOSSIBLE;
	for (int i = 0; i < n; i++) {
		if (vis & (1 << i)) //i번째 노드를 방문했는지 여부
			continue;
		if (w[cur][i] == 0) //cur에서 i번째 노드를 방문할 방법이 없는 경우 (또는 자기 자신)
			continue;
		ret = min(ret, TSP(i, vis | 1 << i) + w[cur][i]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> w[i][j];
		for (int j = 0; j < MAX; j++) dp[i][j] = -1;
	}
	cout << TSP(0, 1);

	return 0;
}
