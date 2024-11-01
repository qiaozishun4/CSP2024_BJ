#include<bits/stdc++.h>
using namespace std;
int T;
int d[]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
        }
        else if(n%7==0)
        {
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
        }
        else if(n%7==1)
        {
            int cnt=n/7-1;
            cout<<10;
            for(int i=1;i<=cnt;i++) cout<<8;
            cout<<endl;
        }
        else
        {
            for(int i=1;;i++)
            {
                int cnt=0;
                int t=i;
                do
                {
                    cnt+=d[t%10];
                    t/=10;
                }while(t);
                if(cnt==n)
                {
                    cout<<i<<endl;
                    break;
                }

            }
        }
    }
    return 0;
}
