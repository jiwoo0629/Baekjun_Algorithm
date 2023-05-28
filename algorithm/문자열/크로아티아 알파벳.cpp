#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<string> v = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
    cin >> str;
    int cnt = 0;
    while(str.size() > 0) {
        bool found = false;
        for(int i=0; i<v.size(); i++) {
            if(str.find(v[i]) == 0) { //목록에 있는 알파벳
                found = true;
                str.erase(0, v[i].size());
                cnt++;
                break;
            }
        }
        if(!found) { //목록에 없는 알파벳
            str.erase(0, 1); //한글자씩
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
