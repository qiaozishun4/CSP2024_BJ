#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[20];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int s=0;s<(1<<n);s++){
            int res=0;
            for(int i=1;i<=n;i++){
                for(int j=i-1;j>=1;j--){
                    if(((s>>(i-1))&1)==((s>>(j-1))&1)){
                        if(a[i]==a[j]){
                            res+=a[i];
                        }
                        break;
                    }
                }
            }
            ans=max(ans,res);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
