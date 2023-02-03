#include <bits/stdc++.h>
using namespace std;

int n;
string arr[20002];

bool cmp(string a, string b)
{
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i - 1] == arr[i]) continue;
        cout << arr[i] << "\n";
    }

    return 0;
}
