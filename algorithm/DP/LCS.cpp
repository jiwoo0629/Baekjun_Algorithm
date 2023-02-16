#include <iostream>
using namespace std;

string str1, str2;
int lcs[1002][1002];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> str1 >> str2;
    int m = str1.length();
    int n = str2.length();
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1] == str2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    cout << lcs[m][n];

    return 0;
}
