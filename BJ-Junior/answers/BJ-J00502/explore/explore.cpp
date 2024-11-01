#include <iostream>
using namespace std;

int t;
int n,m,k;
int x,y,d;
char c;
int a[1111][1111];
int b[1111][1111];
int ans;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int q = 1;q <= t;q++){
    //
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        b[x][y] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> c;
                if(c == '.')a[i][j] = 1;
            }
        }
        for(int i = 1;i <= k;i++){
            if(d == 0){
                if(a[x][y + 1] == 1)y = y + 1;
                else d = 1;
            }
            else if(d == 1){
                if(a[x + 1][y] == 1)x = x + 1;
                else d = 2;
            }
            else if(d == 2){
                if(a[x][y - 1] == 1)y = y - 1;
                else d = 3;
            }
            else if(d == 3){
                if(a[x - 1][y] == 1)x = x - 1;
                else d = 0;
            }
            b[x][y] = 1;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(b[i][j] == 1){
                        ans++;
                }
            }
        }
        cout << ans << endl;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                a[i][j] = 0;
                b[i][j] = 0;
            }
        }
        ans = 0;
     //
    }


     return 0;
}
