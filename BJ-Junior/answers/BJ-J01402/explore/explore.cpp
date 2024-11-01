#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
LL T;//(1 <= T <= 5)
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    for(LL i = 1; i <= T; i++){
        LL n,m,k;
        LL x,y,d;
        LL ans = 0;
        cin >> n >> m >> k;
        bool map[n+5][m+5] = {false};
        cin >> x >> y >> d;
        map[x][y] = true;
        ans++;
        string s[n+5];
        for(LL J = 1; J <= n; J++)
            cin >> s[J];
        for(LL J = 1; J <= k; J++){
            if(d == 0){
                if(1 <= x <= n && 1 <= y+1 <= m && s[x][y+1] == '.'){
                    y = y + 1;
                    if(!map[x][y+1])
                        ans++,map[x][y+1] = true;
                }
                else
                    d = (d+1)%4;
            }
            else if(d == 1){
                if(1 <= x+1 <= n && 1 <= y <= m && s[x+1][y] == '.'){
                    x = x + 1;
                    if(!map[x+1][y])
                        ans++,map[x+1][y] = true;
                }
                else
                    d = (d+1)%4;
            }
            else if(d == 2){
                if(1 <= x <= n && 1 <= y-1 <= m && s[x][y-1] == '.'){
                    y = y - 1;
                    if(!map[x][y-1])
                        ans++,map[x][y-1] = true;
                }
                else
                    d = (d+1)%4;
            }
            else if(d == 3){
                if(1 <= x-1 <= n && 1 <= y <= m && s[x-1][y] == '.'){
                    x = x - 1;
                    if(!map[x-1][y])
                        ans++,map[x-1][y] = true;
                }
                else
                    d = (d+1)%4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}