#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char mapp[1005][1005];
int memo [1005][1005];
int T;
int n,m,k;
int x,y,d;
bool check(int x,int y){
    if(x<1 || x>n || y<1 || y>m || mapp[x][y]=='x'){
            return false;
    }
    return true;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int ans = 1;


        cin>>n>>m>>k;
        cin>>x>>y>>d;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mapp[i][j];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                memo[i][j] = 0;
            }
        }

        memo[x][y] = 1;
        for(int i=1;i<=k;i++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(check(nx,ny)){
                x=nx;
                y=ny;
                if(memo[x][y]==0)ans++;
                memo[x][y] = 1;
            }else{
                d=(d+1)%4;
            }


        }
    cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
