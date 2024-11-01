#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[20005];
bool vis[20005];
void dfs(int d){
    if(d>n){
        int s=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(vis[i]==vis[j]){
                    if(a[i]==a[j]) s+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,s);
        return ;
    }
    for(int i=0;i<=1;i++){
        vis[d]=i;
        dfs(d+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}

