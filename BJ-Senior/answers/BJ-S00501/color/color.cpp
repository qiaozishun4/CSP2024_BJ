#include <bits/stdc++.h>
using namespace std;
long long ans,res=0,n;
struct node{
    long long va;
    bool co;
};
bool b[2]={1,1};
void maxn(vector< node> v){
    for(long long i=1;i<=n;i++){
        for(long long j=i-1;j>=1;j--){
            if(v[i].va==v[j].va&&v[i].co==v[j].co){
                ans+=v[i].va;
            }
        }
    }
    return;
}
void dfs(long long k,vector< node> v){
    if(k==n+1){
        maxn(v);
        res=max(res,ans);
        return;
    }
    for(int i=0;i<=1;i++){
        if(b[i]){
            b[i]=false;
            v[k].co=i;
            dfs(k+1,v);
            b[i]=true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        cin>>n;
        vector< node> v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i].va;
        }
        ans=0;
        dfs(1,v);
        cout<<res<<endl;
    }
    return 0;
}
