#include<bits/stdc++.h>
using namespace std;
int h[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        int s=0;
        cin>>n;
        if(n%7==0)
        {
            int k=n/7;
            for(int i=1;i<=k;i++)
            {
                cout<<8;
            }
            cout<<'\n';
        }
        else if(n%7==1)
        {
            cout<<10;
            n-=8;
            int k=n/7;
            for(int i=1;i<=k;i++)
            {
                cout<<8;
            }
            cout<<'\n';
        }
        else
        {
            cout<<-1;
            cout<<'\n';
        }
    }
    return 0;
}
