//먼저 배열을 만들어놓고 값을 가져다 써야 시간초과에 안걸림
#include <iostream>
using namespace std;

int n, m, s, e;
int num[2005];
int felindrom[2005][2005];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    for(int i=1; i<=n; i++) {
        felindrom[i][i] = 1; //자기 자신만 확인하는 경우
        if(num[i-1] == num[i]) felindrom[i-1][i] = 1;
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<=n; j++) 
            if(num[j] == num[j+i] && felindrom[j+1][j+i-1] == 1) felindrom[j][j+i] = 1;   
    }

    cin >> m;
    while(m--) {
        cin >> s >> e;
        cout << felindrom[s][e] << "\n";   
    }

    return 0;
}

/* 시간초과
#include <iostream>
using namespace std;

int n, m;
int num[2005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    cin >> m;
    while(m--) {
        bool felindrom = true;
        int s, e;
        cin >> s >> e;
        for(int i=0; i<=(e-s)/2; i++) 
            if(num[s+i] != num[e-i]) felindrom = false;
        if(felindrom) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
*/

