#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[100005],cc[100005];
int n,lans=0;
void dfs(int now,int ans){
    if(now==n+1){
        lans=max(lans,ans);
        return;
    }
    cc[now]=0;
    int add=0;
    for(int i=now-1;i>=1;i--){
        if(a[i]==a[now]&&cc[i]==cc[now]){
            add=a[i];
            break;
        }
    }
    dfs(now+1,ans+add);
    cc[now]=1;
    add=0;
    for(int i=now-1;i>=1;i--){
        if(a[i]==a[now]&&cc[i]==cc[now]){
            add=a[i];
            break;
        }
    }
    dfs(now+1,ans+add);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        lans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,0);
        cout<<lans<<endl;
    }
    return 0;
}
