#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, cnt, tot;
int a[N];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i){
        ++cnt;
        if(a[i]^a[i-1]){
            tot -= min(tot, cnt);
            tot += cnt;
            cnt = 0;
        }
    }cout << tot;
    return 0;
}