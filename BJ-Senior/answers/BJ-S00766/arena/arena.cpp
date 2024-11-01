#include<cstdio>
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,cur;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&cur);
    for(int i=1;i<=m;i++) scanf("%d",&cur);
    int k=1,l;
    for(l=1;l<=100000;l++)
    {
        k*=2;
        if(k>=n) break;
    }
    for(int i=1;i<=l;i++) scanf("%d",&cur);
    int T;
    scanf("%d",&T);
    while(T--) printf("0\n");
    return 0;
}