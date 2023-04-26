#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[10005];
int drink[10005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    drink[1] = arr[1]; 
    drink[2] = arr[1] + arr[2];
    //직전에 2개 연속, 한칸 띄고 1개, 한칸 띄고 2개 연속
    for(int i=3; i<=n; i++) 
        drink[i] = max({drink[i-1], drink[i-2] + arr[i], drink[i-3] + arr[i-1] + arr[i]});
    cout << drink[n];

    return 0;
}
