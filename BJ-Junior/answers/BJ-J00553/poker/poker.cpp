#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=52;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
    }
    ans=ans-n;
    if(n==1) cout<<51<<endl;
    if(n==52) cout<<0<<endl;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(s[i]==s[j]){
                ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}