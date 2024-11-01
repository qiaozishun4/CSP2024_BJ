#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<string,int>mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string k;
        cin>>k;
        mp[k]++;
        if(mp[k]<=1) ans++;
    }cout<<52-ans;
    return 0;
}
