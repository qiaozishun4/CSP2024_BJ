//PASS
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[22];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int lst[2]={-1,-1};
            int sum=0;
            for(int j=1;j<=n;j++){
                bool col=(i&(1<<(j-1)));
                if(lst[col]==a[j])sum+=a[j];
                lst[col]=a[j];
            }
            ans=max(ans,sum);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
