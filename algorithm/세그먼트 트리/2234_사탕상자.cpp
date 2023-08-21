#include <iostream>
using namespace std;

int n, a, b, c;
long long candy[4000010]; //1(높은 가중치) ~ 1000000(낮은 가중치) 
// 맛의 종류가 최대 100만개이므로, 가능한 사탕의 종류도 최대 100만개
// 누적합 => 최대 10만번의 빈번한 삽입/삭제 => 세그먼트 트리로 구현 가능

void update(int pos, int start, int end, int idx, int num) {
    if(idx < start || idx > end) return;
    candy[pos] += num;
    int mid = (start + end) / 2;
    if(start != end) {
        update(2 * pos, start, mid, idx, num);
        update(2 * pos + 1, mid + 1, end, idx, num);
    }
}

int find(int pos, int start, int end, int num) {
    candy[pos]--; //하나 빼주는 이유?? => 
    //이 방향으로 이동했으면, 적어도 그쪽에서 사탕 하나는 없어질 것이기 때문에 1 빼준다.
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(candy[2 * pos] >= num)
        return find(2 * pos, start, mid, num);
    num -= candy[2 * pos];
    if(candy[2 * pos + 1] >= num)
        return find(2 * pos + 1, mid + 1, end, num);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> a;
        if(a == 1) { //순위가 b인 사탕 1개를 빼는 경우
            cin >> b;
            cout << find(1, 1, 1000000, b) << "\n";
        }
        else if(a == 2) { //맛이 b인 사탕을 c개 넣거나 빼는 경우
            cin >> b >> c;
            update(1, 1, 1000000, b, c);
        }
    }
    //2억 / 10만 => 1회당 2000번?? 안에 끝내야 한다.
    return 0;
}
