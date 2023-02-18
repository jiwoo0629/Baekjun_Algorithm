//n이 홀수 : 무조건 이김, n이 짝수 : 무조건 짐

#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int n;
    cin >> n;
    if(n % 2 == 1) cout << "SK";
    else cout << "CY";

    return 0;
}
