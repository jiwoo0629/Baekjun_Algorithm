#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int f, s, g, u, d;
int startlink[1000005];
bool vis[1000005];
int dx[2];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    if(s == g) {
        cout << 0;
        return 0;
    }
    dx[0] = u; dx[1] = -d;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<2; i++) {
            int nx = cur + dx[i];
            if(nx < 1 || nx > f) continue;
            if(vis[nx]) continue;
            q.push(nx);
            vis[nx] = true;
            if(startlink[nx] == 0) startlink[nx] = startlink[cur] + 1;
            else startlink[nx] = min(startlink[cur] + 1, startlink[nx]);
        }
    }
    if(startlink[g] == 0) cout << "use the stairs";
    else cout << startlink[g];

    return 0;
}
