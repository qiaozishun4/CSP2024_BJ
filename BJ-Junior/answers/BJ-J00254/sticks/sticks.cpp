#include <bits/stdc++.h>
using namespace std;
const int sum[10]={6,2,5,5,4,5,6,3,7,6};
long long dp[100010],dp2[100010];
long long combine(int i,int j){
    int w=10;
    long long k=dp[i-sum[j]];
    while(k>=w)w*=10;
    return w*j+dp2[i-sum[j]];
}
long long gmax(int i){
    long long minn=LONG_MAX;
    for(int j=1;j<=9;++j){
        if(dp[i-sum[j]]==-1)continue;
        if(i-sum[j]>(i-1)/7*7)continue;
        long long n=combine(i,j);
        //if(i==15)printf("%d,%d->%lld\n",i,j,n);
        minn=minn<n?minn:n;
    }
    return minn;
}
long long gmax_0(int i){
    long long minn=LONG_MAX;
    for(int j=0;j<=9;++j){
        if(dp[i-sum[j]]==-1)continue;
        if(i-sum[j]>(i-1)/7*7)continue;
        long long n=combine(i,j);
        minn=minn<n?minn:n;
    }
    return minn;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
    dp[1]=-1;
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=0;
    dp[7]=8;
    dp2[1]=-1;
    dp2[2]=1;
    dp2[3]=7;
    dp2[4]=4;
    dp2[5]=2;
    dp2[6]=0;
    dp2[7]=8;
        int n;
        cin>>n;
        for(int i=8;i<=n;++i){
            dp[i]=gmax(i);
            dp2[i]=gmax_0(i);
            //cout<<dp[i]<<" ";
        }
        if(n==6)cout<<6<<endl;
        else if(n%7==0){
            for(int i=0;i<n;i+=7){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<10;
            for(int i=0;i<n-8;i+=7){
                cout<<8;
            }
            cout<<endl;
        }
        else cout<<dp[n]<<endl;
    }
    return 0;
}
