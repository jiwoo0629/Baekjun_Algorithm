#include <iostream>
#include <algorithm>
using namespace std;

int n, k=0;
int graph[100005][3];
long long cost[100005][3];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> n;
        if(n == 0) return 0;
        k++; //테스트케이스 번호
        for(int i=0; i<n; i++)
            for(int j=0; j<3; j++) cin >> graph[i][j];
        
        cost[0][0] = 1001;
        cost[0][1] = graph[0][1];
        cost[0][2] = graph[0][1] + graph[0][2];
        for(int i=1; i<n; i++) {
            cost[i][0] = min(cost[i-1][0], cost[i-1][1]) + graph[i][0];
            cost[i][1] = min({cost[i-1][0], cost[i-1][1], cost[i-1][2], cost[i][0]}) + graph[i][1];
            cost[i][2] = min({cost[i-1][1], cost[i-1][2], cost[i][1]}) + graph[i][2];
        }
        cout << k << ". " << cost[n-1][1] << "\n";
    }
    
    return 0;
}
