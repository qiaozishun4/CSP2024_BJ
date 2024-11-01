#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n,ans;
    cin>>t;
    while(t--){
            ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]==a[j] && a[i]!=-1){
                    ans+=a[i];
                    a[i]=-1;
                    a[j]=-1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
