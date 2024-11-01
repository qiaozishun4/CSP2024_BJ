#include <bits/stdc++.h>
using namespace std;
int t;
int n,a[200005],dp[200005];
int main(){
    ios::sync_with_stdio(false);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int last=0;
        for(int i=1;i<=n;i++){
            //cout<<"i: "<<i<<endl;
            for(int j=1;j<i;j++){
                int flag=0;
                if(a[i]==a[j])flag+=a[i];
                for(int k=j+1;k<i;k++){
                    if(last==a[k]){
                        flag+=last;
                    }else{
                        last=a[k];
                    }
                    //cout<<last<<endl;
                }
                //cout<<j<<" "<<dp[j]<<" "<<flag<<endl;
                if(dp[j]+flag<=dp[i])last=0;
                dp[i]=max(dp[i],dp[j]+flag);
            }
        }
        cout<<dp[n]<<endl;
    }
    
    return 0;
}