#include<bits/stdc++.h>
using namespace std;
int T,ans;
int a[105];int n;
bool b[105];
void dfs(int x){
    if(x==0){
        int blue=0,red=0,sum=0;
        for(int i=1;i<=n;i++){
            if(b[i]==1&&blue){
                if(a[i]==a[blue]) sum+=a[i];
            }
            else if(b[i]==0&&red){
                if(a[i]==a[red]) sum+=a[i];
            }
            if(b[i]) blue=i;
            else red=i;
        }
        ans=max(ans,sum);
        return ;
    }
    b[x]=1;
    dfs(x-1);
    b[x]=0;
    dfs(x-1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
            ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(n);
        cout<<ans<<'\n';
    }
    return 0;
}
