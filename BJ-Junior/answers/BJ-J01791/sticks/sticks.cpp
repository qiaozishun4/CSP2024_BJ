#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int T,q[15],dpx[maxn][13],dp[maxn];
bool xcompare(int i,int ij,int j)
{
    bool ff=0,fal=1;
    for(int x=1;x<=9;++x)
    {
        if(ff&&fal)
        {
            if(dpx[i][0]<dpx[ij][0]+(bool)(0==q[j]))
                return 1;
            if(dpx[i][0]>dpx[ij][0]+(bool)(0==q[j]))
                return 0;
            fal=0;
        }
        if(dpx[i][x]<dpx[ij][x]+(bool)(x==q[j]))
            return 1;
        if(dpx[i][x]>dpx[ij][x]+(bool)(x==q[j]))
            return 0;
        if(fal && dpx[i][x]>0)
            ff=1;
    }
    return 0;
}
void xprint(int n)
{
    bool ff=0,fal=1;
    for(int x=1;x<=9;++x)
    {
        if(ff&&fal)
        {
            for(int i=1;i<=dpx[n][0];++i)
                printf("%d",0);
            fal=0;
        }
        if(fal && dpx[n][x]>0)
            ff=1;
        for(int i=1;i<=dpx[n][x];++i)
            printf("%d",x);
        //printf(".");
    }
    printf("\n");
    return;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    q[2]=1;
    q[3]=7;
    q[4]=4;
    q[5]=2;
    q[6]=6;
    q[7]=8;
    scanf("%d",&T);
    dp[0]=0;
    for(int i=1;i<maxn;++i)
        dp[i]=999999;
    //printf("dp1=%d\n",dp[1]);
    for(int i=1;i<maxn;++i)
    {

        for(int j=2;j<=7;++j)
            if(i>=j)
            {
                if(dp[i-j]==999999)
                    continue;
                if(dp[i-j]+1<dp[i])
                {
                    //printf("i=%d,j=%d deef>\n",i,j);
                    dp[i]=dp[i-j]+1;
                    for(int m=0;m<=9;++m)
                        dpx[i][m]=dpx[i-j][m];
                    ++dpx[i][q[j]];
                    continue;
                }
                if(dp[i-j]+1==dp[i])
                    if(xcompare(i,i-j,j))
                    {
                        //printf("i=%d,j=%d num>\n",i,j);
                        dp[i]=dp[i-j]+1;
                        for(int m=0;m<=9;++m)
                            dpx[i][m]=dpx[i-j][m];
                        ++dpx[i][q[j]];
                        continue;
                    }
            }
        //printf("i=%d dpi=%lld\n",i,dp[i]);
        //dp[1]=999999;
        if(i==6)
            q[6]=0;
    }
    //printf("dp1=%d\n",dp[1]);
    //printf("dp2=%d\n",dp[2]);
    //printf("dp3=%d\n",dp[3]);
    //printf("dp4=%d\n",dp[4]);
    //printf("dp5=%d\n",dp[5]);
    //printf("dp6=%d\n",dp[6]);
    for(int o=0;o<T;++o)
    {
        int n;
        scanf("%d",&n);
        if(dp[n]==999999)
            printf("%d\n",-1);
        else
            xprint(n);
    }
    return 0;
}
