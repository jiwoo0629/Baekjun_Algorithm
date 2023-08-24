#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, n, k, x, y, w;
int d[100001], depth[100001], dp[100001]; //w를 짓는 최댓값
vector<int> list[100001]; //시작 -> 도착
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //현재누적시간, 현재건물, depth

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> d[i];
        for(int i=0; i<k; i++) {
            cin >> x >> y;
            list[x].push_back(y);
            depth[y]++;
        }  
        cin >> w;
        for(int i=1; i<=n; i++) {
            if(depth[i] == 0) {
                pq.push({-d[i], i});
                dp[i] = d[i];
            }
        }
        while(!pq.empty()) {
            int cur = pq.top().second;
            pq.pop();
            for(int i=0; i<list[cur].size(); i++) {
                int nxt = list[cur][i];
                dp[nxt] = max(dp[nxt], dp[cur] + d[nxt]);
                depth[nxt]--;
                if(depth[nxt] == 0) {
                    pq.push({-dp[nxt], nxt});
                }
            }
        }
        cout << dp[w] << "\n";
        for(int i=1; i<=n; i++) list[i].clear();
        fill(d+1, d+n+1, 0);
        fill(dp+1, dp+n+1, 0);
        fill(depth+1, depth+n+1, 0);
    }

    return 0;
}

