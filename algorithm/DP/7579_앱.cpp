#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//보이지 않지만 '활성화'되어있는 앱은 여러가지 => 메인메모리에 '직전 상태'가 기록되어있다.
//메모리가 부족해지면, 활성화되어있는 앱 중 몇개를 선택해 '비활성화'한다.
//활성화 되어 있는 앱들 중 몇개를 비활성화 하여 m 바이트 이상의 메모리를 확보하고자 한다. 이때 필요한 최소 비용

int n, m, a[101], c[101]; //a: 활성화 되어 있는 앱 (값 : m(메모리) <= 1천만), c : 비활성화 후 다시 활성화하는 비용
long long dp[10001]; //dp[c] : c만큼의 비용을 사용했을 때, 1~n까지 모두 사용하면 얻을 수 있는 최대 메모리 값

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		int cost = c[i];
		for (int j = 10000 - cost; j >= 0; j--) //역순으로 돌면서 비교
			dp[j + cost] = max(dp[j + cost], dp[j] + a[i]); 
	}
	for (int i = 0; i < 10001; i++) {
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}
	
	return 0;
}
