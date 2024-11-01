#include<bits/stdc++.h>
using namespace std;
string dp[100005];
int T,n;
int need[10]={6,2,5,5,4,5,6,3,7,6};
int a[100005];
string strmin(string s1,string s2){
    if(s1=="-1"){
        return s2;
    }
    if(s1.size()!=s2.size()){
        if(s1.size()<s2.size()){
            return s1;
        }else{
            return s2;
        }
    }else{
        if(s1<s2){
            return s1;
        }else{
            return s2;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    int mx=-0x7f7f7f7f;
    for(int i=1;i<=T;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    dp[0]="";
    for(int i=1;i<=mx;i++){
        dp[i]="-1";
        for(int j=0;j<9;j++){
            if(i-need[j]<0 || dp[i-need[j]]=="-1" || (j==0 && dp[i-need[j]]=="")){
                continue;
            }
            string s2=dp[i-need[j]];
            s2.push_back(j+'0');
            dp[i]=strmin(dp[i],s2);
        }
    }
    for(int i=1;i<=T;i++){
        n=a[i];
        if(n==0){
            cout<<-1<<endl;
        }else{
            cout<<dp[n]<<endl;
        }
    }
    return 0;
}
