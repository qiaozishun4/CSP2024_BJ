#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,ans,m;
int t[N],s[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        t[x]++;
        m=max(m,x);
    }
    ans=t[1];
    for(int i=2;i<=m;i++){

        ans-=min(ans,t[i]);
        ans+=t[i];
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
