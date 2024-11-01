#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m[]={6,2,5,5,4,5,6,3,7,6},a[15],val,minn=1e9;
bool f;
void dfs(int x,int sum){
    if(sum>n) return;
    if(sum==n){
        f=1;
        for(int i=1;i<x;i++) val=val*10+a[i];
        if(val<minn) minn=val;
        val=0;
        return;
    }
    for(int i=0;i<=9;i++){
        if(x==1 && i==0) continue;
        a[x]=i;
        dfs(x+1,sum+m[i]);
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        f=0;
        minn=1e9;
        val=0;
        scanf("%d",&n);
        if(n<2){
            printf("-1\n");
            continue;
        }
        dfs(1,0);
        if(f) printf("%d\n",minn);
        else printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
