#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(!mp[s]) ans--;
        mp[s]=1;
    }
    cout<<ans;
    return 0;
}
