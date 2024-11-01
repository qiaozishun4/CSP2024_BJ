#include<iostream>
using namespace std;

#define ll long long
const int maxn=1e6+10;
const ll inf=1e12;
int T,n,ai[maxn],mx;
ll dp[maxn],add,dpmx;

int score(int i, int j){
    return (ai[i]==ai[j])*ai[i];
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin>>T;
    while(T--){
        cin>>n; mx=dpmx=add=0;
        for(int i=1;i<=n;i++)cin>>ai[i],mx=max(mx,ai[i]);
        for(int j=1;j<=mx;j++)dp[j]=-inf;
        for(int i=2;i<=n;i++){
            dp[ai[i-1]]=max(max(dp[ai[i-1]]+add, dp[ai[i]]+ai[i]+add), dpmx+add)-add-score(i,i-1);
            add+=score(i,i-1); dpmx=max(dpmx, dp[ai[i-1]]);
        }
        cout<<dpmx+add<<endl;
    }
}