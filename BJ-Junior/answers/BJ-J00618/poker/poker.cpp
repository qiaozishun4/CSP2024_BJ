#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    string s;
    cin>>s;
    mp[s]++;
}
int ans=0;
for(auto &k:mp){
    ans++;
}
cout<<52-ans;
return 0;
}
