#include <iostream>
using namespace std;
#define ll long long
ll t, n, m, k;
string str[1010];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t --){
            cc = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i ++){
            cin >> str[i];
        }
        if(d == 0){
            if(y < m - 1 && str[x][y + 1] == 'x'){
                cc ++;
            }
        }
        if(d == 1){
            if(x < n && str[x + 1][y] == 'x'){
                cc ++;
            }
        }
        if(d == 2){
            if(y > 0 && str[x][y - 1] == 'x'){
                cc ++;
            }
        }
        if(d == 3){
            if(x > 1 && str[x - 1][y] == 'x'){
                cc ++;
            }
        }
        cout << cc;
    }
    return 0;
}
