#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> input[500005]; //뛰는 순서, 선수의 능력
int tree[2000005];
//1초 = 1억번 => 50만번 * 200번

void update(int pos, int start, int end, int val) {
    if(val < start || val > end) return;
    tree[pos]++;
    if(start != end) {
        int mid = (start + end) / 2;
        update(2 * pos, start, mid, val);
        update(2 * pos + 1, mid + 1, end, val);
    }
}

int find(int pos, int start, int end, int val) {
    if(val > end) return tree[pos];
    if(start == end || val < start) return 0;
    int mid = (start + end) / 2;
    return find(2 * pos, start, mid, val) + find(2 * pos + 1, mid + 1, end, val);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) { //50만번 * 200
        int num;
        cin >> num;
        input[i] = {i, num}; //뛰는 순서, 선수의 능력
    }
    sort(input+1, input+n+1, cmp); //능력이 낮은 순으로 정렬
    for(int i=1; i<=n; i++) input[i].second = i; //능력을 1~n으로 변환
    sort(input+1, input+n+1); //입력받은 순으로 재정렬    
    
    for(int i=1; i<=n; i++) {
        cout << i - find(1, 1, n, input[i].second) << "\n";
        update(1, 1, n, input[i].second);
    }

    return 0;
}
