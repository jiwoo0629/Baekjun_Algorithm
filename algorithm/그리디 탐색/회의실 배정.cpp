#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100005];

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
    stable_sort(arr, arr + n, compare);

    int answer = 0;
    int t = 0; //현재 시간
    for(int i=0; i<n; i++) {
        if(t > arr[i].first) continue;
        t = arr[i].second;
        answer++;
    }
    cout << answer;
 
    return 0;
}
