#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 11;
int a[MAXN];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, ans = 0, maxx = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        a[x]++;
        maxx = max(maxx, x);
    }
    int pre = 0;
    for(int i = 1; i <= maxx; ++i){
        if(a[i] == 0){
            continue;
        }
        if(a[i] >= pre){
            ans += pre;
            pre = a[i];
        }else{
            ans += a[i];
        }
    }
    cout << n - ans;
    return 0;
}
