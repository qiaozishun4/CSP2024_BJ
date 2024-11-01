#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,a[N],b[N],sum,cnt,ans;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1])cnt++;
        b[cnt]++;
    }
    sum=b[1];
    for(int i=2;i<=cnt;i++){
        if(b[i]>sum)sum=0;
        else sum-=b[i];
        sum+=b[i];
    }
    cout<<sum<<'\n';
    return 0;
}
