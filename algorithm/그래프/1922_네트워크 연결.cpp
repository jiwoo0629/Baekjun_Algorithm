#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<int,int, int>> adj; //연결된 두 컴퓨터, 가중치
int n, m, answer = 0; //n : 컴퓨터의 수(~1000), m : 간선의 수(~100000)
bool used[1005][1005]; //이 edge를 사용했는지?
int root[1005];
int depth[1005];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    int x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1) = a;
    tie(x2, y2, z2) = b;
    return z1 < z2;
}

int find(int k) {
    if(root[k] == k) return k;
    return root[k] = find(root[k]);
}

void unionNode(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(depth[a] < depth[b]) {
        int tmp = a;
        a = b; 
        b = tmp;
    }
    root[b] = a;
    if(depth[a] == depth[b]) depth[a]++;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        root[i] = i;
        depth[i] = 1;
    }
    while(m--) { 
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({a, b, c});
    }
    sort(adj.begin(), adj.end(), cmp);
    //n <= 1000이므로, 플로이드-워샬은 불가능 (n^3 <= 10억)
    //크루스칼 알고리즘 => 최소신장트리
    for(int i=0; i<adj.size(); i++) {
        int a, b, val;
        tie(a, b, val) = adj[i];
        if(find(a) == find(b)) continue;
        unionNode(a, b);
        answer += val;
    }
    cout << answer;
    
    return 0;
}
