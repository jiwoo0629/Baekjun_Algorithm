#include <bits/stdc++.h>
using namespace std;

const int MX = 5001;
int pre[MX], nxt[MX];

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    int n, k;
    cin >> n >> k;

    int len = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = (i == 1) ? n : i - 1;
        nxt[i] = (i == n) ? 1 : i + 1;
        ++len;
    }

    vector<int> v;
    int count = 1;
    for (int i = 1; len != 0; i = nxt[i]) {
        if (count == k) {
            pre[nxt[i]] = pre[i];
            nxt[pre[i]] = nxt[i];
            v.push_back(i);
            count = 1;
            len--;
        }
        else
            count++;
    }

    cout << "<";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) 
            cout << ", ";
    }
    cout << ">";

    return 0;
}
