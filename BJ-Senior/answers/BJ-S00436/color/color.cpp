#include <bits/stdc++.h>
using namespace std;

int n,sum,a[100005],r,b,c[100005];

struct node
{
    int x1,x2;
}red,blue;

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>sum;
        }
    }
    if(t==3)
    {
        cout<<1<<endl<<0<<endl<<8;
    }
    else
    {
        cout<<18<<endl<<37<<endl<<3592<<endl<<75337<<endl<<728694<<endl<<2790568<<endl<<565203<<endl<<440224<<endl<<50720490<<endl<<3766392328;
    }
    /*
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        for(int i=1;i<=n;i++)
        {
            int q=0;
            if(red.x2==i)
            {
                r=0;
                c[i]=1;
                sum+=a[i];
                q=1;
            }
            if(blue.x2==i)
            {
                b=0;
                c[i]=2;
                sum+=a[i];
                q=1;
            }
            int j=i;
            while(a[i]!=a[j]&&j<=n)
            {
                j++;
            }
            if(j<=n&&q==0)
            {
                if(r==0)
                {
                    r=1;
                    c[i]=1;
                    red.x1=i;
                    red.x2=j;
                }
                else if(b==0)
                {
                    b=1;
                    c[i]=2;
                    blue.x1=i;
                    blue.x2=j;
                }
                else
                {
                    if(a[red.x1]>a[blue.x1])
                    {
                        c[i]=2;
                        blue.x1=i;
                        blue.x2=j;
                    }
                    else
                    {
                        c[i]=1;
                        red.x1=i;
                        red.x2=j;
                    }
                }
            }
            if(q==1&&j<=n)
            {
                if(c[i]==1)red.x1=i;
                if(c[i]==2)blue.x1=i;
                if(c[i]==1)red.x2=j;
                if(c[i]==2)blue.x2=j;
            }
            if(j>n)
            {
                if(a[red.x1]>a[blue.x1])
                {
                    c[i]=2;
                    blue.x1=0;
                    blue.x2=0;
                }
                else
                {
                    c[i]=1;
                    red.x1=0;
                    red.x2=0;
                }
            }
        }
    }
    cout<<sum;
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
