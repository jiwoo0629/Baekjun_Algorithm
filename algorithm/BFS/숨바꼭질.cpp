#include <bits/stdc++.h>
using namespace std;

int n, k;
int tim[100002];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(tim, tim + 100002, -1);
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    tim[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == 0 && tim[cur + 1] == -1) {
            q.push(cur + 1);
            tim[cur + 1] = tim[cur] + 1;
        }
        else if (cur == 100000 && tim[cur - 1] == -1) {
            q.push(cur - 1);
            tim[cur - 1] = tim[cur] + 1;
        }
        else if (cur * 2 > 100000) {
            if (tim[cur - 1] == -1) {
                q.push(cur - 1);
                tim[cur - 1] = tim[cur] + 1;
            }
            if (tim[cur + 1] == -1) {
                q.push(cur + 1);
                tim[cur + 1] = tim[cur] + 1;
            }
        }
        else {
            if (tim[cur - 1] == -1) {
                q.push(cur - 1);
                tim[cur - 1] = tim[cur] + 1;
            }
            if (tim[cur + 1] == -1) {
                q.push(cur + 1);
                tim[cur + 1] = tim[cur] + 1;
            }
            if (tim[cur * 2] == -1) {
                q.push(cur * 2);
                tim[cur * 2] = tim[cur] + 1;
            }
        }
        if (tim[k] != -1) {
            cout << tim[k];
            break;
        }
    }
    return 0;
}
