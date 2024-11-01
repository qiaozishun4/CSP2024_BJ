#include<bits/stdc++.h>
using namespace std;
int sign[]={0,0,1,7,4,2,0,8};
int sign2[]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n==1||n==0)
        {
            printf("-1\n");
        }
        else if(n<=7)
        {
            if(n==6)
            {
                printf("6\n");
            }
            else
            {
                printf("%d\n",sign[n]);
            }
        }
        else 
        {
            int tmp=n/7;
            tmp--;
            int tmp2=n%7+7;
            int flag=0;
            for(int i=1;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    if(sign2[i]+sign2[j]==tmp2)
                    {
                        printf("%d%d",i,j);
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    break;
                }
            }
            for(int i=1;i<=tmp;i++)
            {
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}