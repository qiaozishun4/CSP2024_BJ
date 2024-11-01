#include<iostream>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("stocks.out","w",stdout);
    int n,i,a[1005][1005],j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%7==0)
        {
            for(i=1;i<=n/7;i++)
            {
                cout<<"8";
            }
        }
        else if(n%7==1)
        {
            cout<<"10";
            for(i=1;i<=(n/7)-1;i++)
            {
                cout<<"8";
            }
        }
        else{
            cout<<0;
        }

    }

}

