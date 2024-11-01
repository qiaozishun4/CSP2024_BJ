#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void solve(){
    int n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        string map[n + 1];
        bool went_place[n+1][m+1];
        memset(went_place,sizeof(went_place),false);
        went_place[x][y]=true;
        for(int i = 1; i <= n; ++i)
            cin >> map[i];
        while(k--) {
            switch(d) {
                case 0:
                    if(1 <= y + 1 && y + 1 <= m && map[x][y + 1] == '.'){
                        ++y,went_place[x][y]=true;
                    }
                    else{
                        d = (d + 1) % 4;
                    }
                    break;
                case 1:
                    if(1 <= x + 1 && x + 1 <= n && map[x + 1][y] == '.'){
                        ++x,went_place[x][y]=true;
                    }
                    else{
                        d = (d + 1) % 4;
                    }
                    break;
                case 2:
                    if(1 <= y - 1 && y - 1 <= m && map[x][y - 1] == '.'){
                        --y,went_place[x][y]=true;
                    }
                    else{
                        d = (d + 1) % 4;
                    }

                    break;
                case 3:
                    if(1 <= x - 1 && x - 1 <= n && map[x - 1][y] == '.'){
                        --x,went_place[x][y]=true;
                    }
                    else{
                        d = (d + 1) % 4;
                    }
                    break;
            }
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(went_place[i][j]==true)
                    ++ans;
        cout << ans << endl;
        return;
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
