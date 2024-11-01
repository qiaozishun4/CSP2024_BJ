#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
int a[MAX],d[MAX],n,C[MAX],ans;
void dfs(int now,int c){
    d[now]=c;
    if(now==n){
        memset(C,0,sizeof(C));
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(d[i]==d[j]){
                    if(a[i]==a[j])C[i]=a[i];
                    break;
                }
            }
            C[i]+=C[i-1];
        }
        ans=max(ans,C[n]);
        return;
    }
    dfs(now+1,0);
    dfs(now+1,1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)cin>>a[i];
        ans=0;
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
