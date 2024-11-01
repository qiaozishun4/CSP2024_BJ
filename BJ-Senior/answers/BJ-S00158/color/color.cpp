#include<bits/stdc++.h>
using namespace std;
int t,n,ans,mans;
int a[200005],b[200005];
int dfs(int s,int rl,int bl){
    if(s>n){
        mans=max(mans,ans);
        return 0;
    }
    if(a[s]==rl){
        ans+=a[s];
        dfs(s+1,a[s],bl);
        ans-=a[s];
    }
    else{
        dfs(s+1,a[s],bl);
    }
    b[s]=1;
    if(a[s]==bl){
        ans+=a[s];
        dfs(s+1,rl,a[s]);
        ans-=a[s];
    }
    else{
        dfs(s+1,rl,a[s]);
    }
    b[s]=0;
    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        dfs(1,-1,-1);
        cout<<mans<<" ";
        mans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}