#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,q,l[100005],s[10005][20005],r,c;
bool f;
void dfs(int x,int st,int la){
    if(f) return;
    if(x==r+1){
        if(st==c){
            f=1;
            printf("1\n");
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==la) continue;
        for(int j=1;j<l[i];j++){
            if(s[i][j]==st){
                for(int m=j+1;m<j+k;m++){
                    if(m>l[i]) break;
                    dfs(x+1,s[i][m],i);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i];j++) scanf("%d",&s[i][j]);
        }
        for(int i=1;i<=q;i++){
            f=0;
            scanf("%d%d",&r,&c);
            dfs(1,1,0);
            if(!f) printf("0\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
