#include<bits/stdc++.h>
using namespace std;
int t,cl[100001],n,s[100001],dp[10001],same[100001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >>t;
    for(int i=0;i<t;i++){
        cin >>n;
        for(int i=0;i<=n;i++){
            cl[i]=0;
            s[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin >>s[i];
            same[i]=cl[s[i]];
            cl[s[i]]=i;
        }
        for(int i=1;i<=n;i++){
            if(same[i]){
                dp[i]=max(dp[same[i]+1]+s[i],dp[i-1]);
            }
            else dp[i]=dp[i-1];
        }
        cout <<dp[n-1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
