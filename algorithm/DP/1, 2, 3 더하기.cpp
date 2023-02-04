#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int arr[11];
    arr[1] = 1, arr[2] = 2, arr[3] = 4;
    for (int i = 4; i <= 11; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    while (t--) {
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}   
