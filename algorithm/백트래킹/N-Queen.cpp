#include <bits/stdc++.h>
using namespace std;

int n;
bool isused1[15]; //열에 대응되는 값
bool isused2[30]; //퀸이 (x,y)에 있으면 isused2[x+y]를 true로 만듬
bool isused3[30]; //퀸이 (x,y)에 있으면 isused3[x-y+n-1]를 true로 만듬

int cnt = 0;
void func(int k)
{
    if (k == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isused1[i] && !isused2[k+i] && !isused3[k-i+n-1]) {
            isused1[i] = true;
            isused2[k + i] = true;
            isused3[k - i + n - 1] = true;
            func(k + 1);
            isused1[i] = false;
            isused2[k + i] = false;
            isused3[k - i + n - 1] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;

    return 0;
}
