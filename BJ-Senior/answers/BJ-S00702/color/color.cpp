#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int ans[1000050];
int a[1000050];
map<pair<int,int>,int>dp[2050];
int f[2050];
inline pair<int,int>fix(pair<int,int>pr){
    if(pr.first>pr.second)swap(pr.first,pr.second);
    return pr;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;cin>>t;while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=2000){
            dp[0][make_pair(0,0)]=0;
            for(int i=1;i<=n;i++){
                dp[i].clear();
                for(auto x:dp[i-1]){
                    auto k=x.first;
                    int c=0;

                    if(k.first==a[i])c=a[i];
                    k.first=a[i];
                    k=fix(k);
                    dp[i][k]=max(dp[i][k],x.second+c);

                    k=x.first;
                    c=0;
                    if(k.second==a[i])c=a[i];
                    k.second=a[i];
                    k=fix(k);
                    dp[i][k]=max(dp[i][k],x.second+c);
                }
            }
            int ans=0;
            for(auto x:dp[n]){
                ans=max(ans,x.second);
            }
            cout<<ans<<endl;
        }else{
        }
    }
}
