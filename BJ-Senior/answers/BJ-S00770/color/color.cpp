#include<bits/stdc++.h>
using namespace std;
int n;
int mu[101];
int a[101];
int mmax=0;
int check(){
    int sum=0;
    bool flag=0;
    for(int i=1;i<=n;i++){
        flag=0;
        for(int j=i-1;j>=1&&!flag;j--){
            if(mu[i]==mu[j]){
                flag=1;
                if(a[i]==a[j])sum+=a[j];
                break;
            }
        }
    }
    return sum;
}
void dfs(int now){
    if(now==n+1){
        mmax=max(mmax,check());
        return;
    }
    mu[now]=0;
    dfs(now+1);
    mu[now]=1;
    dfs(now+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        mmax=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<mmax<<endl;
    }
    return 0;
}
