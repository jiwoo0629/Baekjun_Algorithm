#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int sum[100005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = arr[i];
    }
    for (int i = 1; i <= n; i++) sum[i] = max(sum[i], sum[i - 1] + arr[i]);
    cout << *max_element(sum + 1, sum + n + 1);
    
    return 0;
}
