#include<bits/stdc++.h>
using namespace std;
int a[200010];bool c[200010];long long ans=0;
long long score(int n){
    int near[2]={0,0},ans=0;
    for(int i=1;i<=n;i++){
        if(a[near[c[i]]]==a[i])ans+=a[i];
        near[c[i]]=i;
    }
    return ans;
}
void dfs(int cl,int n){
    if(cl>(n+1))return;
    if(cl==(n+1)){
        ans=max(ans,score(n));
    }else{
        c[cl]=0;
        dfs(cl+1,n);
        c[cl]=1;
        dfs(cl+1,n);
    }
    return;
}
void Main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans=0;
    dfs(1,n);
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)Main();
    return 0;
}
