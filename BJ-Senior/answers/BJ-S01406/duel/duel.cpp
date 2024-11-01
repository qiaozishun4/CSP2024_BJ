#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
ios sync_with_std(0);
cin.tie(0);cout.tie(0);

cin>>n;
int ans=0;
int maxn=-1e9;
for(int i=1;i<=n;i++){
    cin>>a[i];
    maxn=max(maxn,a[i]);
    ans=ans+a[i];
    b[a[i]]++;
}
    cout<<b[maxn];
    return 0;

return 0;
}
