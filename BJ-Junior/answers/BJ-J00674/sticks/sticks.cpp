#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
                cout<<'8';
                cout<<endl;
        }
        if(n%7==1)
        {
            cout<<"16";
            n-=8;
            for(int i=1;i<=n/7;i++)
                cout<<"8";
                cout<<endl;

        }
    }
    return 0;
}
