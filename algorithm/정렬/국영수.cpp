#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
    string s_a, s_b;
    int k_a, k_b, e_a, e_b, m_a, m_b;
    tie(s_a, k_a, e_a, m_a) = a;
    tie(s_b, k_b, e_b, m_b) = b;
    if(k_a != k_b) return k_a > k_b;
    else if(e_a != e_b) return e_a < e_b;
    else if(m_a != m_b) return m_a > m_b;
    else return s_a < s_b;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<tuple<string, int, int, int>> v;
    while(n--) {
        string s;
        int k, e, m;
        cin >> s >> k >> e >> m;
        v.push_back({s, k, e, m});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) cout << get<0>(v[i]) << "\n";

    return 0;
}
