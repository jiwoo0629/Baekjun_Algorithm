#include<iostream>
#include <string>

using namespace std;

int n, p;
char c;
string s1, s2, answer = "";

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> s1 >> s2;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] == 'x' || s1[i] == 'X') {
                answer += (s2[i] >= 'a' && s2[i] <= 'z') ? s2[i] - 32 : s2[i];
                break;
            }
        }
    }
    cout << answer;
    return 0;
}
