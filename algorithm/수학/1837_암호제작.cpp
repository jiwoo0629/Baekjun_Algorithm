#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> prime;
bool check[1000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string p;
    int k;
    cin >> p >> k;
    for(int i=2; i<k; i++) {
        if(!check[i]) prime.push_back(i);
        int idx = i;
        while(idx < k) {
            if(!check[idx]) check[idx] = true;
            idx += i;
        }
    }
    for(int i=0; i<prime.size(); i++) {
        int result = (p[0] - '0') % prime[i];
        for(int idx = 1; idx < p.size(); idx++) 
            result = (result * 10 + (p[idx] - '0')) % prime[i];
        if(result == 0) {
            cout << "BAD " << prime[i];
            return 0;
        }
    }
    cout << "GOOD";
    
    return 0;
}
