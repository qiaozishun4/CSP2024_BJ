#include <bits/stdc++.h>
using namespace std;

int T,n,m,k,x,y,d,cnt;
int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};
char c[1010][1010];
bool f[1010][1010];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> T;

    while(T--){
        cnt = 0;
        memset(f,0,sizeof(f));
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> c[i][j];
            }
        }
        f[x][y] = true;
        cnt++;
        while(k--){
            int tx = x + fx[d],ty = y + fy[d];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && c[tx][ty] == '.'){
                x = tx;
                y = ty;
            }else{
                d = (d + 1) % 4;
            }
            if(!f[x][y]){
                f[x][y] = true;
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
