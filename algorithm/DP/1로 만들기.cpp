/*  테이블 정의하기
    D[i]=i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
*/
/*  점화식 찾기
    D[12] = D[4]+ 1 / D[6] + 1 / D[11] + 1 중 최솟값
    D[k] = D[k/3] + 1 / D[k/2] + 1 / D[k-1] + 1 중 최솟값
*/
/*  초기값 정의하기
    D[1] = 0
*/

#include <bits/stdc++.h>
using namespace std;

int x;
int arr[1000005];
void func(int k)
{
    arr[1] = 0;
    for (int i = 2; i <= k; i++) {
        int m;
        if (i % 6 == 0) {
            m = min(arr[i / 3], arr[i / 2]);
            m = min(m, arr[i - 1]);
        }
        else if (i % 3 == 0) m = min(arr[i / 3], arr[i - 1]);
        else if (i % 2 == 0) m = min(arr[i / 2], arr[i - 1]);
        else m = arr[i - 1];
        arr[i] = m + 1;
    }
    cout << arr[k];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;
    func(x);

    return 0;
}   
