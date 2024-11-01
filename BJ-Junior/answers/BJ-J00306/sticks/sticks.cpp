#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100005];
int s1[10]={0,0,1,7,4,2,6,8};
int s2[10]={0,0,1,7,4,3,0,8};
int t;
string ans;
string box;

bool cmp(string sum1,string sum2){
    if(sum1.size()!=sum2.size()) return sum2.size()<sum1.size();
    for(int i=0;i<sum1.size();i++)
        if(sum1[i]!=sum2[i]) return sum2[i]<sum1[i];
    return 0;
}

void dfs(int cur,int left,string box){
    if(left<0) return ;
    if(left==0){
        //cout<<box<<endl;
        if(cmp(ans,box)) ans=box;
        return ;
    }
    if(cur==1){
        for(int i=2;i<=7&&left>=i;i++){
            dfs(2,left-i,to_string(s1[i]));
        }
    }
    else{
        for(int i=2;i<=7&&left>=i;i++){
            dfs(cur+1,left-i,box+to_string(s2[i]));
        }
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    dp[1]=10;
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=6;
    dp[7]=8;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=100000;i++) ans+="9";
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n<=25){
            dfs(1,n,"");
            cout<<ans<<endl;
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
        }
        else if(n%7==1&&n>1){
            cout<<10;
            for(int i=1;i<n/7;i++) cout<<8;
            cout<<endl;
        }
        else{
            for(int i=0;i<=7&&i*6<=n-2;i++){//枚举0的个数
                int sum=i,n1=n;
                n1-=i*6;
                string ans1;
                if(n1%7==0) {
                    ans1="8";
                    n1-=7;
                }
                else if(n1%7==1){
                    ans1=to_string(dp[1]);
                    n1-=8;
                }
                else{
                    ans1=to_string(dp[n1%7]);
                    n1-=n1%7;
                }
                for(int j=1;j<=sum;j++) ans1+="0";
                for(int j=1;j<=n1/7;j++) ans1+="8";
                if(cmp(ans,ans1)) ans=ans1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
