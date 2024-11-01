#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    unsigned long long t,n,i=0,j=0;
    cin>>t;
    for (i=0;i<t;i++)
    {
        cin>>n;
        if (n%7==0)
        {
            cout<<8;
        }
        else if (n%7==1)
        {
            if (n==1)
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<10;
            n--;
        }
        else if(n%7==2)
        {
            cout<<1;
            n+=7;
        }
        else if(n%7==3)
        {
            if (n==3)
            {
                cout<<7;
            }
            else
            {
                cout<<22;
            }
        }
        else if(n%7==4)
        {
            if (n==4)
            {
                cout<<4;
            }
            else
            {
                cout<<20;
            }
        }
        else if(n%7==5)
        {
            cout<<2;
        }
        else
        {
            cout<<6;
        }
        n/=7;
        for (j=1;j<n;j++)
        {
            cout<<8;
        }
        cout<<endl;
    }

	return 0;
}
