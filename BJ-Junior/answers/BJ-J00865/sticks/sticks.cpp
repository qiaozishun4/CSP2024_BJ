#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3;
bool smth(const string &a,const string &b){
    if(b=="-1") return true;
    if(a.size()!=b.size()) return a.size()<b.size();
    return a<b;
}
int t,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
string dp[MAXN+15]={"0","-1","1","7","4","2","6","8"};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=8;i<=MAXN;i++){
        dp[i]="-1";
        for(int j=0;j<10;j++){
            if(dp[i-a[j]]=="-1") continue;
            if(smth(dp[i-a[j]]+(char)(j+'0'),dp[i])) dp[i]=dp[i-a[j]]+(char)(j+'0');
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}
