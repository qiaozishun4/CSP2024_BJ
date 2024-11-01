#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int d[100010],v[100010],a[100010],p[100010],f[100010];
vector<int> adj[100010];
int ff[100010];
int mn=1e9;
int n,m,L,V;
void dfs(int x,int y){
    if(y>mn)return;
    if(x>m){
        bool c=1;
        for(int i=1;i<=n;i++){
            if(f[i]&&!ff[i])c=0;
        }
        if(c)mn=min(mn,y);
        return;
    }
    for(int vx:adj[x]){
        ff[vx]++;
    }
    dfs(x+1,y+1);
    for(int vx:adj[x]){
        ff[vx]--;
    }
    dfs(x+1,y);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(f,0,sizeof f);
        memset(ff,0,sizeof ff);
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]<d[i])continue;
                double v1=sqrt(2*a[i]*(p[j]-d[i])+v[i]*v[i]);
                if(v1>V){
                    f[i]=1;
                    adj[j].push_back(i);
                }
            }
            if(f[i])cnt++;
        }
        cout<<cnt<<" ";
        mn=1e9;
        dfs(1,0);
        cout<<m-mn<<"\n";
        for(int i=1;i<=m;i++){
            adj[i].clear();
        }
    }
    return 0;
}
