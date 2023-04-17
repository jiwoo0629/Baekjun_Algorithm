#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

//n : 계정 비밀번호의 최댓값 (0 <= n <= 1000000)
//m : 로그인 시도에 사용된 비밀번호 개수 (0 <= m <= 100000)
int n, m, p; 
string tobinary[1000005];
int safety[1000005]; //비밀번호 별 최소 안전도

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(safety, safety+n+2, -1);
    cin >> m;
    queue<int> plist; //로그인 시도에 사용된 비밀번호 리스트
    while(m--) {
        cin >> p;
        safety[p] = 0;
        plist.push(p);
    }
    
    while(!plist.empty()) {
        int cur = plist.front();
        plist.pop();
        int next;
        for(int i=0; i<20; i++) {
            if(cur & (1 << i)) next = cur & ~(1 << i);
            else next = cur | (1 << i);
            if(next > n) continue;
            if(safety[next] >= 0) continue;
            safety[next] = safety[cur] + 1;
            plist.push(next);
        }
    }
    cout << *max_element(safety, safety+n+2);

    return 0;
}

