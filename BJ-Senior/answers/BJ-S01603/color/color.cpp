#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int q;
int n;
int a[MAXN],dp[MAXN];
int b[MAXN],c[MAXN];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>q;
    while(q--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            b[i]=0;
        }
        for(int i=1;i<=n;i++){
            c[i]=0;
        }
        b[1]=-1;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(a[j]==a[i]){
                    b[i]=j;
                    //cout<<a[i]<<" "<<a[j]<<endl;
                    break;
                }
            }
            if(b[i]==0) b[i]=-1;
            //cout<<b[i]<<endl;
        }
        for(int i=1;i<=n;i++){
            if(b[i]!=-1){
                for(int j=b[i];j<=i-1;j++){
                    for(int k=j-1;k>=b[i];k--){
                        if(a[j]==a[k]){
                            c[i]+=a[j];
                            break;
                        }
                    }
                }
                //cout<<c[i]<<endl;
            }
        }
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(b[i]!=-1){
                dp[i]=max(dp[i-1],dp[i-1]+a[i]-c[i]);
            }else{
                dp[i]=dp[i-1];
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
