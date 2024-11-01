#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T,ans=0;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]==a[j]){
                    ans+=a[i];
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
