#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
char mp[N][N];
int t,n,m,k,x,y,d;
int d2[4][2]={0,1,1,0,0,-1,-1,0};
struct node{
    int x,y,step,lun;
};
int dfs(){
    queue<node> q;
    set<pair<int,int> > l;
    l.insert(make_pair(x,y));
    q.push({x,y,0,0});
    while(!q.empty()){
        node u=q.front();
        q.pop();
        if(u.step==4){
            continue;
        }
        if(u.lun==k){
            return l.size();
        }
        int nx=u.x+d2[d][0];
        int ny=u.y+d2[d][1];
        if(nx<=0 || ny<=0 || nx>n || ny>m || mp[nx][ny]=='x'){
            d=(d+1)%4;
            q.push({u.x,u.y,u.step+1,u.lun+1});
            continue;
        }
        l.insert(make_pair(nx,ny));
        q.push({nx,ny,0,u.lun+1});
    }
    return l.size();
}
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        //memset(vis,0,sizeof vis);
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        cout<<dfs()<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
