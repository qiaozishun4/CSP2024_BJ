#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
bool f[1005][1005];
char mp[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool ins(int x,int y){
    if(x<1||x>n||y<1||y>m||mp[x][y]=='x')return 0;
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               cin>>mp[i][j];
               f[i][j]=0;
            }
        }
        f[x][y]=1;
        for(int i=1;i<=k;i++){
            if(ins(x+dx[d],y+dy[d])){
                x+=dx[d];
                y+=dy[d];
                f[x][y]=1;
            }
            else {
                d=(d+1)%4;
            }

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}