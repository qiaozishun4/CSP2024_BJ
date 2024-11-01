#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=52;cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        if(!mp[s])mp[s]=1,cnt--;
    }
    cout<<cnt;
    return 0;
}
