#include <bits/stdc++.h>

using namespace std;

int a[3000];
int color[3000];

int n;

int ans=0;
int c[3000];
int check(){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        int lc=-1;
        for(int j=i-1;j>=1;j--){
            if(color[j]==color[i]){
                lc=j;
            }
        }
        if(lc!=-1){
            if(a[i]==a[lc]){
                c[i]=a[lc];
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=c[i];
    }
    ans=max(ans,sum);
}

void dfs(int x){
    if(x==n+1){
        check();
        return;
    }
    color[x]=0;
    dfs(x+1);
    color[x]=1;
    dfs(x+1);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
