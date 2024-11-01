#include<bits/stdc++.h>
#define ll long long
#define N 500050
using namespace std;
struct e{
    ll r1,b1,val;
}dp[N];
ll t,n,a[N],ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
                dp[i]=dp[i-1];
            for(int j=i-1;j>0;j--){
                if(a[j]==a[i]){
                    if(a[i]==a[dp[i].r1]){
                        dp[i].val+=a[i];
                        dp[i].r1=i;
                        break;
                    }
                    if(a[i]==a[dp[i].b1]){
                        dp[i].val+=a[i];
                        dp[i].b1=i;
                        break;
                    }

                   if(dp[i].r1<=j){
                        dp[i].val+=a[i];
                        dp[i].r1=i;
                   }else{
                        if(dp[i].b1<=j){
                            dp[i].val+=a[i];
                            dp[i].b1=i;
                        }else{
                            if(a[dp[i].r1]>a[dp[i].b1]){
                                if(a[dp[i].b1]>=a[j]){

                                }else{
                                    dp[i].val=dp[i].val-a[dp[i].b1]+a[j];
                                    dp[i].b1=j;
                                }
                            }else{
                                if(a[dp[i].r1]>=a[j]){

                                }else{
                                    dp[i].val=dp[i].val-a[dp[i].r1]+a[j];
                                    dp[i].r1=j;
                                }

                            }
                        }
                   }

                break;
                }
            }

        }
        /*for(int i=1;i<=n;i++){
                cout<<dp[i].val<<"   ";
        }*/
        cout<<dp[n].val<<endl;
    }
    return 0;
}
