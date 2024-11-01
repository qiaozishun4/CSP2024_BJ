#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
ll w[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string ans, use;\
string smaller(string a, string b){
    if(a.size() < b.size())return a;
    else if(a.size() > b.size())return b;
    for(ll i = 0; i <= a.size(); i ++){
        if(a[i] < b[i]){
            return a;
        }else if(a[i] > b[i]){
            return b;
        }
    }
    return a;
}
void dfs(ll sum, ll n){
//    cout << sum << " " << use << "\n";
    if(sum > n)return;
    if(sum == n){
        if(ans == "")ans = use;
        else ans = smaller(ans, use);
        return;
    }
    ll start = 1;
    if(sum != 0)start = 0;
    for(ll i = start; i <= 9; i ++){
        if(i == 3 || i == 5 || i == 9)continue;
        use += char(i + '0');
        dfs(sum + w[i], n);
        use.pop_back();
    }
}
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ll t;
    cin >> t;
    while(t --){
        ll n;
        cin >> n;
        use.clear();
        ans.clear();
        dfs(0, n);
        if(!ans.empty())cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}