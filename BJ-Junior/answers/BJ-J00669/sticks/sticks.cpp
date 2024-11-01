#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    int num;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>num;
        int x=num/7;
        if(num==1)
        {
            cout<<-1<<endl;
        }
        else
        {
            if(num<=14)
            {
                if(num==2)
                {
                    cout<<1<<endl;
                }
                else if(num==3)
                {
                    cout<<7<<endl;
                }
                else if(num==4)
                {
                    cout<<4<<endl;
                }
                else if(num==5)
                {
                    cout<<2<<endl;
                }
                else if(num==6)
                {
                    cout<<6<<endl;
                }
                else if(num==7)
                {
                    cout<<8<<endl;
                }
                else if(num==8)
                {
                    cout<<10<<endl;
                }
                else if(num==9)
                {
                    cout<<18<<endl;
                }
                else if(num==10)
                {
                    cout<<22<<endl;
                }
                else if(num==11)
                {
                    cout<<20<<endl;
                }
                else if(num==12)
                {
                    cout<<28<<endl;
                }
                else if(num==13)
                {
                    cout<<68<<endl;
                }
                else if(num==14)
                {
                    cout<<88<<endl;
                }
            }
            if(num>14)
            {
                num=(num%7)+7;
                if(num==7)
                {
                    for(int i=0;i<x;i++)
                    cout<<8;
                }
                else if(num!=7)
                {
                    if(num==8)
                    {
                        cout<<10;
                    }
                    else if(num==9)
                    {
                        cout<<18;
                    }
                    else if(num==10)
                    {
                        cout<<22;
                    }
                    else if(num==11)
                    {
                        cout<<20;
                    }
                    else if(num==12)
                    {
                        cout<<28;
                    }
                    else if(num==13)
                    {
                        cout<<68;
                    }
                    for(int i=0;i<x-1;i++)
                    {
                        cout<<8;
                    } 
                }
                cout<<endl;
            }
        }
    }
    return 0;
}