#include <bits/stdc++.h>
using namespace std;
const int N=1e3+9;


char mp[N][N];
int t;
int dx[]={0,1,0,1};
int dy[]={1,0,-1,0};
int vis[N][N];
int n,m,sum,ans=1;



struct Node{
    int x,y,d;
}a;



void dfs(int sum){
    if(sum==0){
        cout<<ans<<endl;
        return;
    }
    a.d=a.d%4;
    int tx=a.x+dx[a.d];
    int ty=a.y+dy[a.d];
    if(tx<1||tx>n||ty<1||ty>m||mp[tx][ty]=='x'){
        a.d++;
        dfs(sum-1);
        return;
    }else{
        a.x=tx;
        a.y=ty;
        vis[a.x][a.y]++;
        if(vis[tx][ty]==1){
            ans++;
        }dfs(sum-1);
    }return;
}


int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=1;
        cin>>n>>m>>sum;
        cin>>a.x>>a.y>>a.d;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                mp[i][j+1]=s[j];
                vis[i][j+1]=0;
            }
        }

        vis[a.x][a.y]=1;
        dfs(sum);
    }fclose(stdin);
    fclose(stdout);

return 0;
}
