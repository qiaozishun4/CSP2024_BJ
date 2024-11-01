#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM
int t,n,a[MAXN];
ll mx;
void dfs(int now,int b,int r,ll sum){
    if(now==n+1){
        mx=max(mx,sum);
        return ;
    }
    if(b==a[now] or r==a[now]){
        dfs(now+1,b,r,sum+a[now]);
        return ;
    }
    dfs(now+1,a[now],r,sum);
    dfs(now+1,b,a[now],sum);
    return ;
}
void init(){
    cin>>t;
    while(t--){
        mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        dfs(1,0,0,0);
        cout<<mx<<endl;
    }
    return ;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    init();
    return 0;
}