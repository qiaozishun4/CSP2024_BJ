#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 5;
int d[N],v[N],a[N],p[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;++j){
        int n,m,l,V,ans=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;++i){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;++i){
            cin>>p[i];
            if(p[i]>=a[i]&&v[i]>V)++ans;
        }
        cout<<ans<<' '<<m-1<<'\n';
    }
    return 0;
}
