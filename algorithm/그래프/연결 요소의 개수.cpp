#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool vis[1002];
vector<vector<int>> graph(1002);
int cnt = 0;

int main(void) {
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        queue<int> q;
        if(vis[i]) continue;
        cnt++;
        vis[i] = true;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j=0; j<graph[cur].size(); j++) {
                if(vis[graph[cur][j]]) continue;
                vis[graph[cur][j]] = true;
                q.push(graph[cur][j]);
            }
        }
    }
    cout << cnt;

    return 0;
}
