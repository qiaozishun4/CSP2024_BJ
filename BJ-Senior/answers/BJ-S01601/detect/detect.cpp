#include<bits/stdc++.h>
using namespace std;
#define int long long
//20 pts

const int N=1e5+5;
int a[N],d[N],p[N],v[N];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,n,m,L,V;
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;++i){
            cin>>p[i];
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            if(d[i]>p[m]) continue;
            if(v[i]>V) ++ans;
        }
        cout<<ans<<' '<<m-1<<endl;
    }
    return 0;
}

/*
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;
CSP-S 2024 RP++;

My luogu uid=1015780,QQ number=3544859511
*/
