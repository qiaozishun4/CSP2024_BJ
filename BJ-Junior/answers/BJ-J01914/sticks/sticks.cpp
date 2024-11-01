#include<bits/stdc++.h>
using namespace std;
int t,n;
string dp[100001];
string num[10]={"qwq","awa","1","7","4","2","0","8"};
string smin(string x,string y){
    if(x.size()!=y.size()){
        return x.size()<y.size()?x:y;
    }
    return x<y?x:y;
}
void doit(){
    dp[2]="1";dp[3]="7";dp[4]="4";
    dp[5]="2";dp[6]="6";dp[7]="8";
    for(int i=8;i<=1001;i++){
        if(i!=8){
            dp[i]=dp[i-7]+num[7];
            for(int j=6;j>=2;j--){
                dp[i]=smin(dp[i],dp[i-j]+num[j]);
            }
        }else{
            dp[i]=dp[i-6]+num[6];
            for(int j=5;j>=2;j--){
                dp[i]=smin(dp[i],dp[i-j]+num[j]);
            }
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    doit();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==1){
            printf("10");
            for(int i=1;i<=n/7-1;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        cout<<(dp[n]==""?"-1":dp[n])<<"\n";
    }
    return 0;
}