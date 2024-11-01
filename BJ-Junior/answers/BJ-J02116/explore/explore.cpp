#include<bits/stdc++.h>
using namespace std;
int mp[1005][1005];
int vis[1005][1005];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        int n,m,k;
        cin>>n>>m>>k;
        int sx,sy,d;
        cin>>sx>>sy>>d;
        int nx=sx,ny=sy;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            string s1='0'+s;
            for(int j=1;j<=m;j++){
                if(s1[j]=='.') mp[i][j]=0;
                else mp[i][j]=1;
            }
        }
        for(int i=1;i<=k;i++){
            vis[nx][ny]=1;
            bool flag=1;
            if(d==0){
                if(ny+1>m||mp[nx][ny+1]==1) flag=0;
            }
            if(d==1){
                if(nx+1>n||mp[nx+1][ny]==1) flag=0;
            }
            if(d==2){
                if(ny-1<1||mp[nx][ny-1]==1) flag=0;
            }
            if(d==3){
                if(nx-1<1||mp[nx-1][ny]==1) flag=0;
            }
            if(flag){
                if(d==0){
                    ny++;
                }
                if(d==1){
                    nx++;
                }
                if(d==2){
                    ny--;
                }
                if(d==3){
                    nx--;
                }

            }
            else{
                d=(d+1)%4;
            }
            vis[nx][ny]=1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
