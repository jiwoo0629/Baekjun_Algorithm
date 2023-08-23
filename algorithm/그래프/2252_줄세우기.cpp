#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m; //n : 학생수 (~32000), m : 비교횟수 (~100000)
vector<int> list[32005]; //n번 학생보다 작은 학생의 리스트
int depth[32005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) { //키를 비교한 결과를 방향 간선으로 표현 (a -> b)
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        depth[b]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(depth[i] == 0)
            q.push(i);    
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i=0; i<list[cur].size(); i++) { //
            int k = list[cur][i];
            depth[k]--;
            if(depth[k] == 0) 
                q.push(k);
        }
    }
    return 0;
}
