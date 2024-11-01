//T3
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
const ll maxn=2e5+5;
ll T,n,arr[maxn];
namespace cod1{
    bool isred[maxn];
    ll ans=0;
    ll cntc(){
        ll ret=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(isred[i]==isred[j] && arr[i]==arr[j]){
                    ret+=arr[i];
                }
            }
        }
        return ret;
    }
    void dfs(ll cur){
        if(cur>n){
            ans=max(ans,cntc());
            return;
        }
        isred[cur]=true;
        dfs(cur+1);
        isred[cur]=false;
        dfs(cur+1);
    }
    void work(){
        ans=0;
        dfs(0);
        print(ans);
        putchar('\n');
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            arr[i]=read();
        }
        cod1::work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
