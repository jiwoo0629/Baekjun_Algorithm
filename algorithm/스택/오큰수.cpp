#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    int arr[1000005];
    int ans[1000005];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && s.top() <= arr[i]) s.pop();
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(arr[i]);
    }
    for(int i=0; i<n; i++) cout << ans[i] << " ";

    return 0;
}

//stack을 이용해 시간복잡도를 O(n)으로 만드는 것이 중요함!!
