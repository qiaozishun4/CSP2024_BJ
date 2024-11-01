#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
ll t;
ll n,k,q,l[100005],s1;
ll r[100005],c[100005];
ll ans[15][200005];
vector<ll> s[100005];
ll maxn=0;
void dfs(ll p,ll la,ll pos){
    if(p>maxn){
        return;
    }
    ans[p][la]=1;
    for(int i=1;i<=n;i++){
        if(i==pos){
            continue;
        }
        for(int j=1;j<=l[i];j++){
            if(s[i][j]==la){
                for(int k1=j+1;k1<=min(ll(j+k-1),l[i]);k1++){
                    dfs(p+1,s[i][k1],i);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int t1=1;t1<=t;t1++){
        memset(ans,0,sizeof(ans));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            s[i].clear();
            s[i].push_back(0);
            for(int j=1;j<=l[i];j++){
                cin>>s1;
                s[i].push_back(s1);
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
            maxn=max(maxn,r[i]);
        }
        dfs(0,1,0);
        for(int i=1;i<=q;i++){
            cout<<ans[r[i]][c[i]]<<endl;
        }
    }
    return 0;
}
