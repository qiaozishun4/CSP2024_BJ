#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,d,cnt,a[1005][1005],dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool flag=0;
void dfs(int step){
    if(flag)return;
    if(step>k){
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]==2)cnt++;
        flag=1;
    }
    a[x][y]=2;
    for(int i=0;i<=3;i++){
        int dx=dxy[d][0],dy=dxy[d][1];
        x+=dx,y+=dy;
        if(1<=dx&&dx<=n&&1<=dy&&dy<=m&&a[x][y]==0)dfs(step+1);
        else d=(d+1)%4;
        x-=dx,y-=dy;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        char c;
        cnt=0,flag=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='x')a[i][j]=1;
                else a[i][j]=0;
            }
        dfs(1);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]==2)cnt++;
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
