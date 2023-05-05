#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51], b[51];
bool cmp (int x, int y) {
    return x > y;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n, cmp);
    int S = 0;
    for(int i=0; i<n; i++) S += (a[i] * b[i]);
    cout << S;

    return 0;
}
