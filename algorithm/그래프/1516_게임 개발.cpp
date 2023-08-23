#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n; //건물의 종류(~500)
vector<int> v[501]; //이 건물을 짓기 전에 먼저 지어야 하는 건물
int t[501]; //건물을 짓는데 걸리는 시간
int ans[501]; //각 건물 별 완성되기까지 걸리는 최소 시간
int depth[501];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        t[i] = num;
        ans[i] = num;
        while(1) {
            cin >> num;
            if(num == -1) break;
            v[num].push_back(i);
            depth[i]++;
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(depth[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<v[cur].size(); i++) {
            int num = v[cur][i];
            depth[num]--;
            if(depth[num] == 0)
                q.push(num);
            ans[num] = max(ans[num], ans[cur] + t[num]);
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << "\n";
    
    return 0;
}
