// #define debug
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+3 ;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int t,n,m,k,x,y,d,res;
char mp[N][N];
bool vis[N][N];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        res=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                vis[i][j]=false;
            }
        }
        vis[x][y]=true;
        while(k--){
            #ifdef debug
            cout<<x<<"-"<<y<<" "<<d<<endl;
            #endif
            int nx=x+dx[d],ny=y+dy[d];
            #ifdef debug
            cout<<nx<<"-"<<ny<<endl;
            #endif
            if(nx>0 && nx<=n && ny>0 && ny<=m && mp[nx][ny]=='.'){
                x=nx;
                y=ny;
                if(!vis[x][y]){
                    res++;
                    vis[x][y]=true;
                }
            }else{
                d++;
                if(d==4){
                    d=0;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}