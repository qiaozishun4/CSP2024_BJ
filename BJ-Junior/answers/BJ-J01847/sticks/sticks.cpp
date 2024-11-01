#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a[]={"0","1","2","3","4","5","6","7","8","9"};
int v[]={6,2,5,5,4,5,6,3,7,6};
string dp[100001][2];
bool cmp(string a,string b){
    if(a.size()!=b.size()) return a.size()<b.size();
    else return a<b;
}
string min(string a,string b){
    if(cmp(a,b)) return a;
    else return b;
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=100000;i++) dp[i][0]=dp[i][1]="2147283647";
        dp[6][1]="0";
        for(int i=1;i<=9;i++){
            dp[v[i]][0]=a[i];
        }
        for(int i=0;i<=9;i++){
           for(int j=n;j>=v[i];j--){
                if(i==0) dp[j][1]=min(dp[j][1],min(a[i]+dp[j-v[i]][0],a[i]+dp[j-v[i]][1]));
                else dp[j][0]=min(dp[j][0],min(a[i]+dp[j-v[i]][0],a[i]+dp[j-v[i]][1]));
            }
        }
        if(dp[n][0]=="2147283647") puts("-1");
        else cout<<dp[n][0]<<endl;
    }
    return 0;
}