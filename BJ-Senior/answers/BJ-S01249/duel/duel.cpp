#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

bool visgong[N], vissi[N];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, cnt = 0, cnt2 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        if(visgong[i]) continue;
        if(vissi[i]) continue;
        if(a[i + 1] > a[i]){
            vissi[i] = true;
            visgong[i + 1] = true;
            continue;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vissi[i]) cnt++;
    }
    cout << cnt - 1;
    return 0;
}
