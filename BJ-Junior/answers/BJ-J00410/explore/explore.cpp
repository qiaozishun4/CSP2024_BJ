#include<bits/stdc++.h>
using namespace std;
int vis[100][1005][1005],sum,t,n,m,k1,xr,yr,dr;
char e[1005][1005];
void dfs(int x,int y,int d,int k,int i)
{
    if(!vis[i][x][y]) { sum++; vis[i][x][y] = 1;}
    if(k == k1) return ;
    if(d == 0){
        if(((y+1) <= m) && (e[x][y+1] == '.'))dfs(x,y+1,d,k+1,i);
        else dfs(x,y,(d+1)%4,k+1,i);
    }
    if(d == 1){
        if(((x+1) <= n) && (e[x+1][y] == '.')) dfs(x+1,y,d,k+1,i);
        else dfs(x,y,(d+1)%4,k+1,i);
    }
    if(d == 2){
        if(((y-1) >= 1) && (e[x][y-1] == '.'))dfs(x,y-1,d,k+1,i);
        else dfs(x,y,(d+1)%4,k+1,i);
    }
    if(d == 3){
        if(((x-1) >= 1) && (e[x-1][y] == '.')) dfs(x-1,y,d,k+1,i);
        else dfs(x,y,(d+1)%4,k+1,i);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>t;
    int j = 0;
    while(t--){
        sum = 1;
        cin>>n>>m>>k1;
        cin>>xr>>yr>>dr;
        vis[j][xr][yr] = 1;
        for(int w = 1;w <= n;w++){
            for(int f = 1;f <= m;f++){
                cin>>e[w][f];
            }
        }
        dfs(xr,yr,dr,0,j);
        cout<<sum<<endl;
        j++;
    }
    return 0;
}
