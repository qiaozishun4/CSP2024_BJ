#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    int ans=0;
    for(auto t : mp){
        ans++;
    }
    cout<<52-ans;
    return 0;
}

