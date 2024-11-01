#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,cnt;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool s[1002][1002],vis[1002][1002];
bool ok(int a,int b){
    if(a>=1&&a<=n&&b>=1&&b<=m&&s[a][b]==true){
        return true;
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        cnt=0;
        scanf("%d %d %d\n%d %d %d",&n,&m,&k,&x,&y,&d);
        //printf("%d\n",k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            for(int j=0;j<str.length();j++){
                if(str[j]=='.'){
                    s[i][j+1]=true;
                    cnt++;
                }
                else{
                    s[i][j+1]=false;
                }
            }
        }
        int stp=0,nx=x,ny=y,nd=d;
        while(stp<=k&&ans<cnt){
            if(!vis[nx][ny]){
                ans++;
            }
            vis[nx][ny]=true;
            if(ok(nx+dx[nd],ny+dy[nd])){
                stp++;
                nx+=dx[nd];
                ny+=dy[nd];
            }
            else{
                stp++;
                nd=(nd+1)%4;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
