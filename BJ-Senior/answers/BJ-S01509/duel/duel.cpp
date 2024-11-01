#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];


int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int sum=0,last=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            //printf("%d\n",sum);
            last=max(last,sum),sum=0;
        }
        sum++;
        //printf("%d\n",sum);
    }
    last=max(last,sum);
    printf("%d",last);
    return 0;
}
