#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
struct node{
    int x,y,d,step;
};
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},mp[MAX][MAX],stp[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,x0,y0,d0;
        cin>>n>>m>>k>>x0>>y0>>d0;
        char a[MAX][MAX];
        memset(stp,0,sizeof(stp));
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>a[i][j];
        }
        queue<node>q;
        q.push({x0,y0,d0,0});
        while(!q.empty()){
            node now=q.front();
            q.pop();
            int x=now.x,y=now.y,d=now.d,step=now.step;
            if(x>n||x<1||y>m||y<1||a[x][y]=='x'||stp[step])continue;
            mp[x][y]=1;
            stp[step]=1;
            //cout<<x<<' '<<y<<' '<<d<<' '<<step<<endl;
            if(step==k)break;
            q.push({x+dx[d],y+dy[d],d,step+1});
            q.push({x,y,(d+1)%4,step+1});
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
