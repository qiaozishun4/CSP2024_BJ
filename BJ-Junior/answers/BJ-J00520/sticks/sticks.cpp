#include<bits/stdc++.h>
using namespace std;
int t,n;
string dp[100001];
bool cnt[100001];
int g[10]={6,2,5,5,4,5,6,3,7,6};
bool cup(string a,string b){
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    if(a>b) return 1;
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=100000;++i){
        cnt[i]=1;
        for(int j=0;j<=9;++j){
            char x='0'+j;
            int u=i-g[j];
            if(u<0||cnt[u]) continue;
            if(u==0&&j==0) continue;
            if(cnt[i]) cnt[i]=0,dp[i]=dp[u]+x;
            else if(cup(dp[i],dp[u]+x)) dp[i]=dp[u]+x;
        }
    }
    while(t--){
        cin>>n;
        if(cnt[n]) cout<<-1<<endl;
        else cout<<dp[n]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
