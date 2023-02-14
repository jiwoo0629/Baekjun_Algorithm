#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n; 
int t[20], p[20], pro[20];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> n;

    for(int i=1; i<=n; i++) cin >> t[i] >> p[i];

    for(int i=n; i>=1; i--) {
        //i번째 일을 했을 때랑 안했을 때 중에 더 이익이 되는 경우를 선택
        if(i + t[i] <= n + 1) pro[i] = max(pro[i+1], pro[i + t[i]] + p[i]);
        else pro[i] = pro[i+1];
    }   
    cout << *max_element(pro, pro+n+1);

    return 0;

}
