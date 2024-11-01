#include <bits/stdc++.h>
using namespace std;
int p[10]={6,2,5,5,4,5,6,3,7,6};
string dp[300050];
string Min(string a,string b){
    if(a=="-1")return b;
    if(b=="-1")return a;
    if(a.size()>b.size())return b;
    if(b.size()>a.size())return a;
    for(int xs=0;xs<a.size();xs++){
        if(a[xs]>b[xs])return b;
        if(b[xs]>a[xs])return a;
    }
    return a;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int xs=1;xs<=t;xs++){
        int n;
        cin>>n;
        dp[0]="";
        for(int xs2=1;xs2<=n;xs2++){
            dp[xs2]="-1";
            for(int xs3=0;xs3<10;xs3++){
                if((xs2!=6||xs3>0)&&(xs2>=p[xs3])){
                    if(dp[xs2-p[xs3]]!="-1")dp[xs2]=Min(dp[xs2],dp[xs2-p[xs3]]+char(xs3+'0'));
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
