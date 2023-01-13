#include <bits/stdc++.h>
using namespace std;

//2^n * 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수
int func(int N, int r, int c)
{
    //base condition
    if (N == 0) return 0;

    int half = 1 << (N - 1);
    //  재귀식
    if (r < half && c < half) //(r, c)가 1번 사각형일 때
        return func(N-1, r, c);
    if (r < half && c >= half) //(r, c)가 2번 사각형일 때
        return half * half + func(N - 1, r, c - half);
    if (r >= half && c < half) //(r, c)가 3번 사각형일 때
        return half * half * 2 + func(N - 1, r - half, c);
    if (r >= half && c >= half) //(r, c)가 4번 사각형일 때
        return half * half * 3 + func(N - 1, r - half, c - half);
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << func(N, r, c);

    return 0;
}
