/*  BFS를 수행해 각 정점의 깊이와 부모 정점을 저장한 후, 하나씩 거슬러 올라가며 최소 공통 조상을 찾는 방법
    시간복잡도 : O(n * m) = 10만 * 10만 = 100억 => 시간초과 
    빠르게 구하는 방법 => DP를 이용
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, a, b, answer;
vector<int> tree [100005];
bool vis[100005];
pair<int, int> node[100005]; //부모 정점, 깊이
int parent[20][100005]; //2^k번째 조상노드 일 때의 값 num => parent[k][v] = num

void func(int start, int end, int a, int b) { //범위를 좁혀가며 처음으로 값이 같아지는 depth를 찾음
    int k = 0, diff = end - start;
    if(diff == 0) return;
    while(pow(2, k+1) <= diff) k++; //k = 1
    if(parent[k][a] == parent[k][b]) { //같을 경우, 아래에서 찾아야 함
        answer = parent[k][a];
        func(end - pow(2, k) + 1, end, a, b);
    }
    else  //다를 경우, 위에서 찾아야 함
        func(start, end - pow(2, k), parent[k][a], parent[k][b]);
} 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    } 
    queue<pair<int, int>> q;
    q.push({1, 0}); //조상노드 번호 : 1, 깊이 : 0
    vis[1] = true;
    node[1] = {1, 0};
    while(!q.empty()) { //각 노드의 부모 노드와 깊이를 확인
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<tree[cur.first].size(); i++) {
            int idx = tree[cur.first][i];
            if(vis[idx]) continue;
            vis[idx] = true;
            q.push({idx, cur.second + 1});
            node[idx] = {cur.first, cur.second + 1};
        }
    }
    for(int i=1; i<=n; i++) parent[0][i] = node[i].first;
    int num = 1;
    while(pow(2, num) < n) {
        for(int i=1; i<=n; i++) 
            parent[num][i] = parent[num-1][parent[num-1][i]]; 
        num++;
    }
    cin >> m;
    while(m--) {
        cin >> a >> b;
        int node_a = a, node_b = b;
        int dep_a = node[a].second, dep_b = node[b].second;
        int diff = dep_b - dep_a, node = node_b, dep = dep_a; //깊이 차이, 확인해야 하는 node
        if(dep_a > dep_b) { //a의 깊이가 더 깊을 경우, 
            diff = dep_a - dep_b;
            node = node_a;
            dep = dep_b;
        }
        while(diff != 0) { 
            int k = 0;
            while(pow(2, k+1) <= diff) k++;
            node = parent[k][node];
            diff -= pow(2, k);
        }
        if(dep_a > dep_b) node_a = node;
        else node_b = node;
        if(node_a == node_b) {
            cout << node_a << "\n";
            continue;
        }
        //dep를 같게 만드는데까지 성공
        func(0, dep, node_a, node_b); //범위를 좁혀가며 처음으로 값이 같아지는 depth를 찾음
        cout << answer << "\n";
    }

    return 0;
}
