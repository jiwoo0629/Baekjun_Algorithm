#include <bits/stdc++.h>
using namespace std;

long long func(long long a, long long b, long long c) 
{
    if (b == 1) return a % c; //1승을 계산할 수 있다.
    long long val = func(a, b / 2, c); //재귀를 이용해 a의 (b/2)승의 값을 구함.
    val = val * val % c; //k승을 계산했으면
    if (b % 2 == 0) return val; //2k승
    return val * a % c; //2k+1승도 계산할 수 있다.
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);

    return 0;
}
