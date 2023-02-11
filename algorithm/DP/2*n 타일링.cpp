#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int count[1001];
    count[1] = 1;
    count[2] = 2;
    for (int i = 3; i <= n; i++) 
        count[i] = (count[i - 1] + count[i - 2]) % 10007;
    cout << count[n];
    
    return 0;
}
