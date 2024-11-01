#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200000+10],ans;
bool b[200000+10];
void dfs(int step){
    if(step==n+1){
        int z=0;

        for(int i=1;i<=n;i++){
            int v=i-1;
            while(v--){
                if(b[v]==b[i]){
                    if(a[i]==a[v])z+=a[i];
                    break;
                }
            }

        }
        if(z>ans)ans=z;
        return;

    }
    b[step]=1;
    dfs(step+1);
    b[step]=0;
    dfs(step+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
