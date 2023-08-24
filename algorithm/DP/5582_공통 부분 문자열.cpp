#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int n, m, lcs[4005][4005], ans = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a;
	cin >> b;
	n = a.size(); m = b.size();
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) continue;
			else if (a[i-1] != b[j-1]) continue;
			else lcs[i][j] = max(lcs[i][j], lcs[i - 1][j - 1] + 1);
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) ans = max(ans, lcs[i][j]);
	cout << ans;

	return 0;
}
