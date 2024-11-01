#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    for(int x = 0;x < t;x++){
        int cnt = 1;
        int d = 0;
        int n,m,k;
        cin >> n >> m >> k;
        char p[n][m];
        cin >> x >> y >> d;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin >> p[i][j];
            }
        }
        while(k>0){
            if(d == 0){
                if(y+1<m&&p[x][y+1]!='x'){
                    cnt++;
                    y++;
                }else{
                    d++;
                }
                k--;
                if(k <= 0) break;
            }else if(d == 1){
                if(x+1<n&&p[x+1][y]!='x'){
                    cnt++;
                    x++;
                }else{
                    d++;
                }
                k--;
                if(k <= 0) break;
            }else if(d == 2){
                if(y-1>=0&&p[x][y-1]!='x'){
                    cnt++;
                    y--;
                }else{
                    d++;
                }
                k--;
                if(k <= 0) break;
            }else if(d == 3){
                if(x-1>=0&&p[x-1][y]!='x'){
                    cnt++;
                    x--;
                }else{
                    d=0;
                }
                k--;
                if(k <= 0) break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}