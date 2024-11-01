#include<iostream>
using namespace std;
int T,l,n,c[10]={6,2,5,5,4,5,6,3,7,6};
void dp(int n,int d)
{
    if(d<=0 or n==0) return ;
    if(d==l)
    {
        for(int i=1;i<=9;i++)
        {
            if(n-c[i]<=(d-1)*7 and n-c[i]>=0)
            {
                cout<<i;
                dp(n-c[i],d-1);
                return ;
            }
        }
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            if(n-c[i]<=(d-1)*7 and n-c[i]>=0)
            {
                cout<<i;
                dp(n-c[i],d-1);
                return ;
            }
        }
    }
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<2)
        {
            cout<<-1<<endl;
            continue;
        }
        l=n/7;
        if(l*7!=n) l++;
        dp(n,l);
        cout<<endl;
    }
    return 0;
}
