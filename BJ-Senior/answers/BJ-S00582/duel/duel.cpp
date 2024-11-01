#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;
int n,a[MAXN],x,mi=1<<30,ans=0,v,ma=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>v;
        a[v]++;
        mi=min(mi,v);
        ma=max(ma,v);
    }
    for(int i=mi;i<=ma;i++){
        ans-=min(a[i],x);
        x=max(a[i],x);
    }
    cout<<ans<<endl;
    return 0;
}
