#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,l,v;
struct node{
    int d,v,a;
    void read(){cin>>d>>v>>a;}
}c[N];
int p[N];
void solve(){
    for(int i=1;i<=n;i++)c[i].read();
    int maxn=INT_MIN;
    for(int i=1;i<=m;i++)cin>>p[i],maxn=max(maxn,p[i]);
    int ans=n;
    for(int i=1;i<=n;i++){
        if(c[i].d>maxn||c[i].v<=v)ans--;
    }
    cout<<ans<<" ";
    if(ans!=0)cout<<m-1<<"\n";
    else cout<<m<<"\n";
}
#define debug cout<<"ans"<<ans<<"\n";for(int i=1;i<=n;i++)cout<<flag[i]<<" ";cout<<"\n"
namespace work{
    const int M=50;
    vector<int>fast[M];int ans=0,cnt=0;
    bool flag[M],vis[M];int sum[M];
    void dfs(int step){
        if(step>=m){
            flag[step]=1;ans++;
            for(int j=1;j<=n;j++){
                for(auto i:fast[j]){
                    if(i==step){sum[j]--;break;}
                }
            }
            bool fla=1;
            for(int i=1;i<=n;i++){
                if(vis[i]&&sum[i]<=0)fla=0;
            }
            if(fla)cnt=max(cnt,ans);
            flag[step]=0;ans--;
            for(int j=1;j<=n;j++){
                for(auto i:fast[j]){
                    if(i==step){sum[j]++;break;}
                }
            }
            fla=1;
            for(int i=1;i<=n;i++){
                if(vis[i]&&sum[i]<=0)fla=0;
            }
            if(fla)cnt=max(cnt,ans);
            return ;
        }
        flag[step]=1;ans++;
        for(int j=1;j<=n;j++){
            for(auto i:fast[j]){
                if(i==step){sum[j]--;break;}
            }
        }
        dfs(step+1);
        flag[step]=0;ans--;
        for(int j=1;j<=n;j++){
            for(auto i:fast[j]){
                if(i==step){sum[j]++;break;}
            }
        }
        dfs(step+1);
    }
    void solve(){
        for(int i=1;i<M;i++)fast[i].clear();
        memset(flag,0,sizeof flag);
        memset(sum,0,sizeof sum);
        memset(vis,0,sizeof vis);
        ans=0,cnt=0;
        for(int i=1;i<=n;i++)c[i].read();
        for(int i=1;i<=m;i++)cin>>p[i];
        int ccnt=0;
        for(int i=1;i<=n;i++){
            int fla=0;
            for(int j=1;j<=m;j++){
                if(c[i].d>p[j])continue;
                int vv=c[i].v*c[i].v+2*c[i].a*(p[j]-c[i].d);
                if(vv>v*v)fla=1,vis[i]=1,fast[i].push_back(j),sum[i]++;
            }
            ccnt+=fla;
        }
        cout<<ccnt<<" ";
        dfs(1);cout<<cnt<<"\n";
    }
}

signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        if(n<=20&&m<=20)work::solve();
        else solve();
    }
    return 0;
}
