#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int a[100]={0,0,1,7,4,5,6,8,10,18,22,20,28,68,88,108,188,218,208,288};
        int n;
        cin>>n;
        if(n%7==0)
        {
            while(n)
            {

                cout<<8;
                n-=7;
            }
            cout<<endl;
        }
        else if(n%7==1)
        {

            if(n==1)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<10;
                while(n>8)
                {

                    cout<<8;
                }
                cout<<endl;
            }
        }
        else cout<<a[n];
    }
    return 0;
}