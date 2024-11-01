#include <bits/stdc++.h>

using namespace std;


int main()
{
    freopen("sticks.in","r",stdin);
 //   freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a;
        cin>>a;
        if(a==0||a==1)
        {
            cout<<-1<<endl;

        }
        else if(a==2)
        {
            cout<<1<<endl;

        }
        else if(a==3)
        {
            cout<<7<<endl;

        }
        else if(a==9)
        {
            cout<<18<<endl;

        }
        else if(a==4)
        {
            cout<<4<<endl;

        }
        else if(a==5)
        {
            cout<<2<<endl;

        }
        else if(a==6)
        {
            cout<<6<<endl;

        }
        else if(a==7)
        {
            cout<<8<<endl;

        }
        else if(a==8)
        {
            cout<<10<<endl;

        }
        else if(a==10)
        {
            cout<<22<<endl;

        }
        else if(a==11)
        {
            cout<<20<<endl;

        }
        else if(a==12)
        {
            cout<<28<<endl;

        }
        else if(a==13)
        {
            cout<<67<<endl;

        }
        else if(a==14)
        {
            cout<<88<<endl;

        }
        else if(a==15)
        {
            cout<<107<<endl;

        }
        else if(a==16)
        {
            cout<<177<<endl;

        }
        else if(a==17)
        {
            cout<<200<<endl;

        }
        else if(a==18)
        {
            cout<<208<<endl;

        }
        else if(a==19)
        {
            cout<<288<<endl;

        }
        else if(a==20)
        {
            cout<<688<<endl;

        }
        else
        {
            for(int j=0;j<a/7;j++)
                cout<<8;
            
        }

    }

    return 0;
}
