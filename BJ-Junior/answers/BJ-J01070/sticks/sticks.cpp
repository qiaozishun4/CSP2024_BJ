#include <bits/stdc++.h>

using namespace std;

int getmax(int n){
    int ret = 1;
    int ans = 0;
    while(ret < n){
        ans++;
        ret*=10;
    }
    return ans;
}

//int fp(int a,int b){
//int c = a;
    //while(b){
        //if(b&1){
            //a*=c;
            //b-1;
        //}
       // if(b){
          //  a*=a;
        //    b/=2;
        //}
   // }
 //   return a;
//}

int pow(int a,int b){
    int c = a;
    while(b){
        a*=c;
        b--;
    }
    return a;
}

long long dp[100010] = {0,0,1,7,4,2,6,8};
int num[11] = {6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 3; i <= 10000; i++){
        if(!dp[i]) dp[i] = -114515554;
    }
    dp[50] = -1;
    for(int i = 1; i <= 49; i++){
        if(dp[i] == -114515554){
            //cout << i << '\n';
            dp[i] = 1e9;
            for(int j = 0; j <= 9; j++){
                if(j == 0 && i >=6){
                    dp[i] = min(dp[i-6]*10,dp[i]);
                }
                else {
                    int maxbit = getmax(dp[i-num[j]]);
                    if(i >= num[j]);
                    dp[i] = min(dp[i-num[j]]*10+j,min(dp[i-num[j]]+j * pow(10,maxbit),dp[i]));
                }
            }
        }
    }
    for(int Q = 1; Q <= t; Q++){
        int n;
        cin >> n;
    if(n <= 50) cout << dp[n];
    else{
        int ex = n/8;
        cout <<ex;
        int eee = n-ex*8;
        cout <<eee;
        int eex = dp[eee];
        if(eex < 8) cout << eex;
        for(int i = 1; i <= ex; i++) cout << 8;
        if(eex >= 8) cout << eex;
        cout << '\n';
    }
    }
    return 0;
}
