#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
ll dp[2005][2005];
int n;
inline int p(int i,int j){
    if(j>n||i==0)return 0;
    return (a[i]==a[j])*a[j];
}
ll mx[2005];
void solve1(){
    dp[0][0]=0;
    for(int i=1;i<=n;i++)dp[0][0]+=p(i-1,i);
    ll ans=0;
    for(int i=1;i<=n;i++){
        mx[i]=0;
        for(int j=1;j<i;j++){
            dp[i][j]=dp[i-1][j]-p(i,i+1)-p(j-1,i)+p(j-1,i+1)+p(i-1,i);
            mx[i]=max(mx[i],dp[i][j]);
            //cout<<dp[i][j]<<" ";
        }
        dp[i][i]=dp[0][0]+p(i-1,i+1)-p(i-1,i)-p(i,i+1);
        for(int j=1;j<=i-2;j++){
            dp[i][i]=max(dp[i][i],mx[j]+p(i-1,i+1)+p(j,i)-p(i-1,i)-p(i,i+1));
        }
        //cout<<dp[i][i]<<"\n";
        mx[i]=max(mx[i],dp[i][i]);
        ans=max(ans,mx[i]);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=2000)solve1();
    }
    return 0;
}
/*
1
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
*/
