#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N];
bool f[N];
long long int n, ans, s;
int T;
void dfs(int x, long long int num){
    if(x==n+1){
        ans=max(ans,num);
        return;
    }
    f[x]=0;
    for(int i=x-1;i>=1;i--)if(f[i]==f[x]){if(a[i]==a[x]){num+=a[i];}break;}
    dfs(x+1,num);
    f[x]=1;
    for(int i=x-1;i>=1;i--)if(f[i]==f[x]){if(a[i]==a[x]){num+=a[i];}break;}
    dfs(x+1,num);
}
int main(){
    cin>>T;
    while(T){
        memset(a,0,sizeof(a));
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,0);
        cout<<ans<<"\n";
        T--;
    }
    return 0;
}
