#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, h, o, d, ans = 0;
pair<int, int> list[100001];
vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> h >> o;
        if(h < o) list[i] = {h, o};
        else list[i] = {o, h};
    }
    sort(list, list+n, cmp);
    cin >> d;
    for(int i=0; i<n; i++) {
        int s = list[i].first, e = list[i].second;
        if(e - s > d) continue; //길이가 선분 길이 d보다 길면 패스
        pq.push({s, e}); //pq에 쌓 삽입
        while(pq.top().first < e - d) pq.pop(); //start < end - d 일때까지 pop
        ans = max(ans, (int)pq.size());
    }
    cout << ans;

    return 0;
}
