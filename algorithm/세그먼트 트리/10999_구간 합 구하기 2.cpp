#include <iostream>
using namespace std;

int n, m, k, a, b, c;
long long d, arr[1000001], tree[4000001], lazy[4000001];

long long init(int pos, int start, int end) {
    if(start == end) return tree[pos] = arr[start];
    int mid = (start + end) / 2;
    return tree[pos] = init(2*pos, start, mid) + init(2*pos+1, mid+1, end);
}

//느리게 갱신되는 세그먼트 트리를 이용해 수행시간 감소
void update_lazy(int pos, int start, int end) {
    if(lazy[pos] != 0) {
        tree[pos] += (end - start + 1) * lazy[pos];
        if(start != end) {
            lazy[2*pos] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
}

void update(int pos, int start, int end, int left, int right, long long val) {
    update_lazy(pos, start, end);
    if(left > end || right < start) return;
    if(left <= start && right >= end) {
        tree[pos] += (end - start + 1) * val;
        if(start != end) {
            lazy[2*pos] += val;
            lazy[2*pos+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(2*pos, start, mid, left, right, val);
    update(2*pos+1, mid+1, end, left, right, val);
    tree[pos] = tree[2*pos] + tree[2*pos+1];
}

long long sum(int pos, int start, int end, int left, int right) {
    update_lazy(pos, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[pos];
    int mid = (start + end) / 2;
    return sum(2*pos, start, mid, left, right) + sum(2*pos+1, mid+1, end, left, right);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);
    for(int i=0; i<m+k; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        }
        else if(a == 2) {
            cin >> b >> c;
            cout << sum(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}
