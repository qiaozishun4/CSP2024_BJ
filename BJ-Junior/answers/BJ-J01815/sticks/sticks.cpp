#include<bits/stdc++.h>
using namespace std;
//         indexes  0, 1,  2,  3,  4,  5,  6,  7, X
string dp[100005]={"","","1","7","4","2","0","8"};
int dpl=7;
bool cmp(string a,string b){
    if(b=="?")
        return true;
    if(a.size()!=b.size())
        return a.size()<b.size();
    return a<b;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         for(int i=dpl+1;i<=n;i++,dpl++){
                string minn="?";
                if(i==n)
                    dp[6]="6";
                for(int j=2;j<=7;j++){
                    if(dp[i-j]==""&&i-j>0)
                        continue;
                    if(cmp(dp[j]+dp[i-j],minn))
                        minn=dp[j]+dp[i-j];
                }
                if(minn=="?")
                    dp[i]="";
                else
                    dp[i]=minn;
                //printf("dp[i:%d]:\"%s\"\n",i,dp[i].c_str());
         }
         if(dp[n]=="")
            puts("-1");
         else{
            if(dp[n][0]=='0')
                puts(('6'+dp[n].substr(1,dp[n].size()-1)).c_str());
            puts(dp[n].c_str());
         }
    }
    return 0;
}
