#include <bits/stdc++.h>
using namespace std;
int n,a[500005],r[500005],cnt=0,maxn=0,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n; ans=n;
    for(int i=1;i<=n;i++){
            cin>>a[i]; r[a[i]]++; maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=maxn;i++){
        if(r[i]<=cnt) ans-=r[i];
        else{
            ans-=cnt; cnt=r[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
