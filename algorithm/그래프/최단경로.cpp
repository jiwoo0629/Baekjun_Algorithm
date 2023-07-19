#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e, k; //정점, 간선, 시작
int cost[20005]; //시작점으로부터 모든 정점까지의 최단경로 값
#define INF 1e9+10

int main(void) {
    cin >> v >> e;
    cin >> k;
    //시작점 자기자신은 0, 나머지는 무한대
    fill(cost+1, cost+v+1, INF);
    cost[k] = 0;
    vector<pair<int, int>> edge[v+1];
    while(e--) {
        int a, b, w; //출발, 도착, 가중치
        cin >> a >> b >> w;
        edge[a].push_back({b, w}); //시작, {도착, 가중치}
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{거리, 시작점}
    pq.push({0, k});
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if(cost[cur.second] != cur.first) continue; //담겨있는 최단경로 값이 다르면, 잘못된 값이므로 continue
        for(auto it : edge[cur.second]) {
            if(cost[it.first] <= cost[cur.second]+it.second) continue;
            cost[it.first] = cost[cur.second] + it.second;
            pq.push({cost[it.first], it.first});
        }
    }
    for(int i=1; i<=v; i++) {
        if(cost[i] == INF) cout << "INF\n";
        else cout << cost[i] << "\n";
    }
}
