#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int r[100005];
int aa[100005];
int a[100005],top = 0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int big = 0;
    for (int i = 1; i <=n; i++){
        cin >> r[i];
        big = max(big,r[i]);
        cnt[r[i]] ++;
        aa[i] = r[i];
    }
    sort(r+1,r+n+1);
    sort(aa+1,aa+n+1);
    for (int i = 1; i <= n; i++){
        if (r[i] != r[i-1]){
            a[top ++] = r[i];
        }
    }
    int ans = cnt[a[1]];
    for (int i = 2; i < top; i++){
        if (ans <= cnt[a[n]]){
            ans = cnt[a[n]];
        }
        else{
            ans = ans;
        }
    }

    if (ans <= cnt[a[n]]){
        cout << cnt[a[n]];
    }
    else{
        cout << ans;
    }
    return 0;
}
