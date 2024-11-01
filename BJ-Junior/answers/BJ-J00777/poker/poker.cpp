#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string,bool> mp;
    while(n--){
        string x;
        cin >> x;
        mp[x]=1;
    }
    cout << 52-mp.size();
    return 0;
}
