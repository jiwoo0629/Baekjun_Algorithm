#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coin[102];
int price[10005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> coin[i];

    fill(price, price+k+1, 100001);
    price[0] = 0;
    for(int i=0; i<n; i++) 
        for(int j=coin[i]; j<=k; j++) price[j] = min(price[j], price[j-coin[i]] + 1);

    if(price[k] == 100001) cout << -1;
    else cout << price[k];

    
    return 0;
}
