#include <iostream>
#include <algorithm>
using namespace std;

int arr1 [100005];
int arr2 [100005];

int binary_search(int arr[], int len, int num) //이분 탐색을 통해 시간 단축
{
	int l = 0, r = len - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] == num)
			return 1;
		else if (arr[m] < num)
			l = m + 1;
		else
			r = m - 1;
	}
	return 0;
}

int main(void)
{
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr1[i];
	sort(arr1, arr1 + n);

	cin >> m;
	for (int i = 0; i < m; i++) 
		cin >> arr2[i];
	
	for (int i = 0; i < m; i++)
		cout << binary_search(arr1, n, arr2[i]) << '\n';

	return 0;
}
