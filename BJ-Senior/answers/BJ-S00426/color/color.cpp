#include<bits/stdc++.h>
using namespace std;
int T,n,a[200001],ans;
void dfs(int x,int z,int re,int blu){
    if(x==n){
        ans=ans>z?ans:z;
        return;
    }
    int i=x+1;
    if(a[i]==re||a[i]==blu){
        dfs(x+1,z+a[i],re,blu);
        return;
    }
    dfs(x+1,z,a[i],blu);
    dfs(x+1,z,re,a[i]);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        ans=0;
        dfs(0,0,0,0);
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
