#include<iostream>
#include<algorithm>
using namespace std;
long long t,n,a[200005],mmax[200005],last[200005],c[200005],sum[200005],dp[200005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        sum[0]=0;
        for(int i=1;i<=n;i++){
            last[i]=mmax[i]=0;
            cin>>a[i];
            c[i]=a[i];
            if(a[i]==a[i-1]&&i!=1){
                sum[i]=sum[i-1]+a[i];
            }else{
                sum[i]=sum[i-1];
            }
        }
        sort(c+1,c+1+n);
        int n2=unique(c+1,c+1+n)-c-1;
        for(int i=1;i<=n;i++){
            a[i]=lower_bound(c+1,c+1+n2,a[i])-c;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]){
                dp[i]=dp[i-1]+c[a[i]];
            }else{
                dp[i]=dp[i-1];
            }
            if(last[a[i]]!=0){
                dp[i]=max(dp[i],c[a[i]]+sum[i-1]+mmax[a[i]]);
            }
            last[a[i]]=i;
            mmax[a[i]]=max(mmax[a[i]],dp[i-1]-sum[i+1]);
            mmax[a[i-1]]=max(mmax[a[i-1]],dp[i]-sum[i]);
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
