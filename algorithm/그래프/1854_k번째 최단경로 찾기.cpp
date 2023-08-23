#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
int n, m, k, a, b, c; //n : 도시 (~1000), m : 간선 (~200000), k : k번째 최단경로 구하기
int vis[1005], dist[1005];
vector<pair<int, int>> v[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; //도시, cost
//시작 도시는 1

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c}); 
    }
    vis[1] = 1;
    for(int i=0; i<v[1].size(); i++) 
        pq.push(v[1][i]);
    int cnt = n; //n개의 노드에 대해서, 모두 k번째 최단거리를 찾았는지 여부 확인
    while(cnt && !pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int city = cur.first, cost = cur.second;
        if(vis[city] >= k) continue;
        if(++vis[city] == k) cnt--;
        dist[city] = cost;
        for(int i=0; i<v[city].size(); i++) {
            if(vis[v[city][i].first] < k)
                pq.push({v[city][i].first, v[city][i].second + cost});
        }
    }
    for(int i=1; i<=n; i++) {
        if(vis[i] == k) cout << dist[i] << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}
