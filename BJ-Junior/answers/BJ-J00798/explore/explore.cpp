#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM
int t,n,m,k,x,y,d,sum;
char a[6][MAXN][MAXN];
bool vis[6][MAXN][MAXN];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void work(){
    while(k--){
        int nx=x+dx[d],ny=y+dy[d];
        if(1<=nx and nx<=n and 1<=ny and ny<=m and a[t][nx][ny]!='x'){
            if(!vis[t][nx][ny])sum++;
            x=nx;y=ny;
            vis[t][x][y]=1;
        }else{
            d=(d+1)%4;
        }
    }
    cout<<sum<<endl;
    return ;
}
void init(){
    cin>>t;
    while(t--){
        sum=1;
        cin>>n>>m>>k>>x>>y>>d;
        vis[t][x][y]=1;
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            for(int j=1;j<=m;j++){
                a[t][i][j]=str[j-1];
            }
        }
        work();
    }
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    init();
    return 0;
}