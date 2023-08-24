#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1e15 + 1
int n, d;
long long arr[100001], dp[100001], tree[400001];

void update(int pos, int start, int end, int idx, long long val) {
    if(start == end) {
        tree[pos] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) update(2*pos, start, mid, idx, val);
    else update(2*pos+1, mid+1, end, idx, val);
    tree[pos] = max(tree[2*pos], tree[2*pos+1]);
}

long long find(int pos, int start, int end, int left, int right) {
    if(left > end || right < start) return -MAX;
    if(left <= start && right >= end) return tree[pos];
    int mid = (start + end) / 2;
    return max(find(2*pos, start, mid, left, right), find(2*pos+1, mid+1, end, left, right));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    for(int i=0; i<n; i++) {
        cin >> arr[i];    
        dp[i] = arr[i];
    }
    for(int i=0; i<n; i++) {
        dp[i] = max(dp[i], arr[i] + find(1, 0, n-1, max(0, i-d), i-1));
        update(1, 0, n-1, i, dp[i]);
    }
    cout << *max_element(dp, dp+n);

    return 0;
}
