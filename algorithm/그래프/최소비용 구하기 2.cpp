#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 100000005
int cost[1002];
int past[1002];

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge[n+1];
    fill(cost+1, cost+n+1, INF);
    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a].push_back({b, w}); //a -> b 간선의 가중치 : w
    } 
    int start, end;
    cin >> start >> end;
    cost[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); //가중치, 시작점
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(cost[cur.second] != cur.first) continue;
        for(auto nxt : edge[cur.second]) {
            if(cost[nxt.first] <= cost[cur.second] + nxt.second) continue;
            cost[nxt.first] = cost[cur.second] + nxt.second;
            pq.push({cost[nxt.first], nxt.first});
            past[nxt.first] = cur.second; 
        }
    }
    cout << cost[end] << "\n";
    vector<int> v;
    int cur = end;
    do {
        v.push_back(cur);
        cur = past[cur];
    } while(cur != start);
    v.push_back(cur);
    cout << v.size() << "\n";
    for(int i=v.size()-1; i>=0; i--) cout << v[i] << ' ';
}
