#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v(n + m);
        int k;
        for (int i = 0; i < n; i++) { //A의 숫자
            cin >> k;
            v[i] = { k, 0 };
        }
        for (int i = n; i < n+m; i++) { //B의 숫자
            cin >> k;
            v[i] = { k, 1 };
        }
        sort(v.begin(), v.end());

        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n+m; i++) {
            if (v[i].second == 0) ans += cnt; //A의 숫자일 경우
            else cnt++; //B의 숫자일 경우
        }
        cout << ans << "\n";
    }

    return 0;
}   
