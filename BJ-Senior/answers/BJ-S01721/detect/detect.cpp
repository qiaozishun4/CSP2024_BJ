#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,l,v1,pi,cam,ans,ans2;
int d[100010],v[100010],a[100010];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while (t--){
        ans=0;
        cin>>n>>m>>l>>v1;
        ans2=m;
        for (int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for (int i=1;i<=m;i++){
            cin>>pi;
            if (i==m){
                cam=pi;
            }
        }
        for (int i=1;i<=n;i++){
            if (d[i]<cam){
                if (v[i]>v1){
                    ans++;
                    continue;
                }
                int tmp=v[i]*v[i]+2*a[i]*(cam-d[i]);
                if (a>0){
                    if (tmp>v1*v1){
                        ans++;
                    }
                }
            }
            else if (d[i]==cam){
                if (v[i]>v1){
                    ans++;
                }
            }
        }
        if (ans){
            ans2--;
        }
        cout<<ans<<" "<<ans2<<"\n";
    }
    return 0;
}
