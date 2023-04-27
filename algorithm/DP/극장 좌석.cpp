#include <iostream>
#include <vector> 
using namespace std;

int n, m;
int seat[41];
bool vip[41];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int k;
        cin >> k;
        vip[k] = true; //이 자리는 vip 석임
    }
    seat[0] = 1; seat[1] = 1; 
    for(int i=2; i<=n; i++) {
        if(vip[i] || vip[i-1]) seat[i] = 1;
        else seat[i] = seat[i-1] + seat[i-2];        
    }
    int total = 1;
    for(int i=1; i<n; i++) 
        if(vip[i] == true) total *= seat[i-1];
    if(!vip[n]) total *= seat[n];
    else total *= seat[n-1];

    cout << total;
    
    return 0;
}
