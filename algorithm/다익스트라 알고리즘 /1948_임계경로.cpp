#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, s, e, dp[10001], ans = 0;
vector<pair<int, int>> list[10001]; //-가중치, 목표
vector<tuple<int, int, int>> reverse_list[10001]; //-가중치, 목표, 임계경로에 포함되는지 여부
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //소요시간, 현재도시

int main(void)
{
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        list[x].push_back({-val, y});
        reverse_list[y].push_back({-val, x, false});
    }
    cin >> s >> e;
    //걸리는 시간의 최댓값을 찾도록 다익스트라 수행
    pq.push({0, s}); 
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for(int i=0; i<list[cur].size(); i++) {
            int val = -list[cur][i].first, nxt = list[cur][i].second;
            if(dp[nxt] < dp[cur] + val) {
                dp[nxt] = dp[cur] + val;
                pq.push({-val, nxt});
            }
        }
    }
    cout << dp[e] << "\n";
    //도착점에서부터 역으로 돌아가면서, dp[past] == dp[cur] - val을 만족할 경우, 임계경로에 속하는 경로임
    pq.push({0, e});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for(int i=0; i<reverse_list[cur].size(); i++) {
            int val = -get<0>(reverse_list[cur][i]), past = get<1>(reverse_list[cur][i]), check = get<2>(reverse_list[cur][i]);
            if(dp[past] == dp[cur] - val && !check) {
                ans++;
                get<2>(reverse_list[cur][i]) = true;
                pq.push({-val, past});
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
