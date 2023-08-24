#include <iostream>
using namespace std;

int n, num;
int m_a[1000005]; //식별번호, 순서
long long tree[2000005];

void update(int pos, int start, int end, int idx) {
    if(start > idx || end < idx) return;
    if(start == end) tree[pos]++;
    else {
        int mid = (start + end) / 2;
        update(2 * pos, start, mid, idx);
        update(2 * pos + 1, mid + 1, end, idx);
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }
}

long long getSum(int pos, int start, int end, int left, int right) {
    if(start > right || end < left) return 0;
    if(left <= start && right >= end) return tree[pos];
    int mid = (start + end) / 2;
    return getSum(2 * pos, start, mid, left, right) + getSum(2 * pos + 1, mid + 1, end, left, right);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) { //50만번
        cin >> num;
        m_a[num] = i;
    }
    long long answer = 0;
    for(int i=1; i<=n; i++) { //50만번 * 최대 200번
        cin >> num;
        int idx = m_a[num];
        answer += getSum(1, 1, n, idx+1, n); 
        update(1, 1, n, idx);
    }
    cout << answer;

    return 0;
}
