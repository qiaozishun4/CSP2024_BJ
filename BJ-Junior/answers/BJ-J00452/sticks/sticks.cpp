#include<bits/stdc++.h>
#define int long long
using namespace std;
string dp[100005];
int n;
int num[11]={6,2,5,5,4,5,6,3,7,6};
string c[11]={"0","1","2","3","4","5","6","7","8","9"};
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    dp[1]="-1";
    dp[2]="1";
    dp[3]="7";
    dp[4]="4";
    dp[5]="2";
    dp[6]="6";
    dp[7]="8";
    while(t--){
        cin>>n;
        for(int i=8;i<=n;i++){
            for(int j=0;j<=9;j++){
                if(j==8&&i==8) continue;
                string s1=dp[i];
                string s2=dp[i-num[j]]+c[j];
                int len1=s1.size();
                int len2=s2.size();
                if(len1==0){
                    dp[i]=s2;
                    continue;
                }
                if(len1!=len2){
                    if(len1<len2){
                        continue;
                    }else{
                        dp[i]=s2;
                        continue;
                    }
                }else{
                    if(s1>s2){
                        dp[i]=s2;
                        continue;
                    }else{
                        continue;
                    }
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
