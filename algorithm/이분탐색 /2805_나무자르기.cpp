#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

/*
나무 N개 (~100만개) 높이 (0~10억), 얻고 싶은 나무 M미터 (~20억)
적어도 M미터의 나무를 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값
*/

int n, m, answer;
int tree[1000005];

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> tree[i];
    int start = 0, end = 1000000000, mid;
    while(start <= end) {
        mid = (start + end) / 2;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            if(tree[i] > mid)
                sum += (tree[i] - mid);
        }
        if(m <= sum) {
            answer = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << answer;
    
    return 0;
}
