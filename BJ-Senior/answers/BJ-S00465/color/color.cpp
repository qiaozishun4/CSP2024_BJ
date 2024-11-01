#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e13;
const int N=200001,A=1000001;
int n;
int a[N];
ll t,f[N],c[A];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        t=0;
        for(int i=1;i<A;i++)c[i]=-inf;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1)continue;
            f[i-1]=max(ans,c[a[i]]+a[i]);
            if(a[i]==a[i-1])t+=a[i],f[i-1]-=a[i];
            c[a[i-1]]=max(c[a[i-1]],f[i-1]);
            ans=max(ans,f[i-1]);
        }
        cout<<ans+t<<'\n';
    }
    return 0;
}
