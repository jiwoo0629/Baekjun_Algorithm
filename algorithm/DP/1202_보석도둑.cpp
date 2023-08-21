#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long answer = 0;
int n, k, i;
pair<int, int> jewel[300005];
int bag[300005];
priority_queue<int> pq;
int main(void) {
    cin >> n >> k;
    for(i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        jewel[i] = {m, v};
    }
    for(i=0; i<k; i++) 
        cin >> bag[i];
    sort(jewel, jewel+n);
    sort(bag, bag+k);
    int idx = 0;
    for(i=0; i<k; i++) { //각 가방에 대해 담을 수 있는 최대 무게를 최대힙에 저장
        while(idx < n && jewel[idx].first <= bag[i]) { //일단 가능한 무게 다 담고
            pq.push(jewel[idx].second);
            idx++;
        }
        if(!pq.empty()) { //그 중 맨 위의 값을 answer에 더함
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
    
    return 0;
}
