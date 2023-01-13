#include <bits/stdc++.h>
using namespace std;


//원판 n개를 기둥 a에서 기둥 b로 옮기는 방법을 출력하는 함수
void func(int a, int b, int n) 
{
    //base condition : n = 1일때 출력
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
        
    //재귀식
    func(a, 6 - a - b, n - 1); //n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
    cout << a << ' ' << b << '\n'; //n번 원판을 기둥 a에서 기둥 b로 옮긴다.
    func(6 - a - b, b, n - 1); //n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    func(1, 3, n);

    return 0;
}
