#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[1005][1005]={};
long long ans=1,sum=0;
char c[1005][1005];
long long n,m,k;
long long x,y,d;
void dfs(long long x,long long y,long long d){
    vis[x][y]=1;
    sum++;
    int xx=x+dx[d];
    int yy=y+dy[d];
    if(sum==k){
        cout<<ans+1<<endl;
        return ;
    }

    //cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<" "<<d<<sum<<" "<<endl;
    if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy]==1||c[xx][yy]!='.'){
        d=(d+1)%4;
        //cout<<1;
        dfs(x,y,d);
    }else{
        ans++;
        dfs(xx,yy,d);
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin>>t;
    while(t!=0){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        if(k==1){
            if(d==0){
                if(c[x][y]+1=='.'){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
            }else if(d==1){
                if(c[x+1][y]=='.'){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
            }else if(d==2){
                if(c[x][y-1]=='.'){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
            }else{
                if(c[x-1][y]=='.'){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
            }
            continue;
        }
        dfs(x,y,d);
        memset(vis,0,sizeof vis);
        memset(c,' ',sizeof c);
        ans=1;
        sum=0;
        t--;
    }
    return 0;
}
