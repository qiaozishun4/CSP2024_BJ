#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],pt,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    pt=1,ans=n;
    for(int i=1;i<=n;i++)
        if(a[i]>a[pt]) pt++,ans--;
    cout<<ans;
    return 0;
}