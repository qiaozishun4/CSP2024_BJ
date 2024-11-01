#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,cnt;
bool f[1010][1010];
char c[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        memset(f,0,sizeof f);
        cin >> n >> m >> k>>x>>y>>d;
        for(int i = 1;i <= n;i++){
            for (int j = 1;j <=m;j++){
                cin >> c[i][j];
            }
        }
        f[x][y]=1;
        cnt=1;
        while(k--){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m||c[nx][ny]!='.'){
                d=(d+1)%4;
            }
            else{
                x=nx;
                y=ny;
                if(!f[x][y]){
                    cnt++;
                    f[x][y]=1;
                }
            }
        }
        cout << cnt<<endl;
    }
    return 0;
}
