#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
ll a[1000005];
ll b[100001];
ll f[100001];
ll col[20];
ll ans=0;
void d(ll now){
    if(now==n+1){
        ll nows=0;
        for(int i=1;i<n;i++){
            ll tp=1;
            for(int j=i+1;j<=n && tp;j++){
                if(col[i]==col[j]){
                    if(b[i]==b[j]) nows+=b[i];
                    tp=0;
                }
            }
        }
        ans=max(ans,nows);
        return ;
    }
    for(int i=0;i<=1;i++){
        col[now]=i;
        d(now+1);
        col[now]=0;
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >>t;
    while(t--){
        cin >>n;
      //  memset(a,0,sizeof(a));
      //  memset(f,0,sizeof(f));
       // memset(col,0,sizeof(col));
        for(int i=1;i<=n;i++){
            cin >>b[i];
        }
        d(1);
        cout <<ans <<'\n';
        ans=0;
    }
    return 0;
}
