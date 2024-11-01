#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
bool ispk[10][15];
int main(){
    freopen("poker.in","r", stdin);
    freopen("poker.out", "w", stdout);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i ++){
        char c[3];
        ll a, b;
        cin >> c;
        if(c[0] == 'D')a = 1;
        if(c[0] == 'C')a = 2;
        if(c[0] == 'H')a = 3;
        if(c[0] == 'S')a = 4;
        if(c[1] == 'A')b = 1;
        else if(c[1] == 'T')b = 10;
        else if(c[1] == 'J')b = 11;
        else if(c[1] == 'Q')b = 12;
        else if(c[1] == 'K')b = 13;
        else b = c[1] - '0';
        ispk[a][b] = 1;
    }
    ll cnt = 0;
    for(ll i = 1; i <= 4; i ++){
        for(ll j = 1; j <= 13; j ++){
            if(ispk[i][j])cnt ++;
        }
    }
    cout << 52 - cnt << "\n";
    return 0;
}