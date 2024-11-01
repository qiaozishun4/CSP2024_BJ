#include <bits/stdc++.h>
using namespace std;
bool a[1000][10][2005];
int b[1000][2005];
int main()
{
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=1000;i++)
            for(int j=1;j<=10;j++)
                for(int k=1;k<=2000;k++)
                    a[i][j][k]=0;
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            int l;
            scanf("%d",&l);
            b[i][0]=l;
            for(int j=1;j<=l;j++)
                scanf("%d",&a[i][j]);
        }
        a[0][0][1]=0;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int o=1;o<=b[j][0];o++)
                {
                    for(int p=1;p<k;p++)
                    {
                        for(int q=0;q<=n;q++)
                        {
                            if(a[q][i-1][b[j][o]]&&o+p<=b[j][0])
                            {
                                a[j][i][b[j][o+p]]=1;
                            }
                        }

                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("\n");
            for(int j=1;j<=10;j++)
            {
                printf("\n");
                for(int k=1;k<=25;k++)
                {
                    printf("a[%d][%d][%d]=%d  ",i,j,k,a[i][j][k]);
                }
            }
        }
        for(int i=1;i<=q;i++)
        {
            int r,c;
            scanf("%d%d",&r,&c);
            for(int j=1;j<=n;j++)
            {
                if(a[j][r][c]=1)
                {
                    printf("a[%d][%d][%d]=%d\n",j,r,c,a[j][r][c]);
                    printf("%d\n",1);
                    break;
                }
                else if(j==n)printf("%d\n",0);
            }
        }
    }
}
//写不完一点