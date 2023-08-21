#include <iostream>
using namespace std;

//사탕을 공평하게 나누자!
//K명이 참가할 경우, K * X + 1개를 사야한다. (X는 자연수)
//봉지 하나에 사탕 C개
//봉지 몇개를 사야 하는가??

long long gcd(long long a, long long b) {
    long long c;
    while(b != 0) {
        c = a % b;
        a = b;
        b= c;
    }
    return a;
}

long long extended_uclid(long long k, long long c) { //확장 유클리드 호제법
    long long t, t1 = 0, t2 = 1;
    long long r, q;
    long long tmp = k;
    while(c != 0) {
        q = k / c;
        r = k - q * c;
        t = t1 - q * t2;
        k = c; c = r;
        t1 = t2; t2 = t;
    }
    while(t1 < 0) t1 += tmp; //해를 양수로 만드는 과정
    return t1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) { //1 시도당 최대 100만번 안에 완료
        long long k, c;
        cin >> k >> c;
        if(c == 1) {
            if(k + 1 > 1000000000) cout << "IMPOSSIBLE\n";
            else cout << k + 1 << "\n";
        }
        else if(k == 1) cout << 1 << "\n";    
        else if(gcd(k, c) != 1) cout << "IMPOSSIBLE\n";
        else { //확장 유클리드 호제법 => O(logN)
            long long ans = extended_uclid(k, c);
            if(ans > 1000000000) cout << "IMPOSSIBLE\n";
            else cout << ans << "\n";
        }   
    }
    return 0;
}
