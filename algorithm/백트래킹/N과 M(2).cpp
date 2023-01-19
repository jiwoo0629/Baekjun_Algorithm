#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = 1;
    for (int i = 0; i < m; i++) arr[i] = 0;
    do {
        for (int i = 0; i < n; i++)
            if (arr[i] == 0) cout << i + 1 << ' ';
        cout << "\n";
    } while (next_permutation(arr, arr + n));

    return 0;
}
