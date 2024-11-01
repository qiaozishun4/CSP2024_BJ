#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
long long n[1000+10],m,t,dp[100000+10],maxn;   //mem:qwq?
int dic[1000]={6,2,5,-1,4,-1,6,3,7,-1};
bool flag1=true,flag2=true;
//6,2,5,5,4,5,6,3,7,6
void mmst(){
    for (int i=0;i<=maxn;i++) dp[i] = 461168601842738790;
}
void cheat1(){
    for (int i=1;i<=t;i++){
        for (int j=1;j<=n[i]/7;j++) printf ("8");
        printf ("\n");
    }
}
void cheat2(){
    for (int i=1;i<=t;i++){
        printf ("10");
        for (int j=1;j<=((n[i]-1)/7)-1;j++) printf ("8");
        printf ("\n");
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf ("%lld", &t);
    for (int i=1;i<=t;i++){
        scanf ("%d", &n[i]);
        maxn = maxn<n[i]?n[i]:maxn;
        if (n[i]%7!=0) flag1 = false;
        if ((n[i]-1)%7!=0) flag2 = false;
    }
    if (flag1){
        cheat1();
        return 0;
    }
    if (flag2){
        cheat2();
        return 0;
    }
    mmst();
    dp[0] = dp[1] = 0;
    for (int i=2;i<=maxn;i++){ //stick number
        for (int j=0;j<=9;j++){
            if (dic[j]==i&&j!=0){
                dp[i] = j;
                break;
            }
            if (i-dic[j]<0) continue;   //not enough
            if (dp[i-dic[j]]==0) continue;   //can't select this number because previous is error(like 1 or 0)
            if (dic[j]==-1) continue;   //never choose this number
            if (dp[i]>dp[i-dic[j]]*10+j){
                dp[i] = dp[i-dic[j]]*10+j;
            }
        }
    }
    for (int i=1;i<=t;i++){
        if (dp[n[i]]==0){
            printf ("-1\n");
            continue;
        }
        printf ("%lld\n", dp[n[i]]);
    }
    return 0;
}
