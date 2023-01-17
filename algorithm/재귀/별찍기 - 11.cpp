#include <bits/stdc++.h>
using namespace std;

char board[3100][6200];
int n;

//a, b : 시작점, k : 차지하는 칸 수
void func(int a, int b, int k)
{
    //k=3이 되면 수행하고 종료
    if (k == 3) {
        for (int i = a; i < a + k; i++) {
            for (int j = b - k + 1; j < b + k; j++) {
                if (i == a) {
                    if (j == b) board[i][j] = '*';
                    else board[i][j] = ' ';
                }
                else if (i == a + 1) {
                    if (j == b - 1 || j == b + 1) board[i][j] = '*';
                    else board[i][j] = ' ';
                }
                else if (i == a + 2) board[i][j] = '*';
            }
        }
        return;
    }
    func(a, b, k / 2);
    func(a + k / 2, b - k / 2, k / 2);
    func(a + k / 2, b + k / 2, k / 2);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        fill(board[i], board[i] + 2 * n, ' ');
    func(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) cout << board[i][j];
        cout << "\n";
    }

    return 0;
}
