#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string,bool>m;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        m[s]=1;
    }
    cout<<52-m.size();
    return 0;
}
