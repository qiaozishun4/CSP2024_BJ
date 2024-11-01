#include<bits/stdc++.h>
using namespace std;
long long n,cnt,tot,a[100005],c[100005],t[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            cnt++;
            t[cnt]=t[cnt-1]+c[cnt-1];
        }
        c[cnt]++;
    }
    for(int i=2;i<=cnt;i++){
        n-=min(c[i],t[i]-tot);
        tot+=min(c[i],t[i]-tot);
    }
    cout<<n;
    return 0;
}
