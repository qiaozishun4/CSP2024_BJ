#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int a[N];
bool f;
int n,t;
long long c;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long i;
    for(i=1;i<=10000000;i++)
    {
        int t=i;
        while(t!=0)
        {
            int c=t%10;
            t=t/10;
            if(c==0 || c==6 || c==9)
            {
                a[i]+=6;
            }
            else if(c==1)
            {
                a[i]+=2;
            }
            else if(c==2 || c==5 || c==3)
            {
                a[i]+=5;
            }
            else if(c==4)
            {
                a[i]+=4;
            }
            else if(c==7)
            {
                a[i]+=3;
            }
            else if(c==8)
            {
                a[i]+=7;
            }
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        f=false;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0)
        {
            c=0;
            for(i=1;i<=n/7;i++)
            {
                c=c*10+8;
            }
            cout<<c;
            continue;
        }
        for(i=1;i<=10000000;i++)
        {
            if(n==a[i])
            {
                cout<<i<<endl;
                f=true;
                break;
            }
        }
        if(f==false)
        {
            cout<<-1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
