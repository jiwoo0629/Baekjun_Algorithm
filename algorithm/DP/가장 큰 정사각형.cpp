#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
string num[1002];
int arr[1005][1005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> num[i];
    int size = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(num[i][j] == '1') {
                //num[i-1][j], num[i][j-1], num[i-1][j-1]이 모두 1일 경우(정사각형일 경우)에만 1이 더해짐
                arr[i][j] = min({arr[i-1][j], arr[i][j-1], arr[i-1][j-1]}) + 1;
                size = max(size, arr[i][j]);
            }
        }
    }
    cout << size * size;

    return 0;
}



/*
#include <iostream>
#include <cmath>
using namespace std;

int n, m;
string num[1002];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> num[i];
    
    long long size = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(num[i][j] == '1') {
                bool escape = false;
                int a = 1;
                while(!escape) {
                    for(int k=0; k<a; k++) {
                        if(num[i+a][j+k] == '0' || num[i+k][j+a] == '0') {
                            size = max(size, (long long) pow(a-1, 2));
                            escape = true;
                            break;
                        }
                    }
                    if(num[i+a][j+a] == '0') {
                        size = max(size, (long long) pow(a-1, 2));
                        escape = true;
                    }
                    a++;
                }
                size = max(size, (long long) pow(a-1, 2));
            }
        }
    }
    cout << size;

    return 0;
}
*/
