#include<bits/stdc++.h>
using namespace std;
const int N = 4.6 * 1e4;
int ans = 1;
char mp[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> mp[i][j];
            }
        }
        while(k--){
            if(d == 0){
                if(1 <= x  && x <= n && 1 <= y + 1 && y + 1 <= m && mp[x][y] != 'x'){
                    ans += 1;
                    y++;
                }else{
                    d += 1;
                }
            }else if(d == 1){
                if(1 <= x + 1 && x + 1 <= n && 1 <= y  && y <= m && mp[x][y] != 'x'){
                    ans += 1;
                    x++;
                }else{
                    d += 1;
                }
            }else if(d == 2){
                if(1 <= x && x <= n && 1 <= y - 1 && y <= m && mp[x][y] != 'x'){
                    ans += 1;
                    y--;
                }else{
                    d += 1;
                }
            }else if(d == 3){
                if(1 <= x - 1  && x - 1 <= n && 1 <= y && y <= m && mp[x][y] != 'x'){
                    ans += 1;
                    x--;
                }else{
                    d = (d + 1) % 4;
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
