#include <iostream>
#include <algorithm>
using namespace std;

int t, w;
int tree[1005];
int jadu[1005][31][2]; //받게 되는 자두 개수, n번째 자두- 이동횟수 - 나무번호

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    for(int i=1; i<=t; i++) cin >> tree[i];

    for(int i=1; i<=t; i++) {
        //이동하지 않는 경우
        if(tree[i] == 1) jadu[i][0][0] = jadu[i-1][0][0] + 1;
        else jadu[i][0][0] = jadu[i-1][0][0];
        for(int j=1; j<=w; j++) {
            if(i < j) break;
            if(tree[i] == 1) { //1번 나무
                jadu[i][j][0] = max(jadu[i-1][j-1][1], jadu[i-1][j][0]) + 1;
                jadu[i][j][1] = max(jadu[i-1][j-1][0], jadu[i-1][j][1]);
            }
            else { //2번 나무
                jadu[i][j][0] = max(jadu[i-1][j-1][1], jadu[i-1][j][0]);
                jadu[i][j][1] = max(jadu[i-1][j-1][0], jadu[i-1][j][1]) + 1;
            }
        }
    }
    int maxjadu = 0;
    for(int i=1; i<=w; i++) 
        maxjadu = max({maxjadu, jadu[t][i][0], jadu[t][i][1]});
    cout << maxjadu;

    return 0;
}
