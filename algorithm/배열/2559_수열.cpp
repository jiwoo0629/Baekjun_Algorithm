#include <iostream>
#include <algorithm>
using namespace std;

int n, k, arr[100005];
int sum = 0, answer = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) { //n <= 10만
        int num;
        cin >> num;
        sum += num;
        arr[i] = sum;
    }
    answer = arr[k-1];
    for(int i=k; i<n; i++) 
        answer = max(answer, arr[i] - arr[i-k]);
    
    cout << answer;

    return 0;
}
