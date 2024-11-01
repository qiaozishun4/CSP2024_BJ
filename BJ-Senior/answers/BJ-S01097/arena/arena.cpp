#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int N  = 1e5 + 5 , M = 1e5 + 5 , K = 15;
int n , m , aa[N] , k , cases ,  b[K][N] , a[N] , t[4] , c[M] , e[N];
vector <int> d , f;
char ch;
void fight(int id){
    f.clear();
    for (int i = 0;i < d.size();i += 2){
        int j = i / 2 + 1;
        if (b[id][j]){
            if (a[d[i + 1]] >= id) f.push_back(d[i + 1]);
            else f.push_back(d[i]);
        }
        else{
            if (a[d[i]] >= id) f.push_back(d[i]);
            else f.push_back(d[i + 1]);
        }
    }
    d.clear();
    for (int x : f) d.push_back(x);
}
int main(){
    freopen("arena.in" , "r" , stdin);
    freopen("arena.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> aa[i];
    }
    for (int i = 1;i <= m;i++){
        cin >> c[i];
    }
    k = log2(n) + 1;
    for (int i = 1;i <= k;i++){
        for (int j = 1;j <= (1 << k - i);j++){
            cin >> ch;
            b[i][j] = ch ^ 48;
        }
    }
    cin >> cases;
    while (cases--){
        for (int i = 0;i < 4;i++) cin >> t[i];
        for (int i = 1;i <= n;i++) a[i] = aa[i] ^ t[i & 3];
        int ans = 0 , cnt = 0;
        memset(e , 0 , sizeof e);
        for (int i = 1;i <= m;i++){
            if (e[c[i]]){
                ans ^= (i * e[c[i]]);
                continue;
            }
            d.clear();
            for (int j = 1;j <= c[i];j++) d.push_back(j);
            cnt = 0;
            while (d.size() != 1) fight(++cnt);
            e[c[i]] = d[0];
            ans ^= (i * d[0]);
        }
        cout << ans << '\n';
    }
    return 0;
}