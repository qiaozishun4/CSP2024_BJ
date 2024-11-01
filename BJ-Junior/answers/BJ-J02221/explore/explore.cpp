#include<bits/stdc++.h>
using namespace std;
int dicx[4]={0,1,0,-1};
int dicy[4]={1,0,-1,0};
void calc(){
    char a[1020][1020];
    int n,m,k;
    cin>>n>>m>>k;
    int xx0,yy0,dd0;
    cin>>xx0>>yy0>>dd0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    int cnt=1;
    a[xx0][yy0]='#';
    for(int step=1;step<=k;step++){
        int nx,ny;
        nx=xx0+dicx[dd0];
        ny=yy0+dicy[dd0];
        if(a[nx][ny]=='x' || nx>n || ny>m || nx<1 || ny<1){
            dd0=(dd0+1)%4;
            continue;
        }
        xx0=nx,yy0=ny;
        if(a[nx][ny]=='.'){
            a[nx][ny]='#';
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        calc();
    }
    return 0;
}