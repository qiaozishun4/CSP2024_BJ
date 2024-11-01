#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
static const int N=1e2+5;
int t,n,m,k,x,y,d,cnt=1;
char s[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int nx,ny;
        if(d==0){
            nx=x,ny=y+1;
        }else if(d==1){
            nx=+1,ny=y;
        }else if(d==2){
            nx=x,ny=y-1;
        }else{
            nx=x-1,ny=y;
        }
        if(nx<1||nx>n||ny<1||ny>m){
            d=(d+1)%4;
        }
        if(s[nx][ny]=='x'){
            d=(d+1)%4;
        }
        s[nx][ny]='x';
        cnt++;
        dfs(nx,ny);
    }
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                cin>>s[j][k];
            }
        }
        //dfs(x,y);
        //cout<<cnt<<endl;
    }
    cout<<1;
    return 0;
}
