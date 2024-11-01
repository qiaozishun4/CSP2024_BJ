#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
set<string> s;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        s.insert(str);
    }
    cout<<52-s.size()<<endl;
    return 0;
}