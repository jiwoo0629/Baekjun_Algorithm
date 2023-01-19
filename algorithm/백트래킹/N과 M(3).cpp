#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];

void permutation(int k)
{
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        permutation(k + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    permutation(0);

    return 0;
}
