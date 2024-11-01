#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>> T;
    while(T--){
        int n,m,k,x,y,d,ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        char f[n+2][m+2];
        bool flag[n+2][m+2];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> f[i][j];
                flag[i][j] = false;
            }
        }
        flag[x][y] = true;
        for (int i = 1; i <= k; i++){
            if(d == 0){
                y+=1;
                if(y>m || f[x][y] == 'x'){
                    y-=1;
                    d = (d+1)%4;
                }else{
                    flag[x][y] = true;
                }
            }else if(d == 1){
                x+=1;
                if(x>n || f[x][y] == 'x'){
                    x-=1;
                    d = (d+1)%4;
                }else{
                   flag[x][y] = true;
                }
            }else if(d == 2){
                y-=1;
                if(y<1 || f[x][y] == 'x'){
                    y+=1;
                    d = (d+1)%4;
                }else{
                    flag[x][y] = true;
                }
            }else if(d == 3){
                x-=1;
                if(x<1 || f[x][y] == 'x'){
                    x+=1;
                    d = (d+1)%4;
                }else{
                    flag[x][y] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(flag[i][j]){
                    ans++;
                }
            }
        }
        cout << ans<<endl;
    }
    return 0;
}