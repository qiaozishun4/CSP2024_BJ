#include<bits/stdc++.h>
using namespace std;

int n,t,a[20],ans;
bool ch[20];
void dfs(int x){
    if(x>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>0;j--){
                if(ch[i]==ch[j]){
                    if(a[i]==a[j])sum+=a[i];
                    break;
                }
            }
        }
        ans=max(sum,ans);
        return;
    }
    ch[x]=0;
    dfs(x+1);
    ch[x]=1;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
