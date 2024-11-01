#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=3005;
long long T,n,m,l,V;
long long f[M][M],d[N],v[N],a[N],p[N],flag[N];
bool vis[N];
int ans;
bool check(){
    for(int i=1;i<=n;i++){
        if(flag[i]&&vis[i]==0)return false;
    }
    return true;
}
void dfs(int x,int an){
    if(x==m+1){
        if(check())ans=min(ans,an);
        return;
    }
    dfs(x+1,an);
    int viss[N]={};
    for(int i=1;i<=n;i++){
        viss[i]=vis[i];
        if(f[i][x])vis[i]=1;
    }
    dfs(x+1,an+1);
    for(int i=1;i<=n;i++){
        vis[i]=viss[i];
    }
}
void work1(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                long long s=p[j]-d[i];
                if(s<0){
                    f[i][j]=0;
                    continue;
                }
                long long v_2=v[i]*v[i]+2*a[i]*s;
                if(v_2<0){
                    f[i][j]=0;
                    continue;
                }
                if(v_2>V*V)f[i][j]=1,flag[i]=1;
                else f[i][j]=0;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)if(flag[i]==1)cnt++;
        ans=cnt;
        dfs(1,0);
        cout<<cnt<<" "<<m-ans<<endl;
}
void work2(){
        long long p_max=0;
        for(int i=1;i<=m;i++)p_max=max(p_max,p[i]);
        for(int i=1;i<=n;i++){
            if(v[i]>V&&d[i]<=p_max)flag[i]=1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)if(flag[i]==1)cnt++;
        if(cnt==0)ans=0;else ans=1;
        cout<<cnt<<" "<<m-ans<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>V;
        memset(vis,0,sizeof(vis));
        memset(f,0,sizeof(f));
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(n<=20&&m<=20)work1();
        else work2();
    }
    return 0;
}
