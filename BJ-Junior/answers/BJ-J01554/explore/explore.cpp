#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char mp[N][N];
bool vis[N][N];
int n,m,k;
int x,y,d;
void move(){
    int x1,y1;
    if(d==0) x1=x,y1=y+1;
    if(d==1) x1=x+1,y1=y;
    if(d==2) x1=x,y1=y-1;
    if(d==3) x1=x-1,y1=y;
    if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&mp[x1][y1]!='x'){
        x=x1,y=y1;
        return;
    }
    else{
        d=(d+1)%4;
        return;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(vis,false,sizeof vis);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=m;j++){
                mp[i][j]=s[j-1];
            }
        }
        vis[x][y]=true;
        while(k--){
            move();
            vis[x][y]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
