#include <iostream>
#include <algorithm> 
using namespace std;

int t, n;
int sticker[2][100005];
int score[2][100005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<2; i++) fill(sticker[i], sticker[i]+n, 0);
        for(int i=0; i<2; i++) 
            for(int j=0; j<n; j++) cin >> sticker[i][j];

        for(int i=0; i<n; i++) {
            for(int j=0; j<2; j++) {
                int k=0;
                if(i>1) k = max(score[0][i-2], score[1][i-2]); //
                if(i>0) k = max(k, score[1-j][i-1]);
                score[j][i] = k + sticker[j][i];
            }
        }
        cout << max(score[0][n-1], score[1][n-1]) << "\n";
    }

    return 0;
}
