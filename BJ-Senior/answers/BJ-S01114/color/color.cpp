#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;


int T;
unsigned int n,a[N],dp[N],fr[N],qzh[N];
unsigned int b[1000005];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        memset(fr,0,sizeof(fr));
        memset(b,0,sizeof(b));
        memset(qzh,0,sizeof(qzh));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(b[a[i]]!=0){
                fr[i]=b[a[i]];
            }
            b[a[i]]=i;
            qzh[i]=qzh[i-1];
            if(a[i]==a[i-1]){
                qzh[i]+=a[i];
            }
        }
        for(int i=2;i<=n;i++){
          //  dp[i]=dp[i-1];
            if(fr[i]!=0){
                if(fr[i]==i-1){
                    dp[i]=dp[i-1]+a[i];
                    //cout<<dp[i]<<" ";
                    continue;
                }
                int x=dp[fr[i]+1]+a[i];
                if(i-1>fr[i]+1){
                    x+=qzh[i-1]-qzh[fr[i]+1];
                }

               if(dp[i-1]>x){
                dp[i]=dp[i-1];
               }else{
                dp[i]=x;
               }
            }else{
                dp[i]=dp[i-1];
            }
            //cout<<dp[i]<<" ";
        }
        cout<<dp[n]<<endl;
    }

    return 0;
}
