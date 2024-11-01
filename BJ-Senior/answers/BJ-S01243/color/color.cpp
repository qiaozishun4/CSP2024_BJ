#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, a[105];
int vis[105], ans;

int calc(){
    int rd=-1, bu=-1;
    int sum=0;
    for(int i=1;i<=n;i++)
        if(vis[i]){
            if(bu!=-1&&a[i]==a[bu])
                sum+=a[i];
            bu=i;
        }else{
            if(rd!=-1&&a[i]==a[rd])
                sum+=a[i];
            rd=i;
        }
    return sum;
}

void dfs(int stp){
    if(stp>n){
        ans=max(ans, calc());
        return;
    }
    vis[stp]=1; dfs(stp+1);
    vis[stp]=0; dfs(stp+1);
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        ans=0; dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
