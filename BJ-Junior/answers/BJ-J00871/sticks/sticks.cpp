#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
const ll cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll t, n;
string f[maxn];
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w" , stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[1] = "-1", f[2] = "1", f[3] = "7", f[4] = "4", f[5] = "2", f[6] = "6", f[7] = "8", f[8] = "10", f[9] = "18", f[10] = "22", f[11] = "20", f[12] = "28", f[13] = "68", f[14] = "88";
    f[15] = "108", f[16] = "188", f[17] = "200", f[18] = "208", f[19] = "288", f[20] = "688", f[21] = "888";
    cin >> t;
    for(ll mod; t; --t){
        cin >> n;
        if(n <= 14) cout << f[n];
        else {
            mod = n % 7;
            if(!mod) mod + 7;
            cout << f[mod + 14];
            for(ll i = 1; i <= (n - mod - 14) / 7; ++i) cout << 8;
        }
        cout << '\n';
    }
    return 0;
}