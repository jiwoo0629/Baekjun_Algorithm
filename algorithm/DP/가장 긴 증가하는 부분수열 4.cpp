#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1005];
int len[1005];
int past[1005];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        len[i] = 1;
        past[i] = -1;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
                past[i] = j;
            }
        }
    }

    vector<int> v;
    int maxlen = *max_element(len, len+n);
    for(int i=0; i<n; i++) {
        if(len[i] == maxlen) {
            int cur = i;
            while(cur != -1) {
                v.push_back(arr[cur]);
                cur = past[cur];
            }
            sort(v.begin(), v.end());
            break;
        }
    }
    cout << v.size() << "\n";
    for(int j=0; j<v.size(); j++) cout << v[j] << " ";

    return 0;
}
