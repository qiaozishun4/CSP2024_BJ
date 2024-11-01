#include <bits/stdc++.h>
using namespace std;
int n,a[15];
bool used[15];
int ans=-2147483647;
void dfs(int x){
    if(x==n+1){
        int ret=0;
        int p=0;
        for(int i=1;i<=n;i++){
            if(used[i])continue;
            if(p==0)p=i;
            else{
                ret+=(a[p]==a[i]?a[p]:0);
                p=i;
            }
        }
        p=0;
        for(int i=1;i<=n;i++){
            if(!used[i])continue;
            if(p==0)p=i;
            else{
                ret+=(a[p]==a[i]?a[p]:0);
                p=i;
            }
        }
        if(ans<ret){
            ans=ret;
            /*cout<<"red:";
            for(int i=1;i<=n;i++){
                if(used[i])cout<<i<<" ";
            }
            cout<<"\nblue:";
            for(int i=1;i<=n;i++){
                if(!used[i])cout<<i<<" ";
            }cout<<"\n\n";*/
        }
        return;
    }
    used[x]=true;
    dfs(x+1);
    used[x]=false;
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        //cout<<"\nlen:"<<n<<"\n";
        //cout<<"a[]:";
        //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        //cout<<"\n\n";
        dfs(1);
        cout<<ans<<"\n";
        ans=-2147483647;
    }
    return 0;
}