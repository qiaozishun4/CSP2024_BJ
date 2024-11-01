//T1
#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar((x%10)^48);
}
const ll maxn=1e5+5;
ll n,arr[maxn],mxnum;
namespace cod1{
    bool isac[maxn],isdn[maxn];
    ll ans=n;
    bool isend(){
        for(int i=1;i<=n;i++){
            if(!isac[i] && !isdn[i]){
                return false;
            }
        }
        return true;
    }
    bool iseq(){
        ll eqy=-1;
        for(int i=1;i<=n;i++){
            if(!isdn[i] && !isac[i]){
                eqy=arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(!isdn[i] && !isac[i]){
                if(arr[i]!=eqy){
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(ll nw){
        if(isend() || iseq()){
            ans=min(ans,nw);
            return;
        }
        for(int i=1;i<=n;i++){
            if(!isdn[i]){
                for(int j=i+1;j<=n;j++){
                    if(!isac[j] && !isdn[j] && i!=j && arr[j]>arr[i]){
                        isdn[i]=true;
                        isac[j]=true;
                        dfs(nw-1);
                        isac[j]=false;
                        isdn[i]=false;
                    }
                }
            }
        }
    }
    void work(){
        ans=n;
        dfs(n);
        print(ans);
    }
}
namespace cod2{
    ll cnt1,cnt2;
    void work(){
        cnt1=0;
        cnt2=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==1)cnt1++;
            if(arr[i]==2)cnt2++;
        }
        if(cnt1>cnt2)print(n-cnt2);
        else print(n-cnt1);
    }
}
namespace cod3{
    ll tong[maxn],maxx;
    void work(){
        for(int i=1;i<=n;i++){
            maxx=max(maxx,arr[i]);
            tong[arr[i]]++;
        }
        ll sum=0;
        for(int i=1;i<=n;i++){
            if(tong[i]>=sum){
                sum=tong[i];
            }
        }
        print(sum);
    }
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        arr[i]=read();
        mxnum=max(arr[i],mxnum);
    }
    sort(arr+1,arr+n+1);
    if(n<=10)cod1::work();
    else if(mxnum<=2){
        cod2::work();
    }else {
        cod3::work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
