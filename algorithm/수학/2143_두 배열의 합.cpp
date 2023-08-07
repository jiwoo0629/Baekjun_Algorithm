#include <iostream>
#include <algorithm>
using namespace std;

int a[1005], b[1005]; 
vector<int> sum_a, sum_b; //가능한 모든 부분합을 모두 저장 
long long answer = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, m;
    cin >> t;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) { //최대 50만
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += a[j];
            sum_a.push_back(sum);
        }
    }
    cin >> m;
    for(int i=0; i<m; i++) cin >> b[i];
    for(int i=0; i<m; i++) { //최대 50만
        int sum = 0;
        for(int j=i; j<m; j++) {
            sum += b[j];
            sum_b.push_back(sum);
        }
    }
    sort(sum_b.begin(), sum_b.end());
    for(int i=0; i<sum_a.size(); i++) { //최대 1000 * log2 1000 = 약 1만번
        int high = upper_bound(sum_b.begin(), sum_b.end(), t-sum_a[i]) - sum_b.begin();
        int low = lower_bound(sum_b.begin(), sum_b.end(), t-sum_a[i]) - sum_b.begin();
        answer += (high - low);
    }
    cout << answer;
    
    return 0;
}
