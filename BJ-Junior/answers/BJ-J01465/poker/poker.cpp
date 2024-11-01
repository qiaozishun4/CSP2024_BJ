#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    for(auto x:mp){
        if(x.second>1){
            n-=1;
        }
    }
    cout<<ans-n;
    return 0;
}
