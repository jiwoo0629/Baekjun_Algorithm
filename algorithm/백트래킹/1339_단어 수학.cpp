#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n, answer;
int new_num[10];
int char_num[26]; //문자가 사용된 횟수
string str[10]; //문자열
//수의 최대 길이가 8이므로 결과의 최대값은 int 범위 내이다.

void rec(int position) {
    if(position == 10) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            int t = 0;
            for(int j=0; str[i][j]; j++) {
                t *= 10;
                t += new_num[char_num[str[i][j]-'A']];
            }
            sum += t;
        }
        answer = max(answer, sum);
        return;
    }
    for(int i=0; i<10; i++) {
        if(new_num[i] < 0) {
            new_num[i] = position;
            rec(position+1);
            new_num[i] = -1;
        }
    }
}

int main(void) {
    cin >> n;
    fill(new_num, new_num+10, -1);
    for(int i=0; i<n; i++) {
        cin >> str[i];
        for(int j=0; str[i][j]; j++) 
            char_num[str[i][j] - 'A']++;
    }
    int pointer = -1;
    for(int i=0; i<26; i++) {
        pointer += !!char_num[i];
        char_num[i] = pointer;
    } 
    answer = 0;
    rec(0);
    cout << answer;

    return 0;
}
