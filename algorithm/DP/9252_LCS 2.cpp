#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int i, j, n, m, lcs[1005][1005];
char c[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a;
	cin >> b;
	n = a.size(); m = b.size();

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i-1] != b[j-1]) lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			else lcs[i][j] = lcs[i - 1][j - 1] + 1;
		}
	}
	i = n; j = m;
	while (lcs[i][j] > 0) {
		while (lcs[i - 1][j] == lcs[i][j]) i--;
		while (lcs[i][j - 1] == lcs[i][j]) j--;
		i--; j--;
		c[lcs[i][j]] = b[j];
	}
	cout << lcs[n][m] << "\n";
	for (int i = 0; i < lcs[n][m]; i++) cout << c[i];

	return 0;
}
