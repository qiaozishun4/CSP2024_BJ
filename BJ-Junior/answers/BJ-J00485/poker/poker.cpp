#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
set<string> sg;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        sg.insert(s);
    }
    cout<<52-sg.size();
    return 0;
}
