#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, arr[100001], l, r, min_sum, x1, x2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    l = 0; r = n-1;
    min_sum = abs(arr[l] + arr[r]); x1 = arr[l]; x2 = arr[r];
    while(l < r) {
        int tmp = arr[l] + arr[r];
        if(min_sum > abs(tmp)) {
            min_sum = abs(tmp);
            x1 = arr[l]; x2 = arr[r];
        }
        if(tmp < 0) l++;
        else r--;
    }
    cout << x1 << " " << x2;

    return 0;
}
