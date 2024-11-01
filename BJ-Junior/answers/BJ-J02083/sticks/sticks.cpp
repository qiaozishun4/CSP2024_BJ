#include <iostream>
using namespace std;
int t,n,a[17]={6,2,5,5,4,5,6,3,7,6};
int ans;
int pin(int x)
{
    int res=0;
    while(x>0)
    {
        res+=a[x%10];
        x/=10;
    }
    return res;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=-1;
        if(n<2)
        {
            printf("%d\n",ans);
            continue;
        }
        for(int i=1;i<=9e6+10;i++)
        {
            if(pin(i)==n)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
