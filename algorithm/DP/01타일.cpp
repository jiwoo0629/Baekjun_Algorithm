#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tile[1000005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    tile[1] = 1; tile[2] = 2;
    for(int i=3; i<=n; i++) tile[i] = (tile[i-1] + tile[i-2]) % 15746;

    cout << tile[n];

    return 0;
}
