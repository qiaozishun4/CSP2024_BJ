#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[1000005];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sum-=min(a[1],a[n]);
        cout<<sum<<endl;
    }
    return 0;
}
