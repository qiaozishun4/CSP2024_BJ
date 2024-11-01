#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    map<string,int>mp;
    string s;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(mp[s]==0){
            ans++;
            mp[s]++;
        }else{
            mp[s]++;
        }
    }
    cout<<52-ans;
    return 0;
}
