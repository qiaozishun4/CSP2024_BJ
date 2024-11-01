#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sl[100005];
int a[100005];
int n;
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)sl[a[i]]++;
    for(int i=0;i<=100000;i++)ans=max(ans,sl[i]);
    cout<<ans;
    return 0;
}
