#include <bits/stdc++.h>
using namespace std;

int arr[128][128];
int n;
int zero = 0, one = 0;

//a,b 시작 좌표, n 행렬 한변 길이
void func(int a, int b, int n)
{
    bool equal = true;
    int past = arr[a][b];
    for (int i = a; i < a+n; i++) {
        for (int j = b; j < b+n; j++) {
            if (arr[i][j] != past) 
                equal = false;
            past = arr[i][j];
        }
    }
    if (equal) {
        if (past == 0) zero++;
        else if (past == 1) one++;
        return;
    }
    else {
        func(a, b, n / 2);
        func(a + n / 2, b, n / 2);
        func(a, b + n / 2, n / 2);
        func(a + n / 2, b + n / 2, n / 2);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    
    func(0, 0, n);
    cout << zero << "\n" << one;

    return 0;
}
