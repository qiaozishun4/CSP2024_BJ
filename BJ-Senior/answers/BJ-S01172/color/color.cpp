#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int a[200005];
int dp[200005];
int f[200005];
int ton[1000005];
int ton2[1000005];
int qzh[200005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

        freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){

        cin>>n;
        for(int i=1;i<=1e6;i++)ton[i]=0;
        for(int i=1;i<=n;i++)cin>>a[i];
       /* if(n>2000){
            cout<<"a\n";
            continue;
        }*/
        memset(qzh,0,sizeof(qzh));
        for(int i=1;i<=n-1;i++){
            if(a[i+1]==a[i])qzh[i]=a[i];
        }
        for(int i=1;i<=n;i++)qzh[i]+=qzh[i-1];
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        memset(ton,-0x3f,sizeof(ton));
        memset(ton2,-0x3f,sizeof(ton2));
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            //cout<<ton[a[i]]<<"asdf"<<endl;
            if(a[i]==a[i-1])dp[i]=max(dp[i],dp[i-1]+a[i]);
            dp[i]=max(ton[a[i]]+a[i]+qzh[i-2],dp[i]);
            dp[i]=max(dp[i],ton2[a[i]]+a[i]+qzh[i-2]);
            f[i]=max(ton[a[i]]+a[i]+qzh[i-2],f[i]);
            f[i]=max(f[i],ton2[a[i]]+a[i]+qzh[i-2]);
          //  cout<<dp[i]<<" "<<f[i]<<endl;
            ton[a[i-1]]=max(ton[a[i-1]],dp[i-1]-qzh[i-1]);
            ton2[a[i-1]]=max(ton2[a[i-1]],f[i]-qzh[i-1]);
           /* for(int t:v[a[i]]){
                if(t==i-1)dp[i]=max(dp[i-1]+a[i],dp[i]);
                else{
                    dp[i]=max(dp[t]+a[i]+qzh[i-2]-qzh[t],dp[i]);
                  //  cout<<t<<endl;
                    dp[i]=max(f[t+1]+a[i]+qzh[i-2]-qzh[t],dp[i]);
                    f[i]=max(f[i],f[t+1]+a[i]+qzh[i-2]-qzh[t]);
                    f[i]=max(dp[t]+a[i]+qzh[i-2]-qzh[t],f[i]);

                }
            }*/
            //cout<<dp[i]<<" "<<f[i]<<endl;
          //  v[a[i]].push_back(i);
            //cout<<i<<" "<<dp[i]<<" "<<f[i]<<endl;
        }
        cout<<dp[n]<<endl;
    }
}

