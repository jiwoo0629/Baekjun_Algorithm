#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[3], max_dp[3], min_dp[3], tmp[3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if(i == 0) {
            for(int i=0; i<3; i++) {
                max_dp[i] = arr[i];
                min_dp[i] = arr[i];
            }
            continue;
        }
        for(int i=0; i<3; i++) 
            tmp[i] = max_dp[i];
        max_dp[0] = max(tmp[0], tmp[1]) + arr[0];
        max_dp[1] = max({tmp[0], tmp[1], tmp[2]}) + arr[1];
        max_dp[2] = max(tmp[1], tmp[2]) + arr[2];
        for(int i=0; i<3; i++)
            tmp[i] = min_dp[i];
        min_dp[0] = min(tmp[0], tmp[1]) + arr[0];
        min_dp[1] = min({tmp[0], tmp[1], tmp[2]}) + arr[1];
        min_dp[2] = min(tmp[1], tmp[2]) + arr[2];
    }   
    cout << *max_element(max_dp, max_dp + 3) << " " << *min_element(min_dp, min_dp + 3);

    return 0;
}
