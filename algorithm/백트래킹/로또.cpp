#include <bits/stdc++.h>
using namespace std;

int n;
int num[50];
int arr[50];
int isused[50];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n;
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) cin >> num[i];
        for (int i = 0; i < n; i++) isused[i] = 1;
        for (int i = 0; i < 6; i++) isused[i] = 0;

        do {
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (isused[i] == 0) {
                    arr[k] = num[i];
                    k++;
                }
            }
            for (int i = 0; i < 6; i++) cout << arr[i] << " ";
            cout << "\n";
        } while (next_permutation(isused, isused + n));
        cout << "\n";
    }

    return 0;
}
