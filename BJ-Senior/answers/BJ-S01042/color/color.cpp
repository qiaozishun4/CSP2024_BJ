#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],dp[N][2],n,tmp[N],maxn=0,ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(tmp,0,sizeof(tmp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            tmp[a[i]]++;
            maxn=max(a[i],maxn);
        }
        for(int i=1;i<=maxn;i++){
        if(tmp[i]>1) ans+=(tmp[i]-1)*i;
    }
    cout<<ans<<endl;
    }
    
    return 0;
}