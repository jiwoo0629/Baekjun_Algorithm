#include <bits/stdc++.h>
using namespace std;

int n;
string arr[1000005];
long long arrll[1000005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        string s = arr[i];
        string s2 = "";
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s2.length() == 0 && s[j] == '0') continue;
            s2 += s[j];
        }
        arrll[i] = stoll(s2);
    }
    sort(arrll, arrll + n);
    for (int i = 0; i < n; i++) cout << arrll[i] << "\n";
    return 0;
}
