#include<bits/stdc++.h>
using namespace std;
int n,t,a[1000001],b[1000001],ans,m;
void dfs(int s){
    if(s>n){
        int c=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j;j--){
                if(b[i]==b[j]){
                    if(a[i]==a[j])c+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,c);
        return;
    }
    b[s]=0;
    dfs(s+1);
    b[s]=1;
    dfs(s+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(b,0,sizeof b);
        ans=0;
        dfs(1);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
