#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
set<string>se;
void slv(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s,se.insert(s);
    cout<<52-se.size()<<endl;
}
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    slv();
    return 0;
}