#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct A
{
    int sz;
    int a[10];
};
bool operator <(A x,A y)
{
    if(x.sz!=y.sz)return x.sz<y.sz;
    int px=1,py=1;
    int sumx=0,sumy=0;
    while(px<=9&&!x.a[px])px++;
    while(py<=9&&!y.a[py])py++;
    if(px!=py)return px<py;
    x.a[px]--;
    y.a[py]--;
    for(int i=0;i<=9;i++)
    {
        sumx+=x.a[px];
        sumy+=y.a[py];
        if(sumx!=sumy)return sumx<sumy;
    }
    return 0;
}
A f[100010];
void print(int x)
{
    if(f[x].sz>100000)
    {
        printf("-1\n");
        return;
    }
    int p=1;
    while(p<=9&&!f[x].a[p])p++;
    f[x].a[p]--;
    printf("%d",p);
    for(int i=0;i<=9;i++)
    {
        for(int j=1;j<=f[x].a[i];j++)printf("%d",i);
    }
    printf("\n");
}

int num[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=100000;i++)
    {
        f[i].sz=1e9;
        for(int j=0;j<=9;j++)f[i].a[j]=0;
    }
    for(int i=1;i<=100000;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(i-num[j]<0)continue;
            A nx=f[i-num[j]];
            nx.sz++;
            nx.a[j]++;
            if(nx<f[i])f[i]=nx;
        }
    }
    while(T--)
    {
        int n;
        cin>>n;
        print(n);
    }
}
