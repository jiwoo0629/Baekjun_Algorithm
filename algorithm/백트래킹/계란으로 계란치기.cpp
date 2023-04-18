#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    계란으로 계란 치기
    각 계란의 내구도는 상대 계란의 무게만큼 깍이고, 내구도가 0 이하가 되면 계란은 깨진다
    1. 가장 왼쪽의 계란을 든다.
    2. 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. 
       단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다. 이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행한다.
    2. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다. 
       단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.
    최대 몇개의 계란을 깰 수 있는지 맞추기
*/

int n;
vector<pair<int, int>> egg; //계란의 내구도, 무게
int maxegg = 0;
int broke = 0;

void func(int k) {
    if(k == n) {
        maxegg = max(maxegg, broke);
        return;
    }
    if(egg[k].first <= 0 || broke == n-1) { //k번째 달걀이 이미 깨졌거나, 빼고 다 깨졌을 경우?
        func(k+1);
        return;
    }
    for(int i=0; i<n; i++) {
        if(i == k || egg[i].first <= 0) continue;
        egg[i].first -= egg[k].second;
        egg[k].first -= egg[i].second;
        if(egg[i].first <= 0) broke++;
        if(egg[k].first <= 0) broke++;
        func(k+1);
        if(egg[i].first <= 0) broke--;
        if(egg[k].first <= 0) broke--;
        egg[i].first += egg[k].second;
        egg[k].first += egg[i].second;
    }
    
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int s, w;
        cin >> s >> w;
        egg.push_back({s, w});
    }
    func(0);
    cout << maxegg;

    return 0;
}
