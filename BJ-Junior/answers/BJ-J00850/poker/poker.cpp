#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(mp[s]==1) continue;
        mp[s]=1;
        cnt++;
    }
    cout<<52-cnt;
    return 0;
}