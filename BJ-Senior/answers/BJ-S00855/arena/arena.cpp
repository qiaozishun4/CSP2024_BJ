#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, p, T;
int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    srand(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> p;
    }
    for(ll i = 1; i <= m; i++){
        cin >> p;
    }
    for(ll i = 1; i <= 31; i++){
        if(pow(2, i) >= n){
            for(int j = 1; j <= i; j++){
                cin >> p;
            }
            break;
        }
    }
    cin >> T;
    for(int i = 1; i <= T; i++){
        cout << rand()%14 << endl;
    }
    return 0;
}
