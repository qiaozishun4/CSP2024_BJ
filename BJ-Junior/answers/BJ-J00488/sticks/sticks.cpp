#include<iostream>
using namespace std;
int t,n;
int a[15]={6,2,5,5,4,5,6,3,7,6};
int b[25]={-1,-1,0,0,0,0,0,0,10,24,23,20,60,80,88,108,188,788,208,800,808,888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0||n==1||(n>=8&&n<=21))
        {
            cout<<b[n]<<endl;
            continue;
        }
        if(n%7==0)
        {
            int m=n/7;
            for(j=1;j<=m;j++)
                cout<<8;
            cout<<endl;
            continue;
        }
        if(n%7==1)
        {
            int m=n/7;
            cout<<10;
            for(i=1;i<m;i++)
                cout<<8;
            cout<<endl;
            continue;
        }
        int f=0;
        for(i=1;i<=9;i++)
        {
            if(a[i]==n)
            {
                cout<<i<<endl;
                f=1;
                break;
            }
        }
        if(f==1)
            continue;
        int mark=0;
        for(i=2;i<=n/2;i++)
        {
            int p=n,flag=1;
            for(j=i;j>=1;j--)
            {
                if(j!=1)
                    p=p-6;
                else
                {
                    if(p>7)
                    {
                        flag=0;
                        break;
                    }
                    if(p<0)
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==0)
                continue;
            else if(mark==0)
            {
                cout<<p;
                for(j=1;i<i;j++)
                    cout<<0;
                cout<<endl;
                mark=1;
            }
        }
    }
    return 0;
}
