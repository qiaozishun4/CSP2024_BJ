#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
map<string,ll> mp;
ll ans=0;
char a[5]={' ','D','C','H','S'};
char b[15]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        string str;
        cin>>str;
        mp[str]=1;
    }
    for(ll i=1;i<=4;i++)
        for(ll j=1;j<=13;j++){
            string str="";
            str+=a[i];
            str+=b[j];
            if(mp[str]==0)
                ans++;
        }
    cout<<ans;
    return 0;
}