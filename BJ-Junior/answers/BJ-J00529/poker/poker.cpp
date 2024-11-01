#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        mp[s]=true;
    }
    cout<<52-mp.size();
    return 0;
}
