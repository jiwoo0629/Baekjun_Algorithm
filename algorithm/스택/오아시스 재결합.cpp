#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<int, int>> s; //<키, 쌍>
    long long pair = 0;
    while(n--) {
        int h; //n번째 사람의 키
        cin >> h;
        int cnt = 1; //n번째 사람이 볼 수 있는 쌍
        while(!s.empty() && s.top().first <= h) {
            pair += s.top().second;
            if(s.top().first == h) cnt += s.top().second;
            s.pop();
        }
        if(!s.empty()) pair++;
        s.push({h, cnt});
    }
    cout << pair;

    return 0;
}
