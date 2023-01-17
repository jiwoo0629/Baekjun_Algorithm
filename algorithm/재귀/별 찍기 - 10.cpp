#include <bits/stdc++.h>
using namespace std;

char board[10000][10000];
int n;

//a, b : 시작점, k : 차지하는 칸 수
void func(int a, int b, int k)
{
    //n=3이 되면 수행하고 종료
    if (k == 3) {
        for (int i = a; i < a + k; i++) {
            for (int j = b; j < b + k; j++) {
                if (i == a + 1 && j == b + 1) board[i][j] = ' ';
                else board[i][j] = '*';
            }
        }
        return;
    }
    func(a, b, k / 3);
    func(a, b + k / 3, k / 3);
    func(a, b + 2 * k / 3, k / 3);
    func(a + k / 3, b, k / 3);
    func(a + k / 3, b + 2 * k / 3, k / 3);
    func(a + 2 * k / 3, b, k / 3);
    func(a + 2 * k / 3, b + k / 3, k / 3);
    func(a + 2 * k / 3, b + 2 * k / 3, k / 3);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        fill(board[i], board[i] + n, ' ');
    func(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << board[i][j];
        cout << "\n";
    }
        


    return 0;
}
