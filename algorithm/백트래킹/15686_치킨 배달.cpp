#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int city[50][50]; //0: 빈칸, 1: 집, 2 : 치킨집 / 집 최소 1개 최대 2n개, 치킨집 최소 m개 최대 13개
int board[50][50]; //각 상황별 도시의 모습을 담을 임시 배열
vector<pair<int, int>> home; //집들의 위치를 모아놓은 벡터
vector<pair<int, int>> chicken; //'원래' 치킨집들의 위치를 모아놓은 벡터
int ans = 1000000;

int distance(int x1, int y1, int x2, int y2) { //집(x1, y1)과 치킨집(x2, y2)의 거리
    int dis = 0;
    dis += (x1 < x2) ? x2-x1 : x1-x2;
    dis += (y1 < y2) ? y2-y1 : y1-y2;
    return dis;
}

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1) home.push_back({i, j});
            else if(city[i][j] == 2) chicken.push_back({i, j});
        }
    }
    //선택 가능한 치킨집의 개수 : 1 ~ m, 원래 치킨집 개수 : chicken.size()
    for(int tmp=1; tmp<=m; tmp++) {
        vector<int> v; //순열을 위한 벡터
        for(int i=0; i<chicken.size()-tmp; i++) v.push_back(0);
        for(int i=0; i<tmp; i++) v.push_back(1);
        sort(v.begin(), v.end());
        do {
            int dis = 0;
            vector<pair<int, int>> chicken2; //남겨질 치킨집들의 위치
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(city[i][j] == 2) board[i][j] = 0; //일단 치킨집은 없는 걸로 취급하고 시작
                    else board[i][j] = city[i][j];
                }
            }
            for(int i=0; i<chicken.size(); i++) {//순열에서 그 값이 1인 경우, 해당 위치의 치킨집은 남겨놓는 것으로 취급
                if(v[i] == 1) {
                    board[chicken[i].first][chicken[i].second] = 2;
                    chicken2.push_back({chicken[i].first, chicken[i].second}); 
                }
            }
            for(int i=0; i<home.size(); i++) { //각 집 별로 치킨거리를 구함
                int len = 100;
                for(int j=0; j<chicken2.size(); j++) { //치킨집들과의 거리 중 최단거리
                    len = min(len, distance(home[i].first, home[i].second, chicken2[j].first, chicken2[j].second));
                }
                dis += len;
            }
            ans = min(ans, dis);
        } while(next_permutation(v.begin(), v.end()));
    }
    cout << ans;

    return 0;
}
