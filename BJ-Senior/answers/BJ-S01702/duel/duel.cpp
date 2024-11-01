#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005],t[100005],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    sort(a+1,a+n+1);
    ll x=0;
    for(int i=1;i<=n;i++){
        if(ans>0){
            ans--;
            x++;
        }else{
            x++;
        }
        if(a[i]!=a[i+1]){
            ans+=x;
            x=0;
        }
    }
    cout<<ans;
    return 0;
}
