#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[21];
bool used[21];
long long factorial[21];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mission;
    factorial[0] = 1;
    for(int i=1; i<21; i++) factorial[i] = i * factorial[i-1]; //미리 초기화
    cin >> n;
    cin >> mission;
    if(mission == 1) {
        long long k;
        cin >> k;
        k--; //0부터 시작인 개념이니까 1 줄여놓고 계산
        for(int i=1; i<=n; i++) {
            int d = k / factorial[n-i]; //만약 k가 3!보다 작을 경우, d = 0
            k = k % factorial[n-i];
            int idx = 1;
            while(used[idx]) idx++; //아직 사용하지 않은 가장 최근 숫자를 찾음
            //d = 0이면, 알맞은 idx를 찾은것이므로 while문을 돌면서 idx를 올려줄 필요가 없음
            while(d > 0) { //값에 알맞는 idx를 찾을 때까지,,
                d--;
                do {
                    idx++;
                } while(used[idx]); //사용하지 않은 idx를 찾는다.
            }
            ans[i] = idx; //이 idx를 넣어준다.
            used[idx] = true; //사용 표시
        }
        for(int i=1; i<=n; i++) cout << ans[i] << " ";
    }
    else if(mission == 2) {
        long long answer = 0;
        for(int i=1; i<=n; i++) cin >> ans[i];
        for(int i=1; i<n; i++) {
            long long cnt = 0;
            used[ans[i]] = true; //사용 표시
            for(int j=1; j<ans[i]; j++) { //이 숫자가 남은 숫자들 중 앞에서 몇번째 숫자인지 확인
                if(used[j]) continue;
                cnt++;
            }
            answer += (cnt * factorial[n - i]); //그만큼 더해줌
        }
        answer++; //마지막 자리에서는 무조건 1 더해주니까
        cout << answer;
    }
    
    return 0;
}
