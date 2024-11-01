#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,cnt,ans;bool flag[N];
void dfs(int step){
    if(step>=n){
        flag[step]=0;int ccnt=cnt;
        for(int i=step-1;i>=1;i--){
            if(flag[i]==flag[step]){
                if(a[i]==a[step])cnt+=a[i];break;
            }
        }
        //cout<<cnt<<"\n";
        //for(int i=1;i<=n;i++)cout<<flag[i]<<" ";
        //cout<<"\n";
        flag[step]=1;
        for(int i=step-1;i>=1;i--){
            if(flag[i]==flag[step]){
                if(a[i]==a[step])ccnt+=a[i];break;
            }
        }
        //cout<<ccnt<<"\n";
        //for(int i=1;i<=n;i++)cout<<flag[i]<<" ";
        //cout<<"\n";
        ans=max(ans,max(cnt,ccnt));
        return ;
    }
    flag[step]=0;int ccnt=cnt;
    for(int i=step-1;i>=1;i--){
        if(flag[i]==flag[step]){
                if(a[i]==a[step])cnt+=a[i];break;
            }
    }
    dfs(step+1);
    flag[step]=1;cnt=ccnt;
    for(int i=step-1;i>=1;i--){
        if(flag[i]==flag[step]){
                if(a[i]==a[step])cnt+=a[i];break;
            }
    }
    dfs(step+1);
}
void solve(){
    cin>>n;cnt=0,ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(flag,0,sizeof flag);
    if(n<=15){
        ans=0;dfs(1);
        cout<<ans<<"\n";
        return ;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])ans+=a[i];
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
