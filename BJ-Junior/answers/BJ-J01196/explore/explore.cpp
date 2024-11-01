#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
bool a[N][N],flag[N][N];
void solve(){
    memset(a,0,sizeof a);
    memset(flag,0,sizeof flag);
    int n,m,k;cin>>n>>m>>k;
    int x,y,d;cin>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char b;cin>>b;
            if(b=='.')a[i][j]=1;
            else a[i][j]=0;
        }
    }
    flag[x][y]=1;int cnt=1;
    while(k--){
        if(d==0){
            if(!a[x][y+1]){d=(d+1)%4;continue;}
            y++;if(!flag[x][y])flag[x][y]=1,cnt++;
            continue;
        }
        if(d==1){
            if(!a[x+1][y]){d=(d+1)%4;continue;}
            x++;if(!flag[x][y])flag[x][y]=1,cnt++;
            continue;
        }
        if(d==2){
            if(!a[x][y-1]){d=(d+1)%4;continue;}
            y--;if(!flag[x][y])flag[x][y]=1,cnt++;
            continue;
        }
        if(d==3){
            if(!a[x-1][y]){d=(d+1)%4;continue;}
            x--;if(!flag[x][y])flag[x][y]=1,cnt++;
            continue;
        }
    }
    cout<<cnt<<"\n";
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
