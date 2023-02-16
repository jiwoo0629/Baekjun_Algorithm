#include <iostream>
#include <cmath>
using namespace std;

int n, p;
int coin[21], price[10005];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int t;
    cin >> t;
    while(t--) {
        fill(price, price+10005, 0);
        cin >> n;
        for(int i=1; i<=n; i++) cin >> coin[i];
        cin >> p;
        price[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=coin[i]; j<=p; j++) price[j] += price[j - coin[i]];
        }
        cout << price[p] << "\n";
    }

    return 0;
}
