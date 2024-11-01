#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005];
int s[100005];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]++;
    }
    int nw=0;
    int ans=n;
    for(int i=0;i<=100000;i++){
        if(s[i]>=nw){
            ans-=nw;
            nw=0;
        }
        else{
            nw-=s[i];
            ans-=s[i];
        }
        nw+=s[i];
    }
    cout<<ans;
    return 0;
}
