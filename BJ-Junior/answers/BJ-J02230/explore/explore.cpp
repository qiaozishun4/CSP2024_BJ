#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t,n,m,k,x,y,d,a=1,ans;
char c[N][N],f[10][N][N];
int dfs(int x,int y,int int step){

    if(step==k) return ans;
    if(x<1||x>n||y<1||y>n||c[x][y]=='x'){
        d=(d+1)%4;
        dfs(x,y,d,step++);
    }else if(f[a][x][y]!=1)ans++, f[a][x][y]=1;
    if(d==0) dfs(x,y+1,d,step++);
    if(d==1) dfs(x+1,y,d,step++);
    if(d==2) dfs(x,y-1,d,step++);
    if(d==3) dfs(x-1,y,d,step++);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >>t;
    for(a;a<=t;a++){
        cin >>n >>m >>k >>x >>y >>d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >>c[i][j];
        ans=0;
        int sum=dfs(x,y,d,0);
        cout <<sum <<endl;
    }
}
