#include<bits/stdc++.h>
using namespace std;

int n,m,K;
int A[100002];
int c[100002];
int d[1002][1002];
int a[1000002];

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",A[i]);
    for(int i=1;i<=m;++i) scanf("%d",c[i]);
    for(int i=1;(1<<(i-1))<=n;++i) K=i;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=(1<<(K-i));++j){
            scanf("%d",d[i][j]);
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x[4];
        for(int i=0;i<4;i++) scanf("%d",&x[i]);
        for(int i=1;i<=n;i++){
            a[i]=A[i]^x[i%4];
        }
        for(int i=1;i<=m;i++){
            printf("%d",a[i%n]);
        }
    }
    return 0;
}
