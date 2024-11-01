#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int r[N],f[N],n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        f[r[i]]++;
    }
    sort(r+1,r+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i!=1&&r[i]==r[i-1])continue;
        //cout<<f[r[i]]<<" ";
        ans=max((f[r[i-1]]-f[r[i]])+ans,0);
    }
    ans+=f[r[n]];
    cout<<ans<<endl;
    return 0;
}
