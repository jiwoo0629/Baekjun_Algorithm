#include <iostream>
#include <queue>

using namespace std;

int n, k;
int ans = 0;
int arr[2][500005]; //0: 갔던 곳으로 돌아오지 않음, 1: 갔던 곳으로 돌아올 수도 있음

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<2; i++) fill(arr[i], arr[i]+500005, -1);
    cin >> n >> k;
    if(n == k) {
        cout << 0; 
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({n, 0});

    int cur = k;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int me = p.first;
        int time = p.second + 1;
        q.pop();
        for(int nx : {me+1, me-1, me*2}) {
            if(nx < 0 || nx > 500000) continue;
            if(arr[time % 2][nx] != -1) continue;
            arr[time%2][nx] = time;
            q.push({nx, time});
        }
    }   
    bool find = false;
    while(k <= 500000) {
        if(arr[ans % 2][k] <= ans) {
            find = true;
            break;
        }
        k += ++ans;
    }
    if(find) cout << ans;
    else cout << -1;

    return 0;
}
