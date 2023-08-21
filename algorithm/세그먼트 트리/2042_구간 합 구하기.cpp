#include <iostream>
#include <string>
#include <queue>
using namespace std;

//n개의 수로 된 배열, 중간에 빈번히 값이 변경, 중간에 부분합 확인 => 세그먼트 트리 가능성!!
long long input[1000005];
long long tree[4000005];

long long initTree(int position, int start, int end) {
    if(start == end) 
        return tree[position] = input[start];
    int mid = (start + end) / 2;
    return tree[position] = initTree(2 * position, start, mid) + initTree(2 * position + 1, mid+1, end);
}
void update(int position, int start, int end, int idx, long long diff) {
    if(idx < start || idx > end) return;
    tree[position] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update(2 * position, start, mid, idx, diff);
        update(2 * position + 1, mid+1, end, idx, diff);
    }
    return;
}
long long sum(int position, int start, int end, int left, int right) {
    if(right < start || left > end) return 0;
    if(left <= start && right >= end) return tree[position];
    int mid = (start + end) / 2;
    return sum(2 * position, start, mid, left, right) + sum(2 * position + 1, mid + 1, end, left, right);
}

int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> input[i];
    initTree(1, 0, n-1); //root 위치, 시작 위치, 끝 위치
    while(m > 0 || k > 0) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1) {
            long long diff = c - input[b-1];
            input[b-1] = c;
            update(1, 0, n-1, b-1, diff);
            m--;
        }
        else if(a == 2) {
            cout << sum(1, 0, n-1, b-1, c-1) << "\n";
            k--;
        }
    }

    return 0;
}
