#include <bits/stdc++.h>
using namespace std;

int a[100005];
int Next[100005], pre[100005];
int cnt[100005];
int cnt2[100005];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    //freopen("/home/csps/下载/CSP-S/duel/duel4.in", "r", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i] != a[i-1]){
            Next[a[i-1]] = a[i];
            pre[a[i]] = a[i-1];
        }
    }
    Next[a[n]] = -1;
    pre[a[1]] = -1;

    int res = 0;
    for(int i=Next[a[1]];i!=-1;i=Next[i]){
        res = max(res+cnt[pre[i]]-cnt[i], 0);
    }
    res+=(cnt[a[n]]);
    cout << res;
    return 0;
}