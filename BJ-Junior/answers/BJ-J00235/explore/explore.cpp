#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
const int N = 1e3 + 5;
const int MOD = 4;
int n, m, k;
char c[N][N];
int d, x, y;
bool flag[N][N];
void soloved() {
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for(int i = 0; i <= max(n, m); i ++)
        c[0][i] = c[i][0] =  c[n+1][i] = c[i][m + 1] = '0';
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m ; j ++) {
            cin >> c[i][j];
        }
    }
//    for(int i = 0; i <= n+1; i ++) {
//        for(int j = 0; j <= m + 1; j ++) {
 //           cout << c[i][j] << ' ';
 //       }
//        cout<<endl;
 //   }
//    d = 0 代表向东,d = 1 代表向南,d = 2 代表向西,d = 3 代表向北。
    int cnt = 1;
    flag[x][y] = true;
    while(k --) {
        switch(d) {
        case 0:
            if(c[x][y + 1] != '0' && c[x][y + 1] != 'x') {
                y++;
                if(!flag[x][y]){
                    cnt++;
 //                   cout<<'*';
                }
                flag[x][y] = true;
//                cout<<0<<' ';
            }
            else d = (d + 1) % MOD;
            break;

        case 1:
            if(c[x + 1][y] != '0' && c[x + 1][y] != 'x') {
                x++;
                if(!flag[x][y]){
                    cnt++;
 //                   cout<<'*';
                }

                flag[x][y] = true;
//                cout<<1<<" ";
            }
            else d = (d + 1) % MOD;
            break;
        case 2:
            if(c[x][y - 1] != '0' && c[x][y - 1] != 'x') {
                y--;
                if(!flag[x][y]){
                    cnt++;
 //                   cout<<'*';
                }
                flag[x][y] = true;
//                cout<<2<<' ';
            }
            else d = (d + 1) % MOD;
            break;
        case 3:
            if(c[x - 1][y] != '0' && c[x - 1][y] != 'x') {
                x--;
                if(!flag[x][y]){
                    cnt++;
//                    cout<<'*';
                }
                flag[x][y] = true;
//                cout<<3<<' ';
            }
            else d = (d + 1) % MOD;
            break;
        }
//        若 d = 0,则令 (x ′ , y ′ ) = (x, y + 1),
//        若 d = 1,则令(x ′ , y ′ ) = (x + 1, y),
//        若 d = 2,则令 (x ′ , y ′ ) = (x, y − 1),
//        若 d = 3,则令(x ′ , y ′ ) = (x − 1, y)。
    }
    cout << cnt << endl;
    for(int i = 0; i <= n; i ++)
        for(int j = 0 ; j <= m; j ++)
        flag[i][j] = false;
        return ;
}
int main() {
      freopen("explore.in", "r", stdin);
      freopen("explore.out", "w", stdout);
//    ios_sync_with_stdio(false);
//    cin.tie;
//    cout.tie;
    int t = 1;
    cin >> t;
    while(t--) {
        soloved();
    }

}

