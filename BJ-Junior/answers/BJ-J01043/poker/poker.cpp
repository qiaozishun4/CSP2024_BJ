#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        mp[a]++;
    }
    for(auto i:mp) cnt++;
    cout<<52-cnt;
    return 0;
}