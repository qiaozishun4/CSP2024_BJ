#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
map<string,bool> mp;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string s; cin>>s;
        if(mp[s]!=1) mp[s]=1,ans--;
    }
    cout<<ans<<endl;
    return 0;
}
