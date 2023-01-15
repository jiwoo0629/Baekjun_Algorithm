#include <bits/stdc++.h>
using namespace std;

int arr[2500][2500];
int n;
int minus1 = 0, zero = 0, plus1 = 0;

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
        if (past == -1) minus1++;
        else if (past == 0) zero++;
        else if (past == 1) plus1++;
        return;
    }
    else {
        func(a, b, n / 3);
        func(a + n / 3, b, n / 3);
        func(a + 2 * n / 3, b, n / 3);
        func(a, b + n / 3, n / 3);
        func(a + n / 3, b + n / 3, n / 3);
        func(a + 2 * n / 3, b + n / 3, n / 3);
        func(a, b + 2 * n / 3, n / 3);
        func(a + n / 3, b + 2 * n / 3, n / 3);
        func(a + 2 * n / 3, b + 2 * n / 3, n / 3);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    
    func(0, 0, n);
    cout << minus1 << "\n" << zero << "\n" << plus1;

    return 0;
}
