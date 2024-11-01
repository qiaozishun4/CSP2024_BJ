#include<bits/stdc++.h>
using namespace std;
char a[2005][2005];
bool bi[2005][2005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
long long maxx=0;
long long n,m,q;
int tui=0;
void sou(long long x,long long y,long long f,long long b,long long ans){
    if(tui>=5){
        if(ans>maxx){
            maxx=ans;
        }
        return ;
    }
    if(bi[x][y]==0){
        ans++;
         bi[x][y]=1;
    }
    if(b==0){

        if(ans>maxx){
            maxx=ans;
        }
        return ;
    }
    int xx=x+dx[f];
    int yy=y+dy[f];
    b--;
    if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&a[xx][yy]=='.'){
        tui=0;
        sou(xx,yy,f,b,ans);
    }else {
        tui++;
        f=(f+1)%4;
        sou(x,y,f,b,ans);
    }
    bi[x][y]=0;
}
void ex(){
    maxx=0;
    cin>>n>>m>>q;
    long long x,y;
    int z;
    cin>>x>>y>>z;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            bi[i][j]=0;
        }
    }
    sou(x,y,z,q,0);
    cout<<maxx;
    cout<<endl;
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int re;
    cin>>re;
    for(int op=1;op<=re;op++){
        ex();
    }
    return 0;
}
