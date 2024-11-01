#include<bits/stdc++.h>
using namespace std;
int T,a[200005],dp[200005],n;
int main (){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){

        cin>>n;
        for(int j=1;j<=n;j++){

            cin>>a[j];
        }
        dp[1]=0;
        for(int j=2;j<=n;j++){
            dp[j]=dp[j-1];
            for(int f=j-1;f>=1;f--){

                if(a[f]==a[j]){

                    dp[j]+=a[f];
                    break;
                }
            }
        }
        cout<<dp[n]<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}