#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,a[200010];
int f[2010][2][2010];
int f2[2][2][20010];
int f3[200010][2][15];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        if(n<=2000)
        {
            memset(f,0,sizeof(f));
            for(int i=2;i<=n;i++)
            {
                //i-1 red
                for(int j=0;j<i-1;j++)
                    f[i][0][j]=max(f[i][0][j],f[i-1][0][j]+(a[i]==a[i-1]?a[i]:0));
                for(int j=0;j<i-1;j++)
                    f[i][1][i-1]=max(f[i][1][i-1],f[i-1][0][j]+(a[i]==a[j]?a[i]:0));
                //i-1 blue
                for(int j=0;j<i-1;j++)
                    f[i][1][j]=max(f[i][1][j],f[i-1][1][j]+(a[i]==a[i-1]?a[i]:0));
                for(int j=0;j<i-1;j++)
                    f[i][0][i-1]=max(f[i][0][i-1],f[i-1][1][j]+(a[i]==a[j]?a[i]:0));
            }
            int ans=0;
            for(int i=0;i<=n-1;i++)
                ans=max(ans,max(f[n][0][i],f[n][1][i]));
            printf("%d\n",ans);
        }
        else
        {
            bool flag=1;
            for(int i=1;i<=n;i++)
                if(a[i]>10)flag=0;
            if(flag)
            {
                memset(f3,-999999,sizeof(f3));
                f3[1][0][0]=f3[1][1][0]=0;
                for(int i=2;i<=n;i++)
                {
                    //i-1 red
                    for(int j=0;j<=10;j++)
                        f3[i][0][j]=max(f3[i][0][j],f3[i-1][0][j]+(a[i]==a[i-1]?a[i]:0));
                    for(int j=0;j<=10;j++)
                        f3[i][1][a[i-1]]=max(f3[i][1][a[i-1]],f3[i-1][0][j]+(a[i]==j?a[i]:0));
                    //i-1 blue
                    for(int j=0;j<=10;j++)
                        f3[i][1][j]=max(f3[i][1][j],f3[i-1][1][j]+(a[i]==a[i-1]?a[i]:0));
                    for(int j=0;j<=10;j++)
                        f3[i][0][a[i-1]]=max(f3[i][0][a[i-1]],f3[i-1][1][j]+(a[i]==j?a[i]:0));
                }
                int ans=0;
                for(int i=1;i<=10;i++)ans=max(ans,max(f3[n][0][i],f3[n][1][i]));
                printf("%d\n",ans);
            }
            else if(n<=20000)
            {
                memset(f2,0,sizeof(f2));
                for(int i=2;i<=n;i++)
                {
                    //i-1 red
                    for(int j=0;j<i-1;j++)
                        f2[i%2][0][j]=max(f2[i%2][0][j],f2[(i-1)%2][0][j]+(a[i]==a[i-1]?a[i]:0));
                    for(int j=0;j<i-1;j++)
                        f2[i%2][1][i-1]=max(f2[i%2][1][i-1],f2[(i-1)%2][0][j]+(a[i]==a[j]?a[i]:0));
                    //i-1 blue
                    for(int j=0;j<i-1;j++)
                        f2[i%2][1][j]=max(f2[i%2][1][j],f2[(i-1)%2][1][j]+(a[i]==a[i-1]?a[i]:0));
                    for(int j=0;j<i-1;j++)
                        f2[i%2][0][i-1]=max(f2[i%2][0][i-1],f2[(i-1)%2][1][j]+(a[i]==a[j]?a[i]:0));
                }
                int ans=0;
                for(int i=0;i<=n-1;i++)
                    ans=max(ans,max(f2[n%2][0][i],f2[n%2][1][i]));
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}