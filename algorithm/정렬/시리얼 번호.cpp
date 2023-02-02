#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v(51);

bool cmp(string a, string b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < a.size(); i++) 
        if(isdigit(a[i])) sum_a += (a[i] - '0');
    for (int i = 0; i < b.size(); i++) 
        if(isdigit(b[i])) sum_b += (b[i] - '0');
    if (sum_a != sum_b) return sum_a < sum_b;
    return a < b;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.begin() + n, cmp);
    for (int i = 0; i < n; i++) cout << v[i] << "\n";

    return 0;
}
