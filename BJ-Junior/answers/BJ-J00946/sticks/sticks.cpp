#include<iostream>
using namespace std;
#define int unsigned long long
#define endl '\n'

int sticks[10][2];
int t,n,maxn = 1e18;

void dfs(int now,int ans){
    if(ans >= maxn) return ;
    if(now > n) return ;
    if(now == n){
        maxn = min(maxn,ans);
        return ;
    }
    for(int i = 0;i <= 9;++i) dfs(now + sticks[i][0],ans * 10 + sticks[i][1]);
}

signed main(){
    ios::sync_with_stdio(false);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    sticks[0][0] = 7,sticks[0][1] = 8;
    sticks[1][0] = 6,sticks[1][1] = 0;
    sticks[2][0] = 6,sticks[2][1] = 6;
    sticks[3][0] = 6,sticks[3][1] = 9;
    sticks[4][0] = 5,sticks[4][1] = 2;
    sticks[5][0] = 5,sticks[5][1] = 3;
    sticks[6][0] = 5,sticks[6][1] = 5;
    sticks[7][0] = 4,sticks[7][1] = 4;
    sticks[8][0] = 3,sticks[8][1] = 7;
    sticks[9][0] = 2,sticks[9][1] = 1;
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 30){
            maxn = 1e18;
            for(int i = 0;i <= 9;++i){
                if(sticks[i][1] == 0) continue;
                dfs(sticks[i][0],sticks[i][1]);
            }
            if(maxn != 1e18) cout << maxn << endl;
            else cout << -1 << endl;
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1;i <= n / 7;++i) cout << 8;
            cout << endl;
            continue;
        }
        if(n % 7 == 1){
            if(n / 7 == 0){
                cout << -1 << endl;
                continue;
            }
            cout << 10;
            for(int i = 1;i < n / 7;++i) cout << 8;
            continue;
        }
    }
    return 0;
}
