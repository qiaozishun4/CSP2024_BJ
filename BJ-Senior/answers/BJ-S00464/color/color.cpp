#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;

int t;
int n;
int a[maxn];
int c[maxn];

int r[maxn],b[maxn];
ll ans;

void cc(){
    ll s=0;
    int l1=0,l2=0;
    for(int i=1;i<=n;i++){
        if(c[i])r[++l1]=i;
        else b[++l2]=i;
    }
    for(int i=2;i<=l1;i++)if(a[r[i]]==a[r[i-1]])s+=a[r[i]];
    for(int i=2;i<=l2;i++)if(a[b[i]]==a[b[i-1]])s+=a[b[i]];
    ans=max(ans,s);
}

void dfs(int x){
    if(x>n)cc();
    else{
        c[x]=0;
        dfs(x+1);
        c[x]=1;
        dfs(x+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(c,-1,sizeof c);
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}

