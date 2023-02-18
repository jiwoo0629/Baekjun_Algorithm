#include <iostream>
using namespace std;

string s;
int num[5005];
long long cnt[5005];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    cin >> s;
    for(int i=1; i <= s.length(); i++) num[i] = s[i-1] - '0';
    if(num[1] == 0) {
        cout << 0;
        return 0;
    }
    cnt[0] = 1;

    for(int i=1; i <= s.length(); i++) {
        if(num[i] > 0) cnt[i] = (cnt[i] + cnt[i-1]) % 1000000;
        int n = num[i-1] * 10 + num[i];
        if(n >= 10 && n <= 26) cnt[i] = (cnt[i] + cnt[i-2]) % 1000000;
    }
    cout << cnt[s.length()];

    return 0;
}
