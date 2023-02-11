#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    int num[100005] = { 0, };
    for (int i = 1; i <= n; i++) cin >> num[i];
    
    int sum[100005] = { 0, };
    sum[1] = num[1];
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + num[i];

    int i, j;
    while (m--) {
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << "\n";
    }

    
    return 0;
}
