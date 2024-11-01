#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200005],d[4005][4005],f[4005][4005],maxn[5005];
ll p(ll x,ll y){
    if(x==y) return x;
    else return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n; memset(maxn,0,sizeof(maxn));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) d[i][j]=d[i][j-1]+p(a[j-1],a[j]);
        }
        for(int i=2;i<=n;i++){
            f[i][i-1]=max(maxn[i-1],f[i-1][i-2])+p(a[i],a[i-1]);
            for(int j=1;j<i-1;j++){
                f[i][j]=p(a[i],a[j])+d[j+1][i-1]+maxn[j+1];
                //cout<<i<<" "<<j<<" "<<d[j+1][i-1]<<" "<<maxn[j+1]<<" "<<f[i][j]<<endl;
                maxn[i]=max(maxn[i],f[i][j]);
            }
        }
        cout<<max(maxn[n],f[n][n-1])<<endl;
    }
    return 0;
}
/*
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
18
3 5 2 5 1 2 1 4     8
*/
