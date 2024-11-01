#include<bits/stdc++.h>
using namespace std;
int num[] = {0,6,2,5,5,4,5,6,3,7,6};
int k[] = {0,2,3,4,5,6,7};
int e[] = {0,1,7,4,2,0,8};
int e0[] = {0,1,7,4,2,6,8};
const int MAXN = 1e5+10;
int T,n;
int dp[MAXN];
int add(int x,int y){
    int b[MAXN],len=0;
    int ax = x;
    while(ax>0){
        b[++len] = ax%10;
        ax/=10;
    }
    b[++len] = y;
    sort(b+1,b+1+len);
    int i=1;
    while(b[i]==0){
        i++;
    }
    swap(b[i],b[1]);
    int res=0;
    for(int i=1;i<=len;i++){
        res+=pow(10,i-1)*b[len-i+1];
    }
    return res;
}//to add one particular number to one number.
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            dp[i] = -1;
        }
        dp[0] = 0;
        for(int i=1;i<=6;i++){
            dp[k[i]] =e0[i];
        }
        for(int i=1;i<=6;i++){
            for(int j=1;j<=n;j++){
                if(j-k[i]>0&&dp[j-k[i]]>0){
                        if(dp[j]>=0){
                    dp[j] = min(dp[j],add(dp[j-k[i]],e[i]));
                    }
                    else{
                        dp[j] = add(dp[j-k[i]],e[i]);
                    }
            }
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}