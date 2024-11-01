#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e3 + 5;
int t;
int n, m, k;
int X0, Y0, D0;
int tx, ty;
int nra, x, y, d;
char ch[N][M];
set<int> s;
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t--){
        nra = 0;
        cin >> n >> m >> k;
        cin >> X0 >> Y0 >> D0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> ch[i][j];
        x = X0, y = Y0, d = D0;
        tx = x, ty = y;
        while (k--){
            if (d == 0) ty++;
            else if (d == 1) tx++;
            else if (d == 2) ty--;
            else if (d == 3) tx--;
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && ch[tx][ty] == '.'){
                x = tx, y = ty;
                nra++;
            }else{
                tx = x, ty = y;
                d = (d + 1) % 4;
            }
            s.insert(x * 10 + y);
        }
        int ize = s.size();
        cout << ize << "\n";
    }
    return 0;
}