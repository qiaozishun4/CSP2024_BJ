#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005];
int minn=1e9,n;
int p[1000005];
void dfs(int st){
    if(p[st]==1){
        dfs(st+1);
        return ;
    }
    if(st>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(p[i]==0){
                cnt++;
            }
        }
        minn=min(cnt,minn);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(st!=i&&a[st]>a[i]&&p[i]==0){
            p[i]=1;
            dfs(st+1);
            p[i]=0;
        }
    }
    dfs(st+1);
    return ;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<minn;
    return 0;
}
