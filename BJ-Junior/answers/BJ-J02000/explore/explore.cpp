#include <bits/stdc++.h>
using namespace std;
int t=0;
int n=0 , m=0 , k=0;
char mp[1000][1000]={ };
bool vis[1000][1000]={ };
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int geshu=1,step=0;
void dfs(int x , int y , int d,){
    if(step==k){
        cout<<geshu<<endl;
        return ;
    }
    step++;
    if(mp[x+dx[d]][y+dy[d]]!='x'&&x+dx[d]<n&&x+dx[d]>=0&&y+dy[d]<m&&y+dy[d]>=0&&vis[x+dx[d]][y+dy[d]]==0){
        geshu++;
        vis[x+dx[d]][y+dy[d]]=1;
        dfs((x+dx[d]),(y+dy[d]),d);
    }else{
        dfs(x,y,(d+1)%4);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0 ; i<t ; i++){
        cin>>n>>m>>k;
        int x_0=0,y_0=0,d_0=0;
        cin>>x_0>>y_0>>d_0;
        x_0-=1;
        y_0-=1;
        char mp[1000][1000]={ };
        bool vis[1000][1000]={ };
        int geshu=1,step=0;
        for(int j=0 ; j<n ; j++){
            for(int l=0 ; l<m ; l++){
                cin>>mp[j][l];
            }
        }
        vis[0][0]=1;
        dfs(x_0,y_0,d_0);
    }
    return 0 ;
}
