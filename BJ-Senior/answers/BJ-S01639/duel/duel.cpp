//n=1 时什么情况？？？
//读错了两遍题，兄弟你无敌了
#include<stdio.h>
#include<algorithm>
int r[100001];
int main(){
    freopen("duel.in","r",stdin),freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",r+i);
    if(n==1)putchar('1');
    else{
        std::sort(r+1,r+n+1);
        int j=1;
        for(int i=2;i<=n;++i)if(r[j]<r[i])++j;
        printf("%d",n-j+1);
    }
    return 0;
}