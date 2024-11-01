#include<bits/stdc++.h>
using namespace std;
const  int N=1010;
bool v[N][N];
char a[N][N];
int t,n,m,k,d,x,y;
struct node{
    int fx,fy,fd;
};
void bfs(int x,int y,int cnt){
    queue<node> q;
    q.push({x,y,d});
    v[x][y]=1;
    cnt++;
    while(q.size()){
        node t=q.front();
        q.pop();
        if(k<=0){
            cout<<cnt<<endl;
            return;
        }
        if(t.fd==0){
            int xx=t.fx,yy=t.fy+1;
            if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&v[xx][yy]!=1&&a[xx][yy]!='x'){
                q.push({xx,yy,t.fd});
                v[xx][yy]=1;
                cnt++;
            }
            else{
                q.push({t.fx,t.fy,(t.fd+3)%4});
            }
        }
        if(t.fd==1){
            int xx=t.fx+1,yy=t.fy;
            if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&v[xx][yy]!=1&&a[xx][yy]!='x'){
                q.push({xx,yy,t.fd});
                v[xx][yy]=1;
                cnt++;
            }
            else{
                q.push({t.fx,t.fy,(t.fd+3)%4});
            }
        }
         if(t.fd==2){
            int xx=t.fx,yy=t.fy-1;
            if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&v[xx][yy]!=1&&a[xx][yy]!='x'){
                q.push({xx,yy,t.fd});
                v[xx][yy]=1;
                cnt++;
            }
            else{
                q.push({t.fx,t.fy,(t.fd+3)%4});
            }
        }
        if(t.fd==3){
            int xx=t.fx-1,yy=t.fy;
            if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&v[xx][yy]!=1&&a[xx][yy]!='x'){
                q.push({xx,yy,t.fd});
                v[xx][yy]=1;
                cnt++;
            }
            else{
                q.push({t.fx,t.fy,(t.fd+3)%4});
            }
        }
        k--;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int s=1;s<=m;s++){
                cin>>a[j][s];
            }
        }
        bfs(x,y,0);
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
    }
    return 0;
}
