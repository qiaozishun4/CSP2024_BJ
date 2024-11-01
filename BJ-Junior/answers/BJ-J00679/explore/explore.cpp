#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,k,x,y,d,cnt;
char c[1005][1005];
bool v[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> c[i][j];
                v[i][j]=0;
            }
        }
        v[x][y]=1;
        cnt=1;
        while(k--){
            int nx,ny;
            if(d==0){
                nx=x;
                ny=y+1;
            }
            else if(d==1){
                nx=x+1;
                ny=y;
            }
            else if(d==2){
                nx=x;
                ny=y-1;
            }
            else{
                nx=x-1;
                ny=y;
            }
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && c[nx][ny]=='.'){
                x=nx;
                y=ny;
                if(!v[x][y]){
                    v[x][y]=1;
                    cnt++;
                }
            }
            else{
                d++;
                d%=4;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}