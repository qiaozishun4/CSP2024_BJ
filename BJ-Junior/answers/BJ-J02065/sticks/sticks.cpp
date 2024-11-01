#include<bits/stdc++.h>

using namespace std;

int t,n;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        if(n%7==0)
        {
            for(int j=1;j<=n/7;j++)
            {
                printf("8");
            }
            cout<<endl;
            continue;
        }
        else if(n==1)
        {
            printf("-1\n");
        }
        else if(n%7==1)
        {
            printf("10");
            for(int j=1;j<=n/7-1;j++)
            {
                printf("8");
            }
            cout<<endl;
        }
    }
    return 0;
}
