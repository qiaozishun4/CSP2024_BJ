#include<bits/stdc++.h>
using namespace std;
long long n;
string s,a="0DCHS",b="0A23456789TJQK";
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>s;
        mp[s]=1;
    }
    long long ans=0;
    for(long long i=1;i<=4;i++){
        for(long long j=1;j<=13;j++){
            s="";
            s+=a[i];
            s+=b[j];
            if(!mp[s])ans++;
        }
    }
    cout<<ans;
    return 0;
}
