#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long len[101];
    int t;
    cin >> t;
    
    len[1] = 1; len[2] = 1; len[3] = 1; len[4] = 2; len[5] = 2;
    while(t--) {
        int n;
        cin >> n;   
        if(n<=5) cout << len[n] << "\n";
        else {
            for(int i=6; i<=n; i++) len[i] = len[i-1] + len[i-5];
            cout << len[n] << "\n";
        }
    }

    return 0;

}
