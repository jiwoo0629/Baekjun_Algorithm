#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) isused[i] = 1;
    for (int i = 0; i < m; i++) isused[i] = 0;

    do {
        for (int i = 0; i < n; i++) 
            if (!isused[i]) cout << arr[i] << " ";
        cout << "\n";
    } while (next_permutation(isused, isused + n));

    return 0;
}
