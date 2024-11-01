/*
我在打入门组比赛吗？
不得不说，我觉得这题难度低于某教练不会的那道入门组 P4。
*/
#include<stdio.h>
int a[200001];
long long f[200001],g[1000001];
const long long inf=0x3f3f3f3f3f3f3f3fll;
long long max(long long x,long long y){return x>y?x:y;}
void work(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<=1000000;++i)g[i]=-inf;
    long long res=0,s=0;
    for(int i=1;i<=n;++i){
        f[i]=max(res,g[a[i]]+s+a[i]);
        if(i>1){
            if(a[i]==a[i-1])res+=a[i],s+=a[i];
            g[a[i-1]]=max(g[a[i-1]],f[i]-s);
        }
        res=f[i]>res?f[i]:res;
    }printf("%lld\n",res);
}
int main(){
    freopen("color.in","r",stdin),freopen("color.out","w",stdout);
    int t;
    for(scanf("%d",&t);t--;work());
    return 0;
}
/*
上个赛季此时此刻好像在这个位置进行了一个白的表，但是为什么现在喜欢的人都不同了呢？？？
*/