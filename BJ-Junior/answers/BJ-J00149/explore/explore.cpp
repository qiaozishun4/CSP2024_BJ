#include <bits/stdc++.h>

using namespace std;
int t,n,m,k,x,y,grid[1005][1005],d,cnt,ans;
bool flag[1005][1005];
string c;
void dfs(int x,int y,int d){
    flag[x][y]=true;
    if(cnt==k)
        return;
    int x2,y2;
    if(d==0)     x2=x,y2=y+1;
    else if(d==1)    x2=x+1,y2=y;
    else if(d==2)    x2=x,y2=y-1;
    else if(d==3)    x2=x-1,y2=y;
    if(x2>=1 && x2<=n && y2>=1 && y2<=m){
        if(grid[x2][y2]!=-1){
            cnt++;
            dfs(x2,y2,d);
        }
        else{
            d=(d+1)%4;
            cnt++;
            dfs(x,y,d);
        }
    }
    else{
        d=(d+1)%4;
        cnt++;
        dfs(x,y,d);
    }

}
void qingkong(){
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            grid[i][j]=0;
            flag[i][j]=false;
        }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >>t;
    for(int i=1;i<=t;i++){
        cin >>n>>m>>k;
        cin>>x>>y>>d;

        for(int j=1;j<=n;j++){
            cin >>c;
            for(int yy=1;yy<=m;yy++){
                if(c[yy-1]=='x'){
                    grid[j][yy]=-1;
                }
            }
        }
        if(k==1){
            int x2,y2;
            if(d==0)     x2=x,y2=y+1;
            else if(d==1)    x2=x+1,y2=y;
            else if(d==2)    x2=x,y2=y-1;
            else if(d==3)    x2=x-1,y2=y;
            if(x2>=1 && x2<=n && y2>=1 && y2<=m && grid[x2][y2]!=-1)
                cout <<2<<endl;
            else
                cout <<1<<endl;
        }
        else{
        dfs(x,y,d);
        //check();
        for(int xx=1;xx<=n;xx++)
            for(int yy=1;yy<=m;yy++){
                if(flag[xx][yy]==true)
                    ans++;
            }
        cout <<ans<<endl;
        }
        ans=0;
        qingkong();
    }
    return 0;
}
