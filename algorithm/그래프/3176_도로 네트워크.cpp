#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define MAX 1000001
int n, k; //n : 도시 개수, k : 입력 횟수
int a, b, x; //두 노드, 가중치
vector<pair<int, int>> v[100001]; //v[a] = [{b, x} ... ] : a에서 b로 가는 가중치 x
int depth[100001]; //이 노드의 깊이
int past[18][100001], min_D[18][100001], max_D[18][100001]; //이전노드, 노드별 최소 거리

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<=n; i++) {
        depth[i] = -1;
        for(int j=0; j<=17; j++) {
            past[j][i] = 0;
            min_D[j][i] = MAX;
            max_D[j][i] = -1;
        }
    }
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> x;
        v[a].push_back({b, x});
        v[b].push_back({a, x});
    }
    stack<int> s;
    depth[1] = 0;
    s.push(1);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        for(int i=0; i<v[cur].size(); i++) {
            int num = v[cur][i].first, val = v[cur][i].second;
            if(depth[num] == -1) {
                depth[num] = depth[cur] + 1;
                past[0][num] = cur;
                min_D[0][num] = max_D[0][num] = val;
                s.push(num);
            }
        }
    }
    for(int i=1; i<=17; i++) {
        for(int j=1; j<=n; j++) {
            past[i][j] = past[i-1][past[i-1][j]];
            min_D[i][j] = min(min_D[i-1][j], min_D[i-1][past[i-1][j]]);
            max_D[i][j] = max(max_D[i-1][j], max_D[i-1][past[i-1][j]]);
        }
    }
    cin >> k;
    while(k--) {
        cin >> a >> b;
        int minL = MAX, maxL = -1;
        if(depth[a] > depth[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        for(int i=17; i>=0; i--) {
            if(depth[a] <= depth[past[i][b]]) {
                minL = min(minL, min_D[i][b]);
                maxL = max(maxL, max_D[i][b]);
                b = past[i][b];
            }
        }
        for(int i=17; i>=0 && a!=b; i--) {
            if(past[i][a] != past[i][b]) {
                minL = min({minL, min_D[i][a], min_D[i][b]});
                maxL = max({maxL, max_D[i][a], max_D[i][b]});
                a = past[i][a];
                b = past[i][b];
            }
        }
        if(a != b) {
            minL = min({minL, min_D[0][a], min_D[0][b]});
            maxL = max({maxL, max_D[0][a], max_D[0][b]});
        }
        cout << minL << " " << maxL << "\n";
    }

    return 0;
}
