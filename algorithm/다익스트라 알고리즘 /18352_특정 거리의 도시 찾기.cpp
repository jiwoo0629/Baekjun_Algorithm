#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

//1번 ~ n번 도시, 가중치가 없는 m개의 단방향 도로
//최단거리가 k인 도시들의 번호를 모두 출력
//자기 자신으로 가는 간선은 없음

#define MAX 1000001
int n, m, k, x, a, b; //x: 시작도시, //간선 a(출발) -> b(도착)
int dp[300001];
vector<int> list[300001], ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> x;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        list[a].push_back(b);
    }
    queue<int> q;
    fill(dp+1, dp+n+1, MAX);
    dp[x] = 0;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<list[cur].size(); i++) {
            int nxt = list[cur][i];
            if(dp[nxt] > dp[cur] + 1) {
                dp[nxt] = dp[cur] + 1;
                q.push(nxt);
            }
        }
    }
    for(int i=1; i<=n; i++) 
        if(dp[i] == k) ans.push_back(i);
    if(ans.size() == 0) cout << -1;
    else 
        for(int i=0; i<ans.size(); i++) cout << ans[i] << "\n";

    return 0;
}
