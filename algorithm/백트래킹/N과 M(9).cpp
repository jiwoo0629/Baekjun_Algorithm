#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int ans[10];
bool isused[10];

void func(int k)
{
    if (k == m) {
        for (int i = 0; i < k; i++) 
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }    

    int tmp = 0; //중복 수열인지 확인하기 위한 변수
    for (int i = 0; i < n; i++) {
        if (!isused[i] && tmp != arr[i]) {
            isused[i] = true;
            ans[k] = arr[i];
            tmp = ans[k];
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    func(0);

    return 0;
}
