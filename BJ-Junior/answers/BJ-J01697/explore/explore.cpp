#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        int a, b,k, x, y, d;
        cin >> a >> b >> k >>x >> y >> d;
        const int p = a+1, q = b+1;
        int m[p+1][q+1];
        int g[p+1][q+1];
        for(int i = 0;i <=p;i++){
            for(int j = 0;j <= q;j++){
                m[i][j] = 0;
                g[i][j] = 0;
            }
        }
        for(int i = 1;i <=  a;i++){
            for(int j = 1;j <= b;j++){
                char c;
                cin >> c;
                if(c == '.'){
                    m[i][j] = 1;
                }else {
                    m[i][j] = 0;
                }
            }
        }
        int ans = 0;
        ans++;
        int flag = 1;
        while(k--){
            flag = 1;
            if(d == 0&&flag == 1){
                if(m[x][y+1]==0){
                    d++;
                    d%=4;
                    flag = 0;
                }else{
                    y++;
                    if(g[x][y] == 0){
                        ans++;
                    }
                    g[x][y] = 1;
                }
            }else if(d == 1&&flag == 1){
                if(m[x+1][y]==0){
                    d++;
                    d%=4;
                    flag = 0;
                }else{
                    x++;
                    if(g[x][y] == 0){
                        ans++;
                    }
                    g[x][y] = 1;
                }
            }else if(d == 2&&flag == 1){
                if(m[x][y-1]==0){
                    d++;
                    d%=4;
                    flag = 0;
                }else{
                    y--;
                    if(g[x][y] == 0){
                        ans++;
                    }
                    g[x][y] = 1;
                }
            }else if(d == 3&&flag == 1){
                if(m[x-1][y]==0){
                    d++;
                    d%=4;
                    flag = 0;
                }else{
                    x--;
                    if(g[x][y] == 0){
                        ans++;
                    }
                    g[x][y] = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}