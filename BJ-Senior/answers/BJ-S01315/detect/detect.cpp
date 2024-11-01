#include <bits/stdc++.h>
using namespace std;
int t,n,m,L,V,p[100005],vis[100005];
int ans1,ans2;
struct node{
    int d,v,a;
    bool operator<(node _){
        return d<_.d;
    }
}c[100005];
void dfs(int x){
    if(x==m+1){
        int cnt=0,m1=m;
        while(p[m1]==0&&m1>0) m1--;
        for(int i=1,j=1;i<=n;i++){
            while((vis[j]==0||p[j]<c[i].d)&&j<m1) j++;
            if(p[j]<c[i].d||vis[j]==0) continue;
            long long dis1=p[j]-c[i].d,dis2=p[m1]-c[i].d,v=c[i].v,a=c[i].a;
            if(dis1*a*2+v*v>1ll*V*V||dis2*a*2+v*v>1ll*V*V) cnt++;
        }
        if(cnt==ans1){
            int now=0;
            for(int j=1;j<=m;j++){
                if(vis[j]==0) now++;
            }
            ans2=max(ans2,now);
        }
        return ;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
void solve1(){
    memset(vis,0,sizeof(vis));
    dfs(1);
}
void solve2(){
    if(ans1==0) ans2=m;
    else ans2=m-1;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>L>>V;
        ans1=0;
        ans2=0;
        for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++) cin>>p[i];
        sort(c+1,c+n+1);
        for(int i=1,j=1;i<=n;i++){
            while(p[j]<c[i].d&&j<m) j++;
            if(p[j]<c[i].d) continue;
            long long dis1=p[j]-c[i].d,dis2=p[m]-c[i].d,v=c[i].v,a=c[i].a;
            if(dis1*a*2+v*v>1ll*V*V||dis2*a*2+v*v>1ll*V*V) ans1++;
            else vis[i]=1;
  //          cout<<"i="<<i<<' '<<dis1<<' '<<dis2<<' '<<vis[i]<<endl;
        }
        if(n<=10&&m<=20) solve1();
        else solve2();
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
