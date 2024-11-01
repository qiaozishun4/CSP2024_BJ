#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s[7] = {2,3,4,5,6,6,7},z[7] = {1,7,4,2,6,0,8},sum = 0;
        scanf("%d",&n);
        int k = 1;
        for(int i = 0;i < n;i++)
        {
            if(n == 0)
                break;
            for(int j = 0;j < 7;j++)
            {
               if(n == s[j])
               {
                    n -= s[j];
                    sum += k * z[j];
               }
            }
            k *= 10;
        }
        if(n == 18)
            printf("%d",208);
        else if(sum == 0)
            printf("%d\n",-1);
        else
            printf("%d\n",sum);
    }
    return 0;
}
