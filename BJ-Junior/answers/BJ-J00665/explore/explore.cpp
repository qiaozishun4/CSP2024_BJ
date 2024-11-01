#include <bits/stdc++.h>
using namespace std;
long long T,sum,a[1005][1005],d[1005][1005];
char v;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        long long m,n,k,q1,q2,b;
        cin >> n >> m >> k >> q1 >> q2 >> b;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> v;
                if(v=='x')
                {
                    a[i][j]=2;
                }
                else
                {
                    a[i][j]=1;
                }
            }
            d[q1][q2]=1;
        }
        for(int i=1;i<=k;i++)
        {
            if(b==0)
            {
                if(a[q1][q2+1]!=2&&a[q1][q2+1]!=0)
                {

                    d[q1][q2+1]=1;
                    q2+=1;
                }
                else
                {
                    b=(b+1)%4;
                }
            }
            else if(b==1)
            {
                if(a[q1+1][q2]!=2&&a[q1+1][q2]!=0)
                {
                    d[q1+1][q2]=1;
                    q1+=1;
                }
                else
                {
                    b=(b+1)%4;
                }
            }
            else if(b==2)
            {
                if(a[q1][q2-1]!=2 &&a[q1][q2-1]!=0)
                {
                    d[q1][q2-1]=1;
                    q2-=1;
                }
                else
                {
                    b=(b+1)%4;
                }
            }
            else
            {
                if(a[q1-1][q2]!=2 &&a[q1-1][q2]!=0)
                {
                    d[q1-1][q2]=1;
                    q1-=1;
                }
                else
                {
                    b=(b+1)%4;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(d[i][j]==1)
                {
                    sum++;
                }
                d[i][j]=0;

            }
        }
        cout << sum << endl;
        sum=0;
    }
}