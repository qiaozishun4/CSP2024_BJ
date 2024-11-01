#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+10;
int t,n;
int a[N],tong[N];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            tong[a[i]]++;
        }
        for(int i=1;i<=N;i++){
            if(tong[i]==2) ans+=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}