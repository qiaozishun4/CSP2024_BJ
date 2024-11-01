#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n,ans=-1;
void dfs(int lb,int lr,int c,int now){
    if(now==n+1){
        ans=max(ans,c);
        return ;
    }
    int k=0;
    if(!k){
        if(a[now]!=a[lb]) dfs(now,lr,c,now+1);
        else dfs(now,lr,c+a[now],now+1);
        k=1;
    }
    if(k){
        if(a[now]!=a[lr]) dfs(lb,now,c,now+1);
        else dfs(lb,now,c+a[now],now+1);
    }

}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=-1;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(0,0,0,1);
        cout<<ans<<endl;
    }
    return 0;
}
