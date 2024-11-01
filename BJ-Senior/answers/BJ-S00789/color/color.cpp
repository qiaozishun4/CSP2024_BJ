#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=200005,N_=1000005;
int T,n,a[N],b[N_],ans;
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==a[i-1])continue;
            b[a[i]]++;
            if(b[a[i]]>1)ans+=a[i];
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)
            b[a[i]]--;
    }
    return 0;
}
