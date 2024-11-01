#include<bits/stdc++.h>
using namespace std;
int T;
int n,a,b,h;
int f1[10][10];

int f2[10][10];//steal ?;
int f3[10][10];
int f4[10][10];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    f1[1][0]=55;f1[2][0]=1;f1[3][0]=7;f1[4][0]=4;f1[5][0]=2;f1[6][0]=6;
    f1[7][0]=8;
    for(int i=1;i<=7;++i)
        for(int j=1;j<=7-i;++j)
        {
            f1[i][j]=f1[i][0];
            for(int k=1;k<=j;++k)
                if(f1[i+k][0]<f1[i][j])
                {
                    f2[i][j]=k;
                    f1[i][j]=f1[i+k][0];
                }

        }
    f3[1][0]=55;f3[2][0]=1;f3[3][0]=7;f3[4][0]=4;f3[5][0]=2;f3[6][0]=0;
    f3[7][0]=8;
    for(int j=1;j<=5;++j)
    {
        f3[7][j]=f3[7][0];
        for(int k=1;k<=j;++k)
        {
            if(f3[7-k][0]<f3[7][j])
            {
                f4[7][j]=k;
                f3[7][j]=f3[7-k][0];
            }

        }

    }/*
    for(int j=0;j<=5;++j)
            printf("f3=%d,f4=%d   ",f3[7][j],f4[7][j]);
        printf("\n");

    for(int i=1;i<=7;++i)
    {
        printf("i=%d  ",i);
        for(int j=0;j<=7-i;++j)
            printf("f1=%d,f2=%d   ",f1[i][j],f2[i][j]);
        printf("\n");
    }*/
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("-1\n");
            continue;

        }
        b=n/7;
        a=n%7;
        if(b==0)
        {
            printf("%d",f1[a][0]);
        }
        else
        {
            int l=min(b,7-a);

            printf("%d",f1[a][l]);
            h=f2[a][l];
            for(int i=1;i<b;++i)
            {
                printf("%d",f3[7][h]);
                h-=f4[7][h];
                //printf("%d\n",h);
            }
            printf("%d\n",f3[7-h][0]);
        }
    }
    return 0;
}
