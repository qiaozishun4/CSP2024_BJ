#include <bits/stdc++.h>
using namespace std;
bool vis[1009][1009]={0};
char dt[1009][1009];
int ax[10]={0,1,0,-1};
int ay[10]={1,0,-1,0};
void cl(){
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            vis[i][j]=0;
        }
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //next_permutation();
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cl();
        int n,m,k;
        int x,y,d;

        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dt[i][j];
            }

        }

        for(int i=1;i<=k;i++){
            int nx=x+ax[d];
            int ny=y+ay[d];
            vis[x][y]=1;
            if(nx>0 && nx<=n && ny>0 && ny<=m && dt[nx][ny]=='.'){
                x=nx;
                y=ny;
                vis[nx][ny]=1;
            }
            else{
                d=(d+1)%4;
            }

        }
        int s=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s+=vis[i][j];
            }
        }
        cout<<s<<endl;

    }

    return 0;
}
