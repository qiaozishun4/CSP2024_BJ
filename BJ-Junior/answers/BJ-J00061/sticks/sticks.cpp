#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int sn[10]={6,2,5,5,4,5,6,3,7,6};
    long long dp[105]={0};
    int ans[55]={},T,n;
    for(int i=1;i<=100;i++){
        dp[i]=-1;
        for(int j=0;j<10;j++){
            if(i>=sn[j]&&dp[i-sn[j]]!=-1){
                int p=dp[i-sn[j]]*10+j;
                if((dp[i]==0||p<dp[i])&&p!=0)dp[i]=p;
            }
        }
    }
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        ans[i]=dp[n];
    }
    for(int i=1;i<=T;i++)cout<<ans[i]<<endl;
    return 0;
}
