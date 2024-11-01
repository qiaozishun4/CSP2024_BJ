#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int>mp;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        mp[x]++;
    }
    int ma=0;
    for(auto i:mp){
        ma=max(ma,i.second);
    }
    cout<<ma;
    return 0;
}
