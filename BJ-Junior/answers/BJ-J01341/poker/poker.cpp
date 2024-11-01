#include <bits/stdc++.h>
using namespace std;
int N;
int P[6][20];
int main ()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>N;
    for(int i=1;i<N+1;i++)
    {
        char c1, c2;
        int d, d0;
        cin>>c1>>c2;
        if('1'<(int)c2 && (int)c2<'9'+1)
            d=(int)c2-'0';
        else if (c2=='T')
        {
            d=10;
        } else if (c2=='J')
        {
            d=11;
        } else if (c2=='Q')
        {
            d=12;
        } else if (c2=='K')
        {
            d=13;
        } else if (c2=='A')
        {
            d=1;
        }
        if (c1=='D')
        {
            d0=1;
        } else if (c1=='C')
        {
            d0=2;
        } else if (c1=='H')
        {
            d0=3;
        } else
        {
            d0=4;
        }
        P[d0][d]=1;
    }
    int sum=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(P[i][j]==0)
            {
                sum++;
            }
        }
    }
    printf("%d", sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
