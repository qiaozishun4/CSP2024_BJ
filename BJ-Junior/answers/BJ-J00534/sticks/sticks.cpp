#include <bits/stdc++.h>
using namespace std;
int n,st[10]={6,2,5,5,4,5,6,3,7,6},w,fl=0;
int ans[10];
void dfs(int a){
    if(a==w){
        if(n==0 && ans[0]!=0){
            for(int i=0;i<w;i++) printf("%d",ans[i]);
            fl=1;
            return;
        }
    }
    for(int i=0;i<10;i++){
        if(a==0 && i==0) continue;
        if(n<i) continue;
        n-=i;
        ans[a]=i;
        dfs(a+1);
        n+=i;
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf(" %d ",&T);
    while(T--){
        scanf(" %d ",&n);
        if(n%7==0){
            for(int i=0;i<n/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        w=n/7+1;
        dfs(0);
        if(n==0) printf("-1");
        printf("\n");
    }
    return 0;
}
