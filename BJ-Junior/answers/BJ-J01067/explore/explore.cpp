#include <iostream>
using namespace std;

int main(){
    if(freopen("explore.in", "r", stdin) == NULL) return 1;
    if(freopen("explore.out", "w", stdout) == NULL) return 1;

    int T; cin >> T;
    while(T--){
        int n, m, k; cin >> n >> m >> k;
        int x0, y0, x1, y1, x2, y2, d0, d1, d2; cin >> x0 >> y0 >> d0;
        char a[n + 1][m + 1]; bool vis[n + 1][m + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }

        int cnt = 1; x1 = x0, y1 = y0, d1 = d0, vis[x1][y1] = 1;
        for(int i = 1; i <= k; i++){
            switch(d1){
                case 0:{
                    x2 = x1, y2 = y1 + 1;
                    break;
                }
                case 1:{
                    x2 = x1 + 1, y2 = y1;
                    break;
                }
                case 2:{
                    x2 = x1, y2 = y1 - 1;
                    break;
                }
                case 3:{
                    x2 = x1 - 1, y2 = y1;
                    break;
                }
            }
            if((x2 >= 1 && x2 <= n) && (y2 >= 1 && y2 <= m) && a[x2][y2] == '.'){
                x1 = x2, y1 = y2;
                if(!vis[x1][y1]){
                    vis[x1][y1] = 1;
                    cnt++;
                }
            }
            else{
                d2 = (d1 + 1) % 4;
                d1 = d2;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
