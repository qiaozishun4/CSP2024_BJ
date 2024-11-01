#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[1005][1005];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    //a[i][j] 2：空地 3：障碍 1：经过的空地
    while(t--){
        int n,m,k,x,y,d;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char ch;
                cin >> ch;
                if(ch == '.') a[i][j] = 2;
                else a[i][j] = 3;
            }
        }
        a[x][y] = 1;
        int ans = 0;
        for(int i = 1; i <= k; i++){
            int x1,y1;
            if(d == 0){
                x1 = x;
                y1 = y+1;
            }else if(d == 1){
                x1 = x+1;
                y1 = y;
            }else if(d == 2){
                x1 = x;
                y1 = y-1;
            }else if(d == 3){
                x1 = x-1;
                y1 = y;
            }


            if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && a[x1][y1] != 3){
                x = x1;
                y = y1;
                a[x][y] = 1;
                //cout << " " << x << " " << y << " " << d << "\n";
            }else{
                d = (d+1) % 4;
                //cout << " " << d << "\n";
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 1){
                    ans++;
                    //cout << "   " << i << " " << j << "\n";
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
