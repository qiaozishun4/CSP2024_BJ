#include<bits/stdc++.h>
using namespace std;
int p[20]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n<=14)
            printf("%d\n",p[n]);
        else
        {
            k=n%7+7;
            if(k==7)
                k+=7;
            printf("%d",p[k]);
            k=n/7-1;
            while(k--)
            {
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
