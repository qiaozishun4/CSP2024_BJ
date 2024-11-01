#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100010;
ll n, ans;
set<string> S;
string str;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> str;
        S.insert(str);
    }
    ans = 52 - S.size();
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
