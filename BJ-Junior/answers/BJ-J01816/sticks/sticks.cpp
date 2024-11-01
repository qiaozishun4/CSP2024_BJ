#include<iostream>
#include<cstring>
using namespace std;
const int N=131072;
const int num[]={6,2,5,5,4,5,6,3,7,6};
int t,n,dp[N],last[N],len[N];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[1]=len[1]=last[1]=0x3f3f3f3f;
        for(int i=2;i<=n;i++){
            dp[i]=1;
            last[i]=i-2;
            len[i]=len[i-2]+1;
            for(int j=0;j<=9;j++)
                if(i>=num[j])
                    if(len[i]>len[i-num[j]]+1){
                        dp[i]=j;
                        last[i]=i-num[j];
                        len[i]=len[i-num[j]]+1;
                    }
                    else if(len[i]==len[i-num[j]]+1&&dp[i]>j){
                        dp[i]=j;
                        last[i]=i-num[j];
                    }
        }
        int mlen=(n+6)/7,minid=0;
        for(int i=1;i<=9;i++){
            if(n>=num[i]&&len[n-num[i]]+1==mlen){
                cout<<i;
                minid=n-num[i];
                break;
            }
        }
        while(minid){
            cout<<dp[minid];
            minid=last[minid];
        }
        cout<<endl;
    }
    return 0;
}