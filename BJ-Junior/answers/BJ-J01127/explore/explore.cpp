#include <bits/stdc++.h>
using namespace std;
const int dx[5]={0,1,0,-1};
const int dy[5]={1,0,-1,0};
int n,m,k,x,y,d,T,dp;
char ma[1003][1003];
int v[1003][1003];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        int cnt=0;
        memset(v,0,sizeof(v));
        v[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ma[i][j];
            }
        }
        while(k--){
            int xx=x+dx[d],yy=y+dy[d];
            if(xx<1||xx>n||yy<1||yy>m||ma[xx][yy]=='x'){
                d=(d+1)%4;
            }
            else{
                x=xx;y=yy;
                v[xx][yy]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j]==1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
