#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,4,5,6,3,7,6};
int dp[100007];
int minn = 1e9;
void dfs(int n,int d,int t){
    if(n==0){
        minn = min(minn,d);
        return;
    }
    if(n==1) return;
    if(dp[n]!=0x3f3f3f3f){
        minn = min(minn,dp[n]+d)
    }
    if(d!=0 && n>=6){
        dfs(n-a[0],d*10,t+1);
    }
    for(int i=1;i<=9;i++){
        dfs(n-a[1],d*10+i,t+1);
        dfs(n-a[1],d+pow(10,t+1)*i,t+1);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        minn = 1e9;
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dfs(n,0);
        cout << minn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}