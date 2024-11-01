#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int n,r[N],t[N],tt[N],vis1[N],vis2[N],ans,cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        if(t[r[i]]==0) tt[++cnt]=r[i];
        t[r[i]]++;
    }
    sort(r+1,r+n+1);
    ans=n;
    if(t[r[1]]==n) return cout<<ans,0;
    for(int i=2;i<=cnt;i++){
        ans-=(min(t[tt[i]],t[tt[i-1]]));
    }
    cout<<ans;
    return 0;
}
