#include<bits/stdc++.h>
using namespace std;
const int maxn=120;
string inf;
int t,n;
string dp[maxn][11],ans;
int st[]={6,2,5,5,4,5,6,3,7,6};
string strmin(string a,string b){
    if(a.length()>b.length()) return b;
    if(a.length()<b.length()) return a;
    return min(a,b);
}
void init(){
    inf="888";
    for(int i=0;i<10000;i++) inf+="88888";
    for(int i=0;i<maxn-7;i++){
        if(i==0) for(int j=0;j<10;j++) dp[i][j]=" ";
        else for(int j=0;j<10;j++) dp[i][j]=inf;
    }
    for(int i=0;i<maxn-8;i++){
        for(int j=0;j<10;j++){
            if(i-st[j]<0 || (i-st[j]==0 && j==0)) continue;
            for(int la=0;la<10;la++){
                dp[i][j]=strmin(dp[i][j],dp[i-st[j]][la]+char(j+'0'));
            }
        }
    }
    return;
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    init();
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=110){
            ans=dp[n][0];
            for(int i=0;i<=9;i++) ans=strmin(ans,dp[n][i]);
            if(ans==inf) cout<<-1<<endl;
            else cout<<ans.substr(1,ans.length()-1)<<endl;
        }else if(n%7==0){
            cout<<inf.substr(0,n/7)<<endl;
        }else if(n%7==1){
            cout<<10<<inf.substr(0,n/7-1)<<endl;
        }
    }
    return 0;
}
