#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char ma[1005][1005];
bool vis[1005][1005];
void dfs(int step,int x,int y,int d,int maxstep){
    if(step==maxstep+2) return;
    if(vis[x][y]==0){
        cnt++;
    }
    vis[x][y]=1;
    int x1=x+dx[d],y1=y+dy[d];
    if(x1>=1&&x1<=n&&y1>=1&&y1<=m){
        if(ma[x1][y1]==0){
                //cout<<"X1:"<<x1<<"Y1:"<<y1<<"OK"<<"STEP"<<step<<"D"<<d<<endl;
                return dfs(step+1,x1,y1,d,maxstep);
        }else{
            //cout<<"X1:"<<x1<<"Y1:"<<y1<<"NOK(X)"<<"STEP"<<step<<"D"<<d<<endl;
            return dfs(step+1,x,y,(d+1)%4,maxstep);
        }
    }else{
        //cout<<"X1:"<<x1<<"Y1:"<<y1<<"NOK(OUT)"<<"STEP"<<step<<"D"<<d<<endl;
        return dfs(step+1,x,y,(d+1)%4,maxstep);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int ma[1005][1005]={};
        int k,x,y,d;
        cnt=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                if(s[j]=='.') ma[i][j]=0;
                else ma[i][j]=1;
            }
        }
        dfs(1,x,y,d,k);
        cout<<cnt<<endl;
    }
    return 0;
}
