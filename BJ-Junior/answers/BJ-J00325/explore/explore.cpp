#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, x0, y0, d0;
        bool a[1010][1010] = {false}, v[1010][1010] = {false};
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                if(c == '.'){
                    a[i][j] = true;
                }
            }
        }
        x0--;
        y0--;
        v[x0][y0] = true;
        for(int i = 0; i < k; i++){
            int nextx = x0, nexty = y0;
            if(d0 == 0){
                nexty++;
            }else if(d0 == 1){
                nextx++;
            }else if(d0 == 2){
                nexty--;
            }else{
                nextx--;
            }
            if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m){
                d0++;
                if(d0 >= 4){
                    d0 = 0;
                }
            }else if(!a[nextx][nexty]){
                d0++;
                if(d0 >= 4){
                    d0 = 0;
                }
            }else{
                x0 = nextx;
                y0 = nexty;
                v[x0][y0] = true;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j]){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
