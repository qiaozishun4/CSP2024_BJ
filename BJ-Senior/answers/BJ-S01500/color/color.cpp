#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e5+7;
ll n,a[maxn],dp[maxn][3],vis[maxn];
ll ans=0;
ll T;
void bo(ll x){
    ll id=0;
    while(x){
        vis[++id]=x&1;
        x>>=1;
    }
}
ll check(){
    ll res=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]==a[j]&&vis[i]==vis[j])
            {
                res+=a[i];
                break;
            }
        }
    }
    return res;
}

void meij(){
    for(int i=1;i<=(1<<n)-1;i++)
    {
        bo(i);
        ans=max(ans,check());
    }

}
void qingli1(){
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
    }
}
void qingli2(){
    for(int i=1;i<=n;i++){

        vis[i]=0;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
   {
       ans=0;
        qingli1();
        qingli2();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        meij();
        cout<<ans<<endl;
    }


    return 0;
}
