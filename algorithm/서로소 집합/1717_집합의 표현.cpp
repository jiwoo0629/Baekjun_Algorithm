#include <iostream>
#include <algorithm>
using namespace std;

int n, m, op, a, b;
int past[1000005], depth[1000005];

int find(int k) { //집합의 시작을 찾는 함수
    if(past[k] == k) return k;
    return past[k] = find(past[k]);
}

void union_func(int a, int b) { //합집합 연산 함수
    int v1 = find(a);
    int v2 = find(b);
    if(v1 == v2) return;
    if(depth[v1] < depth[v2]) { 
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
    past[v2] = v1; //깊이가 더 깊은 녀석의 값을 우선으로 취급
    if(depth[v1] == depth[v2]) depth[v1]++;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; //{0}, ... , {n} 노드만 있는 상태
    for(int i=0; i<=n; i++) {
        past[i] = i;
        depth[i] = 1;
    }
    while(m--) { 
        cin >> op >> a >> b;
        if(op == 0) { //합집합 연산
            union_func(a, b);
        } 
        else if(op == 1) { //두 원소가 같은 집합에 포함되어 있는지 확인
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
