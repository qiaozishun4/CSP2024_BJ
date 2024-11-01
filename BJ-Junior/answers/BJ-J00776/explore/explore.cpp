#include<bits/stdc++.h>
using namespace std;
int t;
char a[1001][1001];
bool b[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t --){
        memset(b,0,sizeof b);
        int n = 0,m = 0,k = 0;
        int x = 0,y = 0,d = 0;
        int ans = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= m;j ++){
                cin >> a[i][j];
            }
        }
        b[x][y] = true;
        while(k --){
            if(d == 0){
                if(x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m && a[x][y + 1] == '.'){
                    if(!b[x][y + 1]){
                        ans ++;
                    }
                    y += 1;
                    b[x][y] = true;
                }else{
                    d ++;
                    d %= 4;
                }
            }else if(d == 1){
                if(x + 1 >= 1 && x + 1 <= n  && y >= 1 && y <= m && a[x + 1][y] == '.'){
                    if(!b[x + 1][y]){
                        ans ++;
                    }
                    x += 1;
                    b[x][y] = true;
                }else{
                    d ++;
                    d %= 4;
                }
            }else if(d == 2){
                if(x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m && a[x][y - 1] == '.'){
                    if(!b[x][y - 1]){
                        ans ++;
                    }
                    y -= 1;
                    b[x][y] = true;
                }else{
                    d ++;
                    d %= 4;
                }
            }else if(d == 3){
                if(x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m && a[x - 1][y] == '.'){
                    if(!b[x - 1][y]){
                        ans ++;
                    }
                    x -= 1;
                    b[x][y] = true;
                }else{
                    d ++;
                    d %= 4;
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
