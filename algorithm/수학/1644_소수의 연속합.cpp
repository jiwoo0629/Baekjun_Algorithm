#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> prime;
vector<long long> prime_sum;
bool check[4000005];
bool isPrime[4000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=2; i<=4000000; i++) {
        if(!check[i]) {
            prime.push_back(i);
            if(i == 2) prime_sum.push_back(i);
            else prime_sum.push_back(prime_sum.back() + i);
            isPrime[i] = true;
        }
        int idx = i;
        while(idx <= 4000000) {
            if(!check[idx]) check[idx] = true;
            idx += i;
        }
    }
    int num;
    cin >> num;
    int start = 0, end = 0, answer = 0;
    while(start <= end) {
        long long sum = prime_sum[end];
        if(start > 0) sum -= prime_sum[start-1]; 
        if(sum < num) end++;
        else if(sum > num) start++;
        else {
            answer++;
            end++;
        }
    }
    cout << answer;
    
    return 0;
}
