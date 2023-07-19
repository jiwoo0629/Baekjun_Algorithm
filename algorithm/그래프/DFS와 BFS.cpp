#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, v; //정점, 간선, 시작번호
bool vis[1002];
vector<vector<int>> graph(1002);

void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : graph[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for(auto nxt : graph[cur]) {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(void) {
    cin >> n >> m >> v;
    while(m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i<=n; i++) sort(graph[i].begin(), graph[i].end());
    dfs(v);
    cout << "\n";
    fill(vis+1, vis+n+1, false);
    bfs();
}
