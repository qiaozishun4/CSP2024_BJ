#include <bits/stdc++.h>
using namespace std;
int forest[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for (int p = 1;p <= T;p++){
        int forest[1005][1005];
        for (int i = 1;i <= 1005;i++){
            for (int j = 1;j <= 1005;j++){
                forest[i][j] = 0;
            }
        }
        int x,y,d,xfu,yfu,n,m,k;
        long long ans = 1;
        string wor;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        forest[x][y] = 2;
        for (int i = 1;i <= n;i++){
            cin >> wor;
            for (int j = 1;j <= m;j++){
                //cout << wor[j - 1] << endl;
                if (wor[j - 1] == 'x'){
                    forest[i][j] = 1;
                    //cout << forest[i][j] << endl;
                }
            }
        }
        //for (int i = 1;i <= n;i++){
        //    for (int j = 1;j <= m;j++){
        //        cout << forest[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        for (int q = 1;q <= k;q++){
            xfu = x;
            yfu = y;
            //cout << xfu << " " << yfu << endl;
            if (d == 0) yfu++;
            if (d == 1) xfu++;
            if (d == 2) yfu--;
            if (d == 3) xfu--;
            //cout << xfu << " " << yfu << " " << forest[xfu][yfu] << endl;
            //cout << n << " " << m << endl;
            //cout << check(xfu,yfu) << endl;
            if (((forest[xfu][yfu] != 1) && (xfu >= 1) && (yfu >= 1) && (xfu <= n) && (yfu <= m))){
                x = xfu;
                y = yfu;
                if (forest[x][y] == 0) ans++;
                forest[x][y] = 2;
            }
            else d = (d + 1) % 4;
            //cout << x << " " << y << " " << d << endl;
        }
        cout << ans << endl;
    }
    return 0;
}