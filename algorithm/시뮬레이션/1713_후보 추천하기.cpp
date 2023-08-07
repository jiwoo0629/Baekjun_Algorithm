#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, cnt;
	cin >> n >> cnt;
	vector<pair<int, int>> v; //추천받은 학생, 추천 횟수 
	vector<int> v2; //추천받은 학생 순서 
	while(cnt--) {
		int num;
		cin >> num;
		if(find(v2.begin(), v2.end(), num) == v2.end()) { //존재하지 않는 경우 
			if(v.size() < n) { //빈 사진틀이 있는 경우 
				v.push_back({num, 1});
				v2.push_back(num);
			}
			else { //빈 사진틀이 없는 경우 
				vector<int> v_cnt; 
				for(int i=0; i<v.size(); i++) v_cnt.push_back(v[i].second);
				int lowest = *min_element(v_cnt.begin(), v_cnt.end());
				vector<int> v_std;
				for(int i=0; i<v.size(); i++) 
					if(v[i].second == lowest) v_std.push_back(v[i].first);	
				for(int i=0; i<v2.size(); i++) {
					bool found = false;
					for(int j=0; j<v_std.size(); j++) {
						if(v2[i] == v_std[j]) {
							found = true;
							for(int k=0; k<v.size(); k++) 
								if(v[k].first == v2[i]) v.erase(v.begin() + k);
							v2.erase(v2.begin() + i);
						}
						break;
					}
					if(found) break;
				}
				v.push_back({num, 1});
				v2.push_back(num);
			}
		}
		else  //이미 존재하는 경우 
			v[find(v2.begin(), v2.end(), num)-v2.begin()].second++;	
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++) cout << v[i].first << " ";
	return 0;
}
