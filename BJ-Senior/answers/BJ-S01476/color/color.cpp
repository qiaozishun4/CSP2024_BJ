#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[2000010],dp[2][2000010],b[200010],p;
set<ll,greater<ll>> heng,shu;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ll B=-1;
        ll ans1=0;p=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            B=max(B,a[i]);
            dp[0][a[i]]=dp[1][a[i]]=-1e13;
            if(a[i]!=a[i-1])    b[++p]=a[i];
            else    ans1+=a[i];
        }
        n=p;
        for(int i=1;i<=n;i++)   a[i]=b[i];
        heng.clear();shu.clear();
        dp[0][0]=dp[1][0]=0;
        heng.insert(-1e13);shu.insert(-1e13);
        heng.insert(0);shu.insert(0);
        for(int i=2;i<=n;i++){
            ll mx0=*heng.begin(),mx1=*shu.begin();
            ll sv1=max(dp[1][a[i-1]],max(mx0,dp[0][a[i]]+a[i]));
            ll sv0=max(dp[0][a[i-1]],max(mx1,dp[1][a[i]]+a[i]));
            dp[1][a[i-1]]=sv1;dp[0][a[i-1]]=sv0;
            //if(heng.count(dp[0][a[i-1]]))  heng.erase(heng.find(dp[0][a[i-1]]));
            //if(shu.count(dp[1][a[i-1]]))  shu.erase(shu.find(dp[1][a[i-1]]));
            heng.insert(sv0);shu.insert(sv1);
            /*
            cout<<"heng : "<<endl;
            for(int j=0;j<=B;j++)   cout<<dp[0][j]<<" ";cout<<endl;
            cout<<"shu : "<<endl;
            for(int j=0;j<=B;j++)   cout<<dp[1][j]<<" ";cout<<endl;
            */
        }
        ll ans2=0;
        for(int i=0;i<=B;i++){
            ans2=max(ans2,max(dp[0][i],dp[1][i]));
        }
        cout<<ans1+ans2<<endl;
    }
    return 0;
}