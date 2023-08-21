#include <iostream>
using namespace std;

#define MAX 100001
int n, m, a, b, c, arr[100001];
long long tree[400001]; //더 작은 인덱스의 값을 저장하는 트리

int minIdx(int x, int y) { //더 작은 값의 인덱스를 반환
    if(x == -1) return y;
    if(y == -1) return x;
    if(arr[x] == arr[y]) return x < y ? x : y; //두 값이 같을 경우, 인덱스가 더 작은 값 반환
    else return arr[x] <= arr[y] ? x : y; //값이 더 작은 인덱스 반환
}

int init(int pos, int start, int end) { 
    if(start == end) return tree[pos] = start;
    int mid = (start + end) / 2;
    return tree[pos] = minIdx(init(2*pos, start, mid), init(2*pos+1, mid+1, end));
}

int update(int pos, int start, int end, int idx) {
    if(idx < start || idx > end) return tree[pos];
    if(start == end) return tree[pos];
    int mid = (start + end) / 2;
    return tree[pos] = minIdx(update(2*pos, start, mid, idx), update(2*pos+1, mid+1, end, idx));
}

int find(int pos, int start, int end, int left, int right) {
    if(left > end || right < start) return -1;
    if(left <= start && right >= end) return tree[pos];
    int mid = (start + end) / 2;
    return minIdx(find(2*pos, start, mid, left, right), find(2*pos+1, mid+1, end, left, right));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);
    cin >> m;
    while(m--) {
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update(1, 1, n, b);
        }
        else if(a == 2) { //인덱스 b~c중 가장 작은 값의 인덱스를 출력한다.
            //*low_element 사용 시, 시간초과
            cout << find(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}
