#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1007;
bool vis[maxn];
string dp[maxn];
string dp0[maxn];
char val[7]={'0','1','2','4','6','7','8'};
int cnt[7]={6,2,5,4,6,3,7};
int K(string S){
    int ans=0;
    for(auto ch:S){
        for(int j=0;j<7;j++){
            if(ch==val[j])ans+=cnt[j];
        }
    }
    return ans;
}
string Min0(string S,string T){
    if(S[S.size()-1]=='a')return T;
    if(T[T.size()-1]=='a')return S;
    if(S.size()!=T.size())return (S.size()<T.size()?S:T);
    int L=S.size();
    for(int i=0;i<L;i++)if(S[i]!=T[i])return (S[i]<T[i]?S:T);
}
inline void init(){
    dp[0]=dp0[0]="";
    dp[1]=dp0[1]="a";
    for(int i=2;i<=1000;i++){
        dp0[i]=dp[i]='a';
        if(i>=cnt[0])dp0[i]=Min0('0'+dp0[i-cnt[0]],'0'+dp[i-cnt[0]]);
        for(int j=1;j<7;j++){
            if(i>=cnt[j])dp[i]=Min0(dp[i],val[j]+Min0(dp0[i-cnt[j]],dp[i-cnt[j]]));
        }
    }
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    init();
    int T=0;
    cin>>T;
    while(T--){
        int n=0;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n<=1000){
            cout<<dp[n]<<endl;
            continue;
        }
        int rem=n%840;
        if(rem==1){
            cout<<dp[421];
            int k=(n-421)/420;
            for(int i=1;i<=k;i++)cout<<dp[420];
            cout<<endl;
        }
        else{
            cout<<dp[rem];
            int k=(n-rem)/420;
            for(int i=1;i<=k;i++)cout<<dp[420];
            cout<<endl;
        }
        
    }
}