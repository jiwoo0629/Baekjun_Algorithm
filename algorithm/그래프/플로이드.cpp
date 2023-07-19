#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    int n, m;
    int graph[101][101];
    cin >> n >> m;
    for(int i=1; i<=n; i++) fill(graph[i]+1, graph[i]+n+1, 10000001);
    for(int i=1; i<=n; i++) graph[i][i] = 0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            if(i == k) continue;
            for(int j=1; j<=n; j++) {
                if(j == k) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);   
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
}
