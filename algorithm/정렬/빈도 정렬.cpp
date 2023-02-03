#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<pair<int, int>> v; //<숫자, 개수>

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        bool exist = false;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].first == k) {
                exist = true;
                v[j].second++;
            }
        }
        if (!exist) v.push_back({ k, 1 });
    }
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[i].second; j++) cout << v[i].first << " ";

    return 0;
}   
