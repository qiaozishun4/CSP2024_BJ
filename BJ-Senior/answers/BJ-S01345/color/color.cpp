#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005],h[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(h,0,sizeof(h));
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(h[a[i]]>0){
                ans+=a[i];
            }
            h[a[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
