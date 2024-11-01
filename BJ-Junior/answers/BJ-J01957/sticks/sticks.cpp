#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,a,b;
    cin>>n;
    int m[n],x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x<2)
        {
            m[i]=-1;
            continue;
        }
        b=x%7;
        a=x/7;
        if(a==0)
        {

            if(b==2)
            {
                m[i]=1;
                continue;
            }
            if(b==3)
            {
                m[i]=7;
                continue;
            }
            if(b==4)
            {
                m[i]=4;
                continue;
            }
            if(b==5)
            {
                m[i]=2;
                continue;
            }
            if(b==6)
            {
                m[i]=6;
                continue;
            }
            if(b==7)
            {
                m[i]=8;
                continue;
            }
        }
        if(b==1)
        {
            m[i]=10;
            for(int j=1;j<a;j++)
            {
                m[i]*=10;
                m[i]+=8;
            }
            continue;
        }
        if(b==2)
        {
            m[i]=1;
            for(int j=1;j<=a;j++)
            {
                m[i]*=10;
                m[i]+=8;
            }
            continue;
        }
        if(b==3)
        {
            if(a>1)
            {
                m[i]=200;
                for(int j=1;j<a-1;j++)
                {
                    m[i]*=10;
                    m[i]+=8;
                }
            }
            else{
                m[i]=22;
            }
            continue;
        }
        if(b==4)
        {
            m[i]=20;
            for(int j=1;j<a;j++)
            {
                m[i]*=10;
                m[i]+=8;
            }
            continue;
        }
        if(b==5)
        {
            m[i]=2;
            for(int j=1;j<=a;j++)
            {
                m[i]*=10;
                m[i]+=8;
            }
            continue;
        }
        if(b==6)
        {
            m[i]=6;
            for(int j=1;j<=a;j++)
            {
                m[i]*=10;
                m[i]+=8;
            }
            continue;
        }
        else
        {
            m[i]=8;
            for(int j=1;j<=a;j++)
            {
                m[i]*=10;
                m[i]+=8;
            }
            continue;
        }
    }
    for(int i=1;i<=n;i++) cout<<m[i]<<endl;
    return 0;
}

