#include <bits/stdc++.h>
using namespace std;
int t;
int f[1005][1005];
string s[1005];
int n,m,k,cnt=1,f1,a,b,c;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
void dfs(int x,int y,int d,int cs){
    if(cs==0){
        f1=1;
        return ;
    }
    if(f1)return;
    int xx=x+dx[d];
    int yy=y+dy[d];
    if(xx<=n&&xx>=1&&yy>=1&&yy<=m&&s[xx][yy]=='.'){
        if(f[xx][yy]==0){
            f[xx][yy]=1;
            cnt++;
        }
        dfs(xx,yy,d,cs-1);
    }else{
        dfs(x,y,(d+1)%4,cs-1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>n>>m>>k>>a>>b>>c;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            s[i]=' '+s[i];
        }
        f[a][b]=1;
        dfs(a,b,c,k);
        cout<<cnt<<endl;
        cnt=1;
        f1=0;
        memset(f,0,sizeof(f));
    }
    return 0;
}
