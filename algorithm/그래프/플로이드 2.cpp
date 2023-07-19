#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    int n, m;
    int graph[101][101];
    int nxt[101][101];
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        fill(graph[i]+1, graph[i]+n+1, 10000001);
        fill(nxt[i]+1, nxt[i]+n+1, 0);
    }
    for(int i=1; i<=n; i++) graph[i][i] = 0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
        nxt[a][b] = b;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    nxt[i][j] = nxt[i][k];
                } 
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) 
            if(graph[i][j] == 10000001) graph[i][j] = 0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cout << graph[i][j] << ' ';
        cout << "\n";
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(graph[i][j] == 0) {
                cout << 0 << "\n";
                continue;
            }
            vector<int> v;
            v.push_back(i);
            while(v.back() != j) {
                v.push_back(nxt[v.back()][j]);
            }
            cout << v.size() << ' ';
            for(int i=0; i<v.size(); i++) cout << v[i] << ' ';
            cout << "\n";
        }
    }
}
