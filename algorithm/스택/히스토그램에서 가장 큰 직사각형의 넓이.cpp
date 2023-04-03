#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        int n;
        cin >> n;
        if(n == 0) break;
        stack<pair<int, int>> s; //<높이, n번째>
        long long size = 0;
        for(int i=0; i<n; i++) {
            int h; //n번째 직사각형의 높이
            cin >> h;
            int cnt = i; 
            while(!s.empty() && s.top().first >= h) {
                size = max(size, 1LL * (i-s.top().second) * s.top().first); 
                cnt = s.top().second;
                s.pop();
            }
            s.push({h, cnt});
        }
        while(!s.empty()) {
            size = max(size, 1LL * (n-s.top().second) * s.top().first); 
            s.pop();
        }
        cout << size << "\n";
    }

    return 0;
}
