#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> maxHeap; //num보다 큰 숫자들 관리 (오름차순)
    priority_queue<int, vector<int>, greater<>> minHeap; //num보다 작은 숫자들 관리 (내림차순)
    int n;
    cin >> n;    
    while(n--) {
        int num;
        cin >> num;
        if(maxHeap.size() <= minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);
        if(!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << "\n";
    }
    //maxHeap : -99 1 2 5
    //minHeap : 10 7 5

    return 0;
}
