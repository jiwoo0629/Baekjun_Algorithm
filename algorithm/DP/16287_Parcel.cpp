#include <iostream>
#include <algorithm>
using namespace std;

int w, n, a[5001], d1[400001], d2[400001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> n;
    fill(d1, d1+400001, 0); fill(d2, d2+400001, 0);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int weight = a[i] + a[j];
            if(d1[weight] == 0) {
                d1[weight] = i; d2[weight] = j;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int weight = w - a[i] - a[j];
            //무게가 범위를 벗어나거나, 그 무게를 만들 수 있는 조합이 없는 경우 
            if(weight > 400000 || weight < 0 || d1[weight] == 0) continue; 
            //인덱스 쌍이 겹치지 않는지 확인
            if(i != d1[weight] && j != d2[weight] && i != d2[weight] && j != d1[weight]) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}
