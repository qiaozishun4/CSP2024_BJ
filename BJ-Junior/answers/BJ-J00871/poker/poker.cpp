#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 100;
ll n, vis[5][maxn], ans;
ll f(char ch){
    if(ch == 'D') return 1;
    if(ch == 'C') return 2;
    if(ch == 'H') return 3;
    return 4;
}
ll f1(char ch){
    if(ch >= '2' && ch <= '9') return (ch - '0');
    if(ch == 'A') return 1;
    if(ch == 'T') return 10;
    if(ch == 'J') return 11;
    if(ch == 'Q') return 12;
    if(ch == 'K') return 13;
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w" , stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ans = 52;
    cin >> n;
    for(char a, b; n; --n){
        cin >> a >> b;
        vis[f(a)][f1(b)] = 1;
    }
    for(ll i = 1; i <= 4; ++i)
        for(ll j = 1; j <= 13; ++j) ans -= vis[i][j];
    cout << ans;
    return 0;
}