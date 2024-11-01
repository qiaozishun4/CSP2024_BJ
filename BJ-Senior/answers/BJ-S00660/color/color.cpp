#include<bits/stdc++.h>
#define int long long
using namespace std;
int num[200010];
int pre[1000010],last[1000010];
int f[200010],sum[200010];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            pre[i]=last[num[i]];
            last[num[i]]=i;
        }
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        for(int i=2;i<=n;i++){
            if(num[i]==num[i-1])sum[i]+=num[i-1];
            sum[i]+=sum[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            f[i]=f[pre[i]]+sum[i-1]-sum[pre[i]+1]+num[pre[i]];
            if(pre[i]&&num[pre[i]-1]==num[pre[i]+1])f[i]+=num[pre[i]-1];
            ans=max(ans,f[i]+sum[n]-sum[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
