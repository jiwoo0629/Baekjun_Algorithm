#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1000000001 //10만(n) * 1만(굴 길이) => 10억
int n, a, b, c, ant[100001], parent[100001], dp[100001], ans[100001]; //dp[k] : k번방에서 1번방까지의 거리
vector<pair<int, int>> list[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(dp+1, dp+n+1, MAX);
    for(int i=1; i<=n; i++) cin >> ant[i];
    for(int i=1; i<n; i++) {
        cin >> a >> b >> c;
        list[a].push_back({-c, b});
        list[b].push_back({-c, a});
    }
    //다익스트라 알고리즘을 통해 (1 -> 각방 / 각방 -> 1) 최단거리 구함
    dp[1] = 0; parent[1] = 1;
    pq.push({0, 1});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for(int i=0; i<list[cur].size(); i++) {
            int val = -list[cur][i].first, nxt = list[cur][i].second;
            if(dp[nxt] > dp[cur] + val) {
                parent[nxt] = cur;
                dp[nxt] = dp[cur] + val;
                pq.push({-val, nxt});
            }
        }
    }
    ans[1] = 1;
    for(int i=2; i<=n; i++) {
        int cur = i;
        while(cur != 1) {
            if(dp[i] - dp[parent[cur]] > ant[i]) break;
            cur = parent[cur];
        }
        ans[i] = cur;
    }
    for(int i=1; i<=n; i++) cout << ans[i] << "\n";

    return 0;
}

