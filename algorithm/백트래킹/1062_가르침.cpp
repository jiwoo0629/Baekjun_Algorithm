#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans = 0; //단어의 개수, 읽을 수 있는 알파벳의 개수
bool c[26]; //a ~ z 가능여부
vector<string> vs; //문자열 벡터 (최대 50개), 길이는 0~7
vector<char> vc; //추가로 배울 수 있는 글자 list
//anta, tica 앞뒤로 자르기, a c i n t 가능 표시
//원래 읽을 수 있는 글자 = 5개, 만약 k가 5보다 작으면, 읽을 수 없음 (ans = 0)


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	c[0] = c[2] = c[8] = c[13] = c[19] = true; //a, c, i, n, t
	for (int i = 0; i < 26; i++)
		if (!c[i]) vc.push_back((char)(i + 97));
	for (int i = 0; i < n; i++) {
		string s, str = "";
		cin >> s;
		for (int j = 4; j < s.size() - 4; j++) str += s[j];
		vs.push_back(str);
	}
	if (k < 5) {
		cout << 0 << "\n";
		return 0;
	}
	k -= 5; //새로 배울 수 있는 알파벳 수
	vector<int> v;
	for (int i = 0; i < k; i++) v.push_back(1);
	for (int i = k; i < 21; i++) v.push_back(0); 
	sort(v.begin(), v.end());
	
	do { //21Ck 최대 21C10 = 약 35만
		int cnt = 0;
		vector<char> clist;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) {
				clist.push_back(vc[i]);
				c[vc[i] - 'a'] = true;
			}
		}
		for (int j = 0; j < vs.size(); j++) {
			string str = vs[j];
			bool possible = true;
			for (int k = 0; k < str.size(); k++)
				if (!c[str[k] - 'a']) possible = false;
			if (possible) cnt++;
		}
		ans = max(ans, cnt);
		for (int i = 0; i < clist.size(); i++) c[clist[i] - 'a'] = false;
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans;

	return 0;
}
