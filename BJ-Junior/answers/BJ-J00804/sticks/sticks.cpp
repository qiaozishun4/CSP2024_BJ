#include <bits/stdc++.h>
using namespace std;
int k[11]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        a=b=n;
        while(n)
        {
            a%=7;
            if(a==0)
            {
                a=7;
            }
            if(n>7)
            {
                if(n==b)
                {
                    for(int j=1;j<=9;j++)
                    {
                        if(k[j]>=a)
                        {
                            cout<<j;
                            n-=k[j];
                            a=n;
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=0;j<=9;j++)
                    {
                        if(k[j]>=a)
                        {
                            cout<<j;
                            n-=k[j];
                            a=n;
                            break;
                        }
                    }
                }
            }
            else
            {
                if(n==b)
                {
                    for(int j=1;j<=9;j++)
                    {
                        if(k[j]==n)
                        {
                            cout<<j<<endl;
                            n=0;
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=0;j<=9;j++)
                    {
                        if(k[j]==n)
                        {
                            cout<<j<<endl;
                            n=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
