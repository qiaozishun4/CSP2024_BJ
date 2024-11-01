#include<bits/stdc++.h>
using namespace std;
map <string, bool> mp;
int n, ans; string s;
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        if(mp[s]!=true){
            mp[s]=true;
            ans++;
        }
    }
    if(ans>52) cout << 0 << endl;
    else cout << 52-ans << endl;
    return 0;
}
