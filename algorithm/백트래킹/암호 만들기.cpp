#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char letter[16];
char password[16];
bool issued[16];
//암호 : 최소 한개의 모음, 최소 두개의 자음, 증가하는 방향
//서로 다른 l개의 소문자로 구성, 사용했을 수 있는 문자 c가지

void func(int k) {
    if(k == l) {
        int cons = 0, vow = 0; //자음, 모음
        for(int i=0; i<k; i++) {
            if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') vow++;
            else cons++;
        }
        if(cons >= 2 && vow >= 1) {
            for(int i=0; i<k; i++) cout << password[i];
            cout << "\n";
        }
        return;
    }
    for(int i=0; i<c; i++) {
        if(!issued[i]) {
            if(k == 0 || (k > 0 && letter[i] > password[k-1])) {
                password[k] = letter[i];
                issued[i] = true;
                func(k+1);
                issued[i] = false;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for(int i=0; i<c; i++) cin >> letter[i];
    sort(letter, letter+c);

    func(0);

    return 0;
}
