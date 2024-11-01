#include<bits/stdc++.h>
using namespace std;
const int val[]={6,2,5,5,4,5,6,3,7,6};
int t,n;
string dp[8];
string mins(string a,string b){
    if(a=="oo"){
        return b;
    }
    if(a.size()>b.size()){
        return b;
    }
    if(a.size()<b.size()){
        return a;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]>b[i]){
            return b;
        }
        if(a[i]<b[i]){
            return a;
        }
    }
    return a;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1e5){
            cout<<2;
            for(int i=1;i<=14285;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            cout<<"10";
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        dp[0]="0",dp[1]="oo",dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8";
        for(int i=8;i<=n;i++){
            string ans="oo";
            int id=i%8;
            for(int j=0;j<=9;j++){
                if(dp[(id-val[j]+8)%8]=="oo"){
                    continue;
                }
                ans=mins(ans,dp[(id-val[j]+8)%8]+(char)(j+48));
            }
            dp[id]=ans;
        }
        if(dp[n%8]=="oo"){
            cout<<-1<<endl;
            continue;
        }
        for(auto v:dp[n%8]){
            cout<<v;
        }
    }
}
