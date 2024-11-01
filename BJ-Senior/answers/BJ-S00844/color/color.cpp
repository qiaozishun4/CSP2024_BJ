#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool dis[200010];
int near_r[200010];
int near_b[200010];
int ans=0;
void dfs(int now,int &n){
    if(now>n){
        int k=0;
        for(int i=1;i<=n;i++)
        if(dis[i]==1){
            if(a[near_r[i-1]]==a[i])k+=a[i];
        }else{
            if(a[near_b[i-1]]==a[i])k+=a[i];
        }
        ans=max(ans,k);
    }else{
        dis[now]=1;
        near_r[now]=now;
        near_b[now]=near_b[now-1];
        dfs(now+1,n);
        dis[now]=0;
        near_b[now]=now;
        near_r[now]=near_r[now-1];
        dfs(now+1,n);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        dfs(1,n);
        cout<<ans<<endl;
    }
    return 0;
}
