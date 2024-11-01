#include<bits/stdc++.h>

using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
int dp[100005];
int T,ans[51],maxx=-1,temp,rec;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    for(int i =1;i<=T;i++){
        cin>>temp;
        maxx= max(maxx,temp);
        ans[i] = temp;
    }

    for(int num = 1;num<=9;num++){
        for(int i =1;i<=maxx;i++){
            if(i-a[num]>=0&&dp[i-a[num]]!=-1){
                temp = dp[i-a[num]]*10+num;
                if(dp[i]==-1 ){
                    dp[i] = temp;
                }
                else if(temp!=0){
                        //16 - 5 =11
                    dp[i] = min(temp,dp[i]);
                }
            }
            if(i-a[0]>0 &&dp[i-a[0]]!=-1){
                temp = dp[i-a[0]]*10;
                if(dp[i]==-1 ){
                    dp[i] = temp;
                }
                else if(temp!=0){
                    dp[i] = min(temp,dp[i]);
                }
            }
        }
    }
    for(int i=1;i<=T;i++){
        cout<<dp[ans[i]]<<endl;
    }
    return 0;
}
