#include <bits/stdc++.h>
using namespace std;

int arr[64][64];
int n;

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
        cout << past;
        return;
    }
    else {
        cout << "(";
        func(a, b, n / 2);
        func(a, b + n / 2, n / 2);
        func(a + n / 2, b, n / 2);
        func(a + n / 2, b + n / 2, n / 2);
        cout << ")";
        return;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            arr[i][j] = s[j] - '0';
    }
    func(0, 0, n);

    return 0;
}
