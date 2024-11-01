#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
bool vis[N][N]={};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        long long x,y,x1,y1,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        long long cnt=1;
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0) x1=x,y1=y+1;
            else if(d==1) x1=x+1,y1=y;
            else if(d==2) x1=x,y1=y-1;
            else if(d==3) x1=x-1,y1=y;
            if(x1<1||y1<1||x1>n||y1>m||a[x1][y1]=='x'){
                d=(d+1)%4;
                continue;
            }
            x=x1;
            y=y1;
            if(vis[x][y]==0){
                cnt++;
                vis[x][y]=1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
