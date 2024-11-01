#include<bits/stdc++.h>
using namespace std;
int t,n,k,x,y,q,a[10001][20001],sum;
void dfs(int x,int last,int la){
    if(sum==1)return;
    if(x==0&&last==y){
        sum=1;
        return;
    }
    if(x==0)return;
    for(int i=1;i<=n;i++){
        if(i==la)continue;
        for(int j=1;j<=a[i][0];j++){
            if(a[i][j]==last){
                for(int jj=j+1;jj<=j+k-1;jj++)dfs(x-1,a[i][jj],i);
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i][0]);
            for(int j=1;j<=a[i][0];j++)scanf("%d",&a[i][j]);
        }
        while(q--){
            scanf("%d %d",&x,&y);
            sum=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=a[i][0];j++){
                    if(a[i][j]==1){
                        for(int jj=j+1;jj<=j+k-1;jj++){
                            dfs(x-1,a[i][jj],i);
                        }
                    }
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
