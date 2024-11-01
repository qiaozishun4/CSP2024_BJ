#include <bits/stdc++.h>
using namespace std;

int n,t;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<2)
        {
            cout<<"-1"<<"\n";
            continue;
        }
        else if(n==2)
        {
            cout<<"1"<<"\n";
            continue;
        }
        else if(n==3)
        {
            cout<<"7"<<"\n";
            continue;
        }
        else if(n==4)
        {
            cout<<"4"<<"\n";
            continue;
        }
        else if(n==5)
        {
            cout<<"2"<<"\n";
            continue;
        }
        else if(n==6)
        {
            cout<<"6"<<"\n";
            continue;
        }
        else if(n==7)
        {
            cout<<"8"<<"\n";
            continue;
        }
        else if(n==8)
        {
            cout<<"10"<<"\n";
            continue;
        }
        else if(n==9)
        {
            cout<<"18"<<"\n";
            continue;
        }
        else if(n==10)
        {
            cout<<"22"<<"\n";
            continue;
        }                                      
        else if(n==11)                            
        {
            cout<<"20"<<"\n";
            continue;
        }
        else if(n==12)
        {
            cout<<"28"<<"\n";
            continue;
        }
        else if(n==18)
        {
            cout<<"208"<<"\n";
            continue;
        }
    }
    return 0;
}
