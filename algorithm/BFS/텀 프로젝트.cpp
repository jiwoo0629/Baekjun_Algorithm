#include <iostream>
#include <queue>
using namespace std;

int n;
int pref[100005]; // 각 번호의 학생이 선호하는 학생의 번호 ex) pref[1] = 2 : 1번이 2번 학생을 선호
int team[100005]; // 0: 팀에 속하지 않은 경우, -1: 팀에 속한 경우 

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        fill(team, team+n+1, 0);
        for(int i=1; i<=n; i++) cin >> pref[i];
        for(int i=1; i<=n; i++) {
            if(team[i] != 0) continue;
            int cur = i;
            while(1) {
                team[cur] = i;
                cur = pref[cur];
                if(team[cur] == i) {
                    while(team[cur] != -1) {
                        team[cur] = -1;
                        cur = pref[cur];
                    }
                    break;
                }
                else if(team[cur] != 0) break;
            }
        }            
        int notpick = 0;
        for(int i=1; i<=n; i++) if(team[i] != -1) notpick++;
        cout << notpick << "\n";
    }

    return 0;
}
