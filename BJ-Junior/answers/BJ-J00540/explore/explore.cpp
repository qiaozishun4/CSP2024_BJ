#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
pair <int,int> p;
char y[N][N];
int n,m,ans,d,k;

bool go(int i,int j){
    if(i<=0||i>n||j<=0||j>m) return 0;
    return y[i][j]=='.';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    bool vis[N][N]={0};
    cin>>n>>m>>k;
    cin>>p.first>>p.second>>d;
    vis[p.first][p.second]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>y[i][j];
        }
    }

    int i=1;
        while(i<=k){
            if(d==0) {
                if(go(p.first,p.second+1)) p.second++,vis[p.first][p.second]=1;
                else d++;
                i++;
            }
            if(d==1) {
                if(go(p.first+1,p.second)) p.first++,vis[p.first][p.second]=1;
                else d++;
                i++;
            }
            if(d==2) {
                if(go(p.first,p.second-1)) p.second--,vis[p.first][p.second]=1;
                else d++;
                i++;
            }
            if(d==3) {
                if(go(p.first-1,p.second)) p.first--,vis[p.first][p.second]=1;
                else d=0;
                i++;
            }

        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(vis[i][j]) ans++;
    }
    cout<<ans<<'\n';
    ans=0;
    }

    return 0;
}
