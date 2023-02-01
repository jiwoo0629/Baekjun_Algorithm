#include <bits/stdc++.h>
using namespace std;

int n, t;
int tmp[2000002];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> t;
        tmp[t + 1000000]++;
    }
    for (int i = 0; i <= 2000000; i++) 
        while(tmp[i]--) cout << i - 1000000 << "\n";

    return 0;
}
