#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r[100005],vis[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&r[i]);
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        ll j=upper_bound(r+1,r+n+1,r[i])-r;
        while(j<=n&&vis[j])j++;
        if(j==n+1){
            cout<<n-i+1<<'\n';
            break;
        }else vis[j]=1;
    }
    return 0;
}