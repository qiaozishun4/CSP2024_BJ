#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,r=0,len=1;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    b[len]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) b[len]++;
        else b[++len]=1;
    }
    for(int i=1;i<=len;i++) r=max(r,b[i]);
    cout<<r;
    return 0;
}
//CSP-S rp++;
