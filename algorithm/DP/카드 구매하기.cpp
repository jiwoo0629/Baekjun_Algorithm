#include <iostream>
#include <algorithm> 
using namespace std;

int n;
int price[1005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> price[i];
    for(int i=1; i<=n; i++) 
        for(int j=1; j<i; j++) price[i] = max(price[i-j] + price[j], price[i]);

    cout << price[n];

    return 0;
}
