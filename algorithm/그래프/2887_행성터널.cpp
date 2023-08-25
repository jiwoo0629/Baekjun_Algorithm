#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, x, y, z, root[100001];
long long ans = 0;
vector<pair<int, int>> pl_x, pl_y, pl_z; //각 좌표값, 행성번호
vector<tuple<int, int, int>> planet;

int find(int k) {
    if(root[k] == k) return k;
    return root[k] = find(root[k]);
}

bool union_(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return false;
    root[a] = b;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        root[i] = i;
        cin >> x >> y >> z;
        pl_x.push_back({x, i});
        pl_y.push_back({y, i});
        pl_z.push_back({z, i});
    }
    sort(pl_x.begin(), pl_x.end());
    sort(pl_y.begin(), pl_y.end());
    sort(pl_z.begin(), pl_z.end());
    for(int i=0; i<n-1; i++) {
        planet.push_back({pl_x[i+1].first - pl_x[i].first, pl_x[i].second, pl_x[i+1].second});
        planet.push_back({pl_y[i+1].first - pl_y[i].first, pl_y[i].second, pl_y[i+1].second});
        planet.push_back({pl_z[i+1].first - pl_z[i].first, pl_z[i].second, pl_z[i+1].second});
    }
    sort(planet.begin(), planet.end());
    for(int i=0; i<planet.size(); i++) {
        int val = get<0>(planet[i]);
        int pl1 = get<1>(planet[i]);
        int pl2 = get<2>(planet[i]);
        //union-find
        if(union_(pl1, pl2)) 
            ans += val;
    }
    cout << ans;

    return 0;
}
