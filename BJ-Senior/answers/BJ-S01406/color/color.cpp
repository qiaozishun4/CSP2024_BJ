#include<bits/stdc++.h>
using namespace std;
int s,n,a[200005],maxn=-1e9;
bool b[200005];
bool jocker(int x){
for(int i=1;i<=n;i++){
    if(b[i]==x){
        return false;
    }
}
return true;
}
int dfs(int u){
    if(u>n){
        int ans=0;
        for(int i=2;i<=n;i++){
            if(jocker(b[i])){
                ans=ans+0;
            }
            else{
                for(int j=i-1;j>=1;j--){
                    if(b[j]==b[i]&&a[j]==a[i]){
                            cout<<b[j]<<" "<<b[i]<<" "<<a[j]<<" "<<a[i]<<endl;
                        ans=ans+a[i];
                    }
                }
            }
        }
        maxn=max(maxn,ans);
        return maxn;
    }
    b[u]=1;
    dfs(u+1);
    b[u]=0;
    dfs(u+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios sync_with_std(0);
    cin.tie(0);cout.tie(0);
cin>>s;
while(s--){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
    }
    cout<<dfs(1)<<endl;

}
return 0;
}
