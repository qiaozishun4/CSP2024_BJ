#include <bits/stdc++.h>
using namespace std;
int t,n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
string mmap[1005];
bool flag[1005][1005],check;
void dfs(int x,int y,int d,int step,int ans){
    if(x<1||x>n||y<0||y>m-1||mmap[x][y]=='x'||check==1) return;
    if(step==0){
        cout<<ans<<endl;
        check=1;
        return;
    }
    int tmpx=x+dx[d];
    int tmpy=y+dy[d];
    if(tmpx>=1&&tmpx<=n&&tmpy>=0&&tmpy<=m-1&&mmap[tmpx][tmpy]!='x'){
        if(flag[tmpx][tmpy]==0){
            flag[tmpx][tmpy]=1;
            dfs(tmpx,tmpy,d,step-1,ans+1);
        }
        else dfs(tmpx,tmpy,d,step-1,ans);
    }
    else dfs(x,y,(d+1)%4,step-1,ans);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t){
        check=0;
        int k,x0,y0,d0;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            cin>>mmap[i];
            for(int j=0;j<=m-1;j++){
                flag[i][j]=0;
            }
        }
        flag[x0][y0-1]=1;
        dfs(x0,y0-1,d0,k,1);
        t--;
    }
    return 0;
}