#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
int dp[N];
int f(int x){
    int tmp;
    while(x>0){
        tmp=x%10;
        x/=10;
    }
    return tmp;
}
int w(int x){
    int tmp=1;
    while(x>0){
        tmp++;
        x/=10;
    }
    return tmp;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=n;i++) dp[i]=1e6;
        for(int i=0;i<=n;i++){
            for(int j=9;j>=0;j--){
                if(i-a[j]>=0){
                    if(dp[i-a[j]]!=-1){
                        if(j>f(dp[i-a[j]])||j==0){
                            dp[i]=min(dp[i],dp[i-a[j]]*10+j);
                        }
                        else if(j!=0){
                            dp[i]=min(dp[i],dp[i-a[j]]+int(pow(10,w(dp[i-a[j]]))*j));
                        }
                    }
                    else{
                        if(i-a[j]==0&&j!=0) dp[i]=min(dp[i],j);
                    }
                }
            }
            if(dp[i]==1e6) dp[i]=-1;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}