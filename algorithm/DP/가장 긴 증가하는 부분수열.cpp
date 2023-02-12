#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int len[1005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        len[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i]) len[i] = max(len[i], len[j] + 1);
    }
    cout << *max_element(len, len + n);

    return 0;
}
