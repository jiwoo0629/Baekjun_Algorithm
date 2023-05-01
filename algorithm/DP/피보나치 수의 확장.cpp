#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[2000010];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num = n;
    if(num < 0) num *= -1; //음수일 경우 양수로
    
    //경계 : 0~num 이므로 num+1개, 경계 : n <-> n+1 
    arr[num] = 0;
    if(num != 0) arr[num-1] = arr[num+1] = 1;
    for(int i=2; i<=num; i++) {
        arr[num+i] = (arr[num+i-1] + arr[num+i-2]) % 1000000000; //arr[n+2] = arr[n+1] + arr[n]
        arr[num-i] = (arr[num-i+2] - arr[num-i+1]) % 1000000000; //arr[n-2] = arr[n] - arr[n-1];
    }
    
    if(arr[n+num] > 0) 
        cout << 1 << "\n";
    else if(arr[n+num] < 0) {
        cout << -1 << "\n";
        arr[n+num] *= -1;
    }
    else 
        cout << 0 << "\n";
    cout << arr[n+num];

    return 0;
}
