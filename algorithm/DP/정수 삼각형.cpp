#include <bits/stdc++.h>
using namespace std;

int sum[502][502];
int tr[502][502];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) cin >> tr[i][j];

    sum[1][1] = tr[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) sum[i][j] = sum[i - 1][j] + tr[i][j];
            else if (j == i) sum[i][j] = sum[i - 1][j - 1] + tr[i][j];
            else sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + tr[i][j];
        }
    }
    cout << *max_element(sum[n] + 1, sum[n] + n + 1);
    
    return 0;
}
