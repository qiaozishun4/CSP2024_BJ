#include <iostream>
using namespace std;
const int N = 1e3 + 5;
int n,m,k,x,y,d,ans,fx,fy;
char a[N][N];
bool v[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                v[i][j] = 0;
            }
        }
        ans = 1;
        v[x][y] = 1;
        for(int i=0;i<k;i++){
            if(d == 0)
                fx = x,fy = y+1;
            else if(d == 1)
                fx = x+1,fy = y;
            else if(d == 2)
                fx = x,fy = y-1;
            else if(d == 3)
                fx = x-1,fy = y;
            if(fx > 0 && fx <= n && fy > 0 && fy <= m && a[fx][fy] == '.')
                x = fx,y = fy;
            else
                d = (d+1)%4;
            if(v[x][y] == 0){
                v[x][y] = 1;
                ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
