#include<iostream>
using namespace std;
int ans=0;
int n;
int c[2005];
int a[2005];
void dfs(int x){
    if(x==n+1){
        int now=0;
    for(int i=1;i<=n;i++){
            int cc=0;
        for(int j=i;j>=1;j--){
            if(c[i]==c[j]){
                if(a[i]==a[j]){
                    cc=a[i];
                }
                break;
            }
        }
        now+=cc;
    }
        ans=max(ans,now);
        return ;
    }
    dfs(x+1);
    c[x]=1;
    dfs(x+1);
    c[x]=0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
           cin>>a[i];
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
