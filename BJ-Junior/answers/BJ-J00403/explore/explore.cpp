#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int dir[4][2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    dir[0][0]=0;dir[0][1]=1;
    dir[1][0]=1;dir[1][1]=0;
    dir[2][0]=0;dir[2][1]=-1;
    dir[3][0]=-1;dir[3][1]=0;
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                vis[i][j]=0;
            }
        }
        pair<int,int> now=make_pair(x0,y0);
        int nd=d0,ans=0;
        while(k){
            if(mp[now.first][now.second]=='x'){
                break;
            }
            if(!vis[now.first][now.second]){
                ans++;
            }
            vis[now.first][now.second]=1;
            for(int j=0;j<4;j++){
                if(k==0){
                    break;
                }
                k--;
                int x1=now.first+dir[nd][0],y1=now.second+dir[nd][1];
                if(x1>0&&y1>0&&x1<=n&&y1<=m&&mp[x1][y1]=='.'){
                    now=make_pair(x1,y1);
                    break;
                }
                nd=(nd+1)%4;
            }
        }
        if(!vis[now.first][now.second]){
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
