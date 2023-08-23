#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
//방향 그래프임
//거의 최단경로 : 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것
#define MAX 10000001
int n, m, s, d, u, v, p; //n : 정점 (<=500), m : 간선 (<=10000), 시작점, 도착점, u->v 비용 : p
int D[501], shortest_path[501][501]; //다익스트라 배열, start와 연결된 노드들에 대해, 가장 적은 cost가 걸리는 애들
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
queue<int> q;

void dijkstra() {
    fill(D, D+n, -1);
    pq.push({s, 0});
    while(!pq.empty()) {
        int cur = pq.top().first, val = pq.top().second;
        pq.pop();
        if(D[cur] != -1) continue;
        D[cur] = val;
        for(int i=0; i<n; i++) {
            if(shortest_path[cur][i] == -1) continue;
            if(D[i] != -1) continue;
            pq.push({i, shortest_path[cur][i] + val});
        }
    }
}

void findShortest() {
    q.push(d);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i=0; i<n; i++) {
            if(D[cur] == D[i] + shortest_path[i][cur] && shortest_path[i][cur] != -1) {
                shortest_path[i][cur] = -1; // 최단경로이므로 사용불가능처리
                q.push(i);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while(1) {
        cin >> n >> m; 
        if(n == 0 && m == 0) break;
        cin >> s >> d;
        for(int i=0; i<n; i++) fill(shortest_path[i], shortest_path[i] + n, -1);
        while(m--) {
            cin >> u >> v >> p;
            shortest_path[u][v] = p;
        }
        //start로부터 각 위치까지 가는 최단거리가 얼마인지 먼저 구한다.
        dijkstra();
        //end에서부터 역추적하면서 D[end] - list[end][node]가 D[node]와 같은지 확인한다.
        findShortest();
        //최단경로의 간선을 제외하고 남은 간선들을 이용해 다시 최단거리를 구한다.
        dijkstra();
        cout << D[d] << "\n";
    }
    
    return 0;
}
