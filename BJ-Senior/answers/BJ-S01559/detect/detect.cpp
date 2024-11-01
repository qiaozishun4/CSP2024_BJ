#include <bits/stdc++.h>
using namespace std;
const int N = 114514,M=1e6+6;
int T;
long long f2(int v0,int a0,int s){
    return ceil(sqrt(v0*v0+2*a0*s));
}
struct nd{int d,v,a;}dva[N];
struct nnd{int pp;}p[N];
struct ndd{long long sp;}ps[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,L,V,ans1,ans2,vis1[N],vis2[24][24];
        cin>>n>>m>>L>>V;
        //int d[N],v[N],a[N];
        //int dva[N][4];
        //int p[N];
        int t[M];
        bool flag[N];
        //long long ps[M];
        for(int i=1;i<=n;i++){
            cin>>dva[i].d>>dva[i].v>>dva[i].a;
            flag[i]=1;
        }
        for(int i=1;i<=m;i++) cin>>p[i].pp,t[p[i].pp]++;
        /*
        for(int i=1;i<=m;i++){
            memset(p,-1,sizeof -1);
            for(int j=1;j<=n;j++){
                if(dva[j].d>=p[i].pp){
                    ps[i].sp=max(ps[i].sp,f2(dva[j].v,dva[j].a,p[i].pp));
                }
            }
            if(ps[i].sp>V) flag[i]=0,ans1++;
        }

        for(int i=1;i<=m;i++){
            for(int i=1;i<=n;i++)
        }
        */
        if(n<=20){
            memset(vis1,0,sizeof vis1);
            memset(vis2,0,sizeof vis2);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(/*()&&*/dva[i].d>=p[i].pp&&f2(dva[i].v,dva[i].a,p[j].pp)>V) vis1[i]++,vis2[i][j]++;
                }
                if(vis1[i]) ans1++;
            }
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(vis2[j][i]-1==0&&vis1[i]==0){flag[i]=0;break;}
                }
            }
            for(int i=1;i<=m;i++){
                if(flag[i]) ans2++;
            }
            cout<<ans1<<' '<<ans2<<'\n';
        }

    }
    return 0;
}
