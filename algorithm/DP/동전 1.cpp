#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[102];
int ans[10005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    ans[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=arr[i]; j<=k; j++) 
            ans[j] += ans[j - arr[i]];
    }
    cout << ans[k] << "\n";

    return 0;
}
