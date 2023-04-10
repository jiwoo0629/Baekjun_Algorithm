#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[100005];
bool vis[100005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(n == k) {
        cout << 0 << "\n";
        cout << n;
        return 0;
    }
    fill(arr, arr+100005, -1);
    queue<int> q;
    vis[n] = true;
    q.push(n);
    
    while(!vis[k]) {
        int cur = q.front();
        q.pop();
        if(cur == 0) {
            if(!vis[cur+1]) {
                vis[cur+1] = true;
                arr[cur+1] = cur;
                q.push(cur+1);
            }
        }
        else if(cur == 100000) {
            if(!vis[cur-1]) {
                vis[cur-1] = true;
                arr[cur-1] = cur;
                q.push(cur-1);
            }
        }
        else if(cur > 50000) {
            if(!vis[cur-1]) {
                vis[cur-1] = true;
                arr[cur-1] = cur;
                q.push(cur-1);
            }
            if(!vis[cur+1]) {
                vis[cur+1] = true;
                arr[cur+1] = cur;
                q.push(cur+1);
            }
        }
        else {
            if(!vis[cur-1]) {
                vis[cur-1] = true;
                arr[cur-1] = cur;
                q.push(cur-1);
            }
            if(!vis[cur+1]) {
                vis[cur+1] = true;
                arr[cur+1] = cur;
                q.push(cur+1);
            }
            if(!vis[cur*2]) {
                vis[cur*2] = true;
                arr[cur*2] = cur;
                q.push(cur*2);
            }
        }
    }

    vector<int> v;
    int cur = k;
    v.push_back(k);
    while(arr[cur] != -1) {
        cur = arr[cur];
        v.push_back(cur);
    }
    cout << v.size() - 1 << "\n";
    for(int i=v.size()-1; i>-1; i--) cout << v[i] << " "; 
    
    return 0;
}
