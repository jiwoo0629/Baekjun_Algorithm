#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
long long sum[100005];
int start = 0, finish = 0; //시작위치, 끝위치
int answer = 100000;

int main(void) {
    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(i == 0) sum[i] = arr[i];
        else sum[i] = sum[i-1] + arr[i];
    }
    while(finish < n) {
        long long s_sum = sum[finish];
        if(start > 0) s_sum -= sum[start-1]; //부분합 구하기
        if(s_sum < s) finish++;
        else {
            answer = min(answer, finish - start + 1);
            start++;
        }
    }
    if(answer == 100000) cout << 0;
    else cout << answer;

    return 0;
}
