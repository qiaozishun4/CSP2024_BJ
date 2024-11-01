#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
     int t;
     cin >> t;
     for(int i = 1; i <= t; i++){
            int n,m,k;
            int x,y,d;
            char ch[1005][1005];
            cin >> n >> m >> k;
            cin >> x >> y >> d;
            ch[x][y] = 1;
            for(int j = 1; j <= n; j++){
                   for(int l = 1; l <= m; l++){
                          cin >> ch[j][l];
                   }
            }
            for(int j = 1; j <= k; j++){
                  if(d == 0){
                       if(y+1 >= 1 && y+1 <= m && ch[x][y+1] != 'x'){
                              y++;
                             ch[x][y] = '1';
                        }
                       else d = (d+1)%4;
                   } 
                   if(d == 1){
                         if(x+1 >= 1 && x+1 <= n && ch[x+1][y] != 'x'){
                             x++;
                             ch[x][y] = '1';
                         }
                         else d = (d+1)%4;
                   }
                   if(d == 2){
                       if(y-1 >= 1 && y-1 <= m && ch[x][y-1] != 'x'){
                            y--;
                            ch[x][y] = '1';
                        }
                        else d = (d+1)%4;
                  }
                  if(d == 3){
                      if(x-1 >= 1 && x-1 <= n && ch[x-1][y] != 'x'){
                          x--;
                          ch[x][y] = '1';
                      }
                      else d = (d+1)%4;
                  }
             }
             int cnt = 0;
             for(int j = 1; j <= n; j++){
                  for(int l = 1; l <= m; l++){
                      if(ch[j][l] == '1') cnt++;
                  }
             }
             cout << cnt << "\n";
     }
     return 0;
}