#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010];
long long ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ans=0;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=n;j>1;j--){
            for(int k=j-1;k>=1;k--){
                if(a[j]==a[k]){
                    ans+=a[j];
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
