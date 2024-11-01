#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,v,p[200000],ans,ans1;
struct car{
    int d,v,a;
}c[200000];
bool vis[200000];
void dfs(int x,int cnt){
    if(x==m+1){
        int res=0;
        for(int i=1;i<=n;i++){
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[j]==0) continue;
                if(p[j]<c[i].d) continue;
                double nowv=sqrt(1.0*c[i].v*c[i].v+2.0*c[i].a*(p[j]-c[i].d));
                if(nowv>v){
                    res++;
                    cout<<i<<endl;
                    break;
                }
            }
        }
        cout<<endl<<endl<<endl<<endl;
        if(res==ans){
            ans1=max(ans1,cnt);
        }
        return;
    }
    vis[x]=0;
    dfs(x+1,cnt+1);
    vis[x]=1;
    dfs(x+1,cnt);
    return;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        bool flag1=1,flag2=1;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a!=0){
                flag1=0;
            }
            if(c[i].a<=0){
                flag2=0;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        ans=0;
        ans1=0;
        sort(p+1,p+m+1);
        if(flag1){
            for(int i=1;i<=n;i++){
                if(c[i].d<=p[m] && c[i].v>v){
                    ans++;
                }
            }
            cout<<ans<<" "<<m-1<<endl;
            continue;
        }else if(flag2){
            for(int i=1;i<=n;i++){
                if(c[i].d>p[m]){
                    continue;
                }
                double nowv=sqrt(1.0*c[i].v*c[i].v+2.0*c[i].a*(p[m]-c[i].d));
                if(nowv>v){
                    ans++;
                }
            }
            cout<<ans<<" "<<m-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]<c[i].d) continue;
                double nowv=sqrt(1.0*c[i].v*c[i].v+2.0*c[i].a*(p[j]-c[i].d));
                if(nowv>v){
                    ans++;
                    cout<<i<<endl;
                    break;
                }
            }
        }
        dfs(1,0);
        cout<<ans<<" "<<ans1<<endl;
    }
    return 0;
}

