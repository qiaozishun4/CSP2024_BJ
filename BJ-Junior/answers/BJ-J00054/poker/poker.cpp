#include <bits/stdc++.h>
using namespace std;
bool vis[256][256];
string s;
char a, b;
int n, ans = 52;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> s;
        a = s[0], b = s[1];
        if(!vis[a][b]){
            vis[a][b] = 1;
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}
