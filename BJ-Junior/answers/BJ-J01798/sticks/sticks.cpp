#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int mu[10] = {6,2,5,5,4,5,6,3,7,6};
string dp[N];
string low[N];
int n,T;
void init(){
    dp[2]+="1",dp[3]+="7",dp[4]+="4",dp[5]+="2",dp[6]+="9",dp[7]+="8",dp[8]+="10";
    for(int i = 9;i<N-5;i++){
        int l = 2,r = i-2;
        dp[i] = dp[l]+dp[r];
        if(i%7==0){
            int len = i/7;
            dp[i] = "8";
            for(int j = 1;j<len;j++){
                dp[i]+="8";
            }
            //cout<<i<<' '<<dp[i]<<endl;
            continue;
        }else if(i%7==1){
            int len = i/7;
            dp[i] = "10";
            for(int j = 1;j<len;j++){
                dp[i]+="8";
            }
            //cout<<i<<' '<<dp[i]<<endl;
            continue;
        }
        while(l<=r){
            dp[i] = min(dp[i],dp[l]+dp[r]);
            dp[i] = min(dp[i],dp[r]+dp[l]);
            if(l==6)dp[i] = min(dp[i],dp[r]+'0');
            if(r==6)dp[i] = min(dp[i],dp[l]+'0');
            if(dp[l][0]=='9'){
                dp[l][0] = '0';
                dp[i] = min(dp[i],dp[r]+dp[l]);
                dp[l][0] = '9';
            }
            if(dp[r][0]=='9'){
                dp[r][0] = '0';
                dp[i] = min(dp[i],dp[l]+dp[r]);
                dp[r][0] = '9';
            }
            l++,r--;
        }
        //cout<<i<<' '<<dp[i]<<endl;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    bool op = false;
    while(T--){
        scanf("%d",&n);
        if(n==1){
            printf("-1\n");
        }else if(n%7==0){
            int len = n/8;
            for(int i = 1;i<=len;i++){
                printf("%d",8);
            }
            printf("\n");
            continue;
        }else if(n%7==1){
            int len = n/7;
            printf("10");
            for(int i = 1;i<len;i++){
                printf("%d",8);
            }
            printf("\n");
        }else{
            if(op==false){
                init();
                op = true;
            }
            cout<<dp[n]<<endl;
        }
    }

    return 0;
}
