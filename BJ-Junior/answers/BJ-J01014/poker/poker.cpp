#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;string s;
map<string,int>mp;
int ans;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    ans=52-n;
    while(n--){
        cin>>s;
        if(mp[s]){
            ans++;
        }else{
            mp[s]++;
        }
    }
    cout<<ans;
    return 0;
}
