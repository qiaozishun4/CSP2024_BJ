#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s,a="A23456789TJQK";
map<string,int> m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        m[s]=1;
    }
    for(int i=0;i<13;i++){
        string x="D"+a.substr(i,1);
        //cout<<x<<" "<<m[x]<<'\n';
        ans-=m[x];
        x="C"+a.substr(i,1);
        ans-=m[x];
        x="H"+a.substr(i,1);
        ans-=m[x];
        x="S"+a.substr(i,1);
        ans-=m[x];
    }
    cout<<ans;
    return 0;
}
