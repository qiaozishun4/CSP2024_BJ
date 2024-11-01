#include<iostream>
using namespace std;
int a[100005];
int c[100005],len,d[100005];
int b[15]={-1,-1,1,7,4,2,0,8}
bool flag=true;
void f(int n,int l)
{
    if((l==0&&n!=0)||n==1)
    {
        return;
    }
    if(n==0)
    {
        for(int i=len;i>=1;i--)
        {
            if(d[i]<a[i])
            {
                for(int j=1;j<=len;j++)
                {
                    a[j]]=d[j];
                }
            }
        }
    }
    for(int i=1;i<=c[l]-2;i++)
    {
        if(flag==true||n-i==6)
        {
            d[l]=6;
        }
        else
        {
            d[l]=b[n-i];
        }
        f(i,l-1);

    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,cnt=0;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(n>7)
        {
            cnt++;
            n-=7;
            a[cnt]=b[7];
            c[cnt]=7;
        }
        if(n==0)
        {
            for(int j=cnt;j>=1;j--)
            {
                cout<<a[j];
            }
            cout<<endl;
            continue;
        }
        else if(n==1)
        {
            a[cnt]=0;
            a[cnt+1]=1;
            for(j=cnt+1;j>=1;j--)
            {
                cout<<a[j];
            }
            cout<<endl;
            continue;
        }
        else
        {
            c[cnt+1]=n;
            len=cnt+1;
            f(n,cnt+1);
            for(int j=cnt+1;j>=1;j--)
            {
                cout<<a[j];
            }
        }
        flag=true;
    }
    return 0;
}