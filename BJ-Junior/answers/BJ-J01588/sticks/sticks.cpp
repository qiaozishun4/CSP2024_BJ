#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int t,n,dp[MAXN],a[10]={0,6,2,5,4,3,7},b[10]={0,0,1,2,4,7,8},ans[MAXN];
int c[10]={0,2,5,4,6,3,7},d[10]={0,1,2,4,6,7,8};
int main(){
    cin>>t;
    while(t--){
        freopen("sticks.in","r",stdin);
        freopen("sticks.out","w",stdout);
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        for(int j=0;j<=n;j++) dp[j]=1e9;
        dp[0]=0;
        for(int i=1;i<=6;i++){
            for(int j=a[i];j<=n;j++){
                dp[j]=min(dp[j],dp[j-a[i]]+1);
            }
        }
        int cnt=0;
        int len=dp[n];
        for(int i=1;i<=6;i++){
  //          cout<<(len-1)*2<<' '<<n-cnt-c[i]<<' '<<(len-1)*7<<endl;
            if((len-1)*2<=n-cnt-c[i]&&n-cnt-c[i]<=(len-1)*7){
   //             cout<<"i="<<i<<' '<<d[i]<<endl;
                ans[1]=d[i];
                cnt+=c[i];
                break;
            }
        }
        for(int k=2;k<=len;k++){
            for(int i=1;i<=6;i++){
                if((len-k)*2<=n-cnt-a[i]&&n-cnt-a[i]<=(len-k)*7){
                    ans[k]=b[i];
                    cnt+=a[i];
                    break;
                }
            }
        }
        for(int i=1;i<=len;i++) cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
