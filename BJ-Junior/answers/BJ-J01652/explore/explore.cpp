#include<bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d,cnt;
int dx[]={0,1,0,-1};//r,d,l,u
int dy[]={1,0,-1,0};
char mp[1234][1234];
int vis[1234][1234];



void solve(){
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    cnt=1;
    vis[x][y]=1;
    //cout<<"pass:";
    while(k--){
        int tx=x+dx[d],ty=y+dy[d];
        if(tx<=n&&tx>=1&&ty<=m&&ty>=1&&mp[tx][ty]=='.'){
            x=tx,y=ty;
            if(vis[x][y]!=1){
                cnt++;
                vis[x][y]=1;
                //cout<<"("<<x<<","<<y<<"),";
            }
        }else{
            d=(d+1)%4;
        }
    }
    //cout<<"\n";
    cout<<cnt<<"\n";
}


int main(){
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    
    cin>>t;
    while(t--){
        solve();
    }

   fclose(stdin);
   fclose(stdout);
    return 0;
}
