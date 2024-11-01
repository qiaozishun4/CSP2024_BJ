#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int T,n,m,L,V,d,v,a,lo[N],p,p_,cnt,ans;
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cnt=0;
        p_=-1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d>>v>>a;
            if(d>L)continue;
            if(v>V){
                cnt++;
                lo[cnt]=d;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p;
            p_=max(p_,p);
            p_=min(L,p_);
        }
        ans=cnt;
        for(int i=1;i<=cnt;i++){
            if(lo[cnt]>p_)ans--;
        }
        if(ans!=0)cout<<ans<<" "<<m-1<<'\n';
        else cout<<ans<<" "<<m<<'\n';
    }
    return 0;
}
