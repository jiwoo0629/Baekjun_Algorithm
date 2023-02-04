#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[11];
        arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i == 2) arr[i] = arr[i - 1] + 1;
            else if (i == 3) arr[i] = arr[i - 1] + arr[i - 2] + 1;
            else arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        cout << arr[n] << "\n";
    }

    return 0;
}   
