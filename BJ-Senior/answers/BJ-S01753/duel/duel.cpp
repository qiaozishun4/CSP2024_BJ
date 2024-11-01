#include<bits/stdc++.h>
using namespace std;
int mp[100005],maxx=0,ans=0,n,a;
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
        cin>>a;
    mp[a]++;
    maxx=max(maxx,a);
}
for(int i=1;i<=maxx;i++){
    ans=max(ans,mp[i]);
}
cout<<ans;
return 0;
}
