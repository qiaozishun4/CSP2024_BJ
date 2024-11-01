#include<bits/stdc++.h>
using namespace std;
int sti[10]={6,2,5,5,4,5,6,3,7,6};
int dp[100005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=0;i<=9;i++){
            for(int j=n;j>=1;j++){
                dp[j]=min(dp[j-1],dp[j-sti[i]]+sti[i]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);

}
