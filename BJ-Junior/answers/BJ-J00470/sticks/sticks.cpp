 #include<bits/stdc++.h>
using namespace std;
int T;
int a[10]={6,2,5,5,4,5,6,3,7,6};
string dp[100005],xsd;
int c,cjs;
string jh(int mg,int cen,bool ffd){
    if(mg==1||mg<0) return "-1";
    cjs=mg/7;
    if(mg%7) cjs++;
    if(cen+cjs>c) return "-1";
    if(!ffd&&mg==6) return "0";
    if(dp[mg].size()) return dp[mg];
    if(cen!=0){
        xsd=jh(mg-6,cen+1,0);
        if(xsd[0]!='-'){
            dp[mg]='0'+xsd;
            return dp[mg];
        }
    }
    char ccaf='1';
    for(int i=1;i<=9;i++){
        xsd=jh(mg-a[i],cen+1,0);
        if(xsd[0]!='-'){
            dp[mg]=ccaf+xsd;
            return dp[mg];
        }
        ccaf++;
    }
    return dp[mg];
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8";
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            continue;
        }
        c=n/7;
        if(n%7)c++;
        cout<<jh(n,0,1)<<'\n';
        for(int i=8;i<=100000;i++){
            dp[i]="";
        }
    }
    return 0;
}