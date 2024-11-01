#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;

    int ans=52;
    while(n--){
        string s;
        cin>>s;
        mp[s]++;
        if(mp[s]==1)ans--;
        //cout<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
/*
4
DQ
H3
DQ
DT

*/
