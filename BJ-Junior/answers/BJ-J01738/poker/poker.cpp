#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=52;
    while(n--){
        string s;
        cin>>s;
        if(mp[s]==0){
            mp[s]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
