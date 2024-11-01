#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int r;
    cin>>r;
    for(int i=0;i<r;i++)
    {
        int n,m,k;
        int x0,y0,d;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d;
        char a[n+2][m+2]={};
        for(int j=1;j<n+1;j++)
        {
            for(int f=1;f<m+1;f++)
            {
                cin>>a[j][f];
            }
        }
        int ans=1;
        for(int g=0;g<k;)
        {
            if(d==0)
            {
                if(a[x0][y0+1]=='.')
                {
                    ans++;
                    a[x0][y0]=a[x0][y0+1];
                    g++;
                }
                else
                {
                    d=(d+1)%4;
                    g++;

                }
            }
            else if(d==1)
            {
                if(a[x0+1][y0]=='.')
                {
                    ans++;
                    a[x0][y0]=a[x0+1][y0];
                    g++;
                }
                else
                {
                    d=(d+1)%4;
                    g++;

                }
            }
            else if(d==2)
            {
                if(a[x0][y0-1]=='.')
                {
                    ans++;
                    a[x0][y0]=a[x0][y0-1];

                    g++;
                }
                else
                {
                    d=(d+1)%4;
                    g++;

                }
            }
            else if(d==3)
            {
                if(a[x0-1][y0]=='.')
                {
                    ans++;
                    a[x0][y0]=a[x0-1][y0];

                    g++;
                }
                else
                {
                    d=(d+1)%4;
                    g++;

                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}
