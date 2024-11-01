#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200005],maxc;
bool f[200005];
void dfs(int x,int sum){
    if(x>n){maxc=max(maxc,sum);return;}
    int i;
    f[x]=true;
    for(i=x-1;i>0 and !f[i];i--);
    dfs(x+1,sum+(a[x]==a[i])*a[x]);
    f[x]=false;
    for(i=x-1;i>0 and f[i];i--);
    dfs(x+1,sum+(a[x]==a[i])*a[x]);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        maxc=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n<=15) dfs(1,0);
        else maxc=0;
        cout<<maxc<<endl;
    }
    return 0;
}