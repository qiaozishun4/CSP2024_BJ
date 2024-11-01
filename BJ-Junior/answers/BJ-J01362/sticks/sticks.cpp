#include <bits/stdc++.h>

using namespace std;
int st[10]={6,2,5,5,4,5,6,3,7,6};
string dp[100001];
string Min(string a,string b){
    int la=a.size(),lb=b.size();
    if(la==0)return b;

    if(la<lb)return a;
    if(la>lb)return b;
    for(int i=0;i<la;i++){
        if(a[i]<b[i])return a;
        if(a[i]>b[i])return b;
    }
    return a;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=0;i<=1000;i++)dp[i]="";
    for(int i=2;i<=1000;i++){
        if(i-st[0]>1)dp[i]=dp[i-st[0]]+'0';
        for(int j=1;j<10;j++){
            if((i-st[j]>=0)&&(i-st[j]!=1)){
                dp[i]=Min(dp[i],Min(dp[i-st[j]]+char('0'+j),char('0'+j)+dp[i-st[j]]));

            }
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        if(n<=1)cout<<-1<<endl;
        else if(n<=1000)cout<<dp[n]<<endl;
    }
    return 0;
}

