#include <bits/stdc++.h>

using namespace std;
int T;
char a[1010][1010];
int n,m,k;
void dfs(int x,int y,int d,int kk){
    a[x][y]='0';
    if(kk==0){
        return;
    }
    int nx=x;
    int ny=y;
    if(d==0)ny++;
    if(d==1)nx++;
    if(d==2)ny--;
    if(d==3)nx--;
    if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&(a[nx][ny]=='.'||a[nx][ny]=='0')){
        dfs(nx,ny,d,kk-1);
    }
    else{
        dfs(x,y,(d+1)%4,kk-1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m>>k;
        int xx0,yy0,dd0;
        cin>>xx0>>yy0>>dd0;
        for(int ii=1;ii<=n;ii++){
            for(int jj=1;jj<=m;jj++){
                cin>>a[ii][jj];
            }
        }
        dfs(xx0,yy0,dd0,k);
        int sum=0;
        for(int ii=1;ii<=n;ii++){
            for(int jj=1;jj<=m;jj++){
                if(a[ii][jj]=='0')
                    sum++;
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

