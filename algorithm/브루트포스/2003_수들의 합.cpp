#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n, m; //n: 1~10000, m : 1~3억
int start = 0, finish = 0;
int sum = 0, answer = 0;
int a[10005];

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    while(finish <= n) {
        if(sum > m) sum -= a[start++];
        else if(sum < m) sum += a[finish++];
        else {
            answer++;
            sum += a[finish++];
        }
    }
    cout << answer;
    
    return 0;
}
