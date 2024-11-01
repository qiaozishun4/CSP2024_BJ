#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n; scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int k = 0,p = 0;
    for(int i = 2;i <= n;i++)
    {
        while(p < n && a[p+1] < a[i]) p++;
        if(k < p) k++;
    }
    printf("%d",n-k);
    return 0;
}
